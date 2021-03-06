/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytosquare.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 21:58:49 by user42            #+#    #+#             */
/*   Updated: 2021/03/28 13:30:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

double	square_intersec_equation(t_ray *ray, t_square *square)
{
	t_plane		plane;
	t_vector	ray_pos;
	t_vector	dist;
	double		size;
	double		t;

	plane.ori = square->ori;
	plane.cord = square->cord;
	t = plane_intersec_equation(ray, &plane);
	ray_pos = ray_equation(ray, t);
	dist = vec_diff(plane.cord, ray_pos);
	size = square->height / 2;
	if (fabs(dist.x) <= size && fabs(dist.x) >= -size)
		if (fabs(dist.y) <= size && fabs(dist.y) >= -size)
			if (fabs(dist.z) <= size && fabs(dist.z) >= -size)
				return (t);
	return (INFINITY);
}

void	square_intersec_color(t_square *square, t_ray *ray, t_scene scene)
{
	t_vector		normal;
	double			t_;

	t_ = square_intersec_equation(ray, square);
	if (t_ > ray->dir.z && t_ < INFINITY && t_ < ray->ray_t)
	{
		ray->ray_t = t_;
		ray->obj = square;
		ray->ray_color = square->color;
		ray->ray_n_t = ray_equation(ray, ray->ray_t);
		normal = square->ori;
		if (vec_dot(ray->dir, normal) > 0)
			normal = vec_multipli_coeff(normal, -1);
		ray->ray_color = color_multipli(color_range1(ray->ray_color),
		compute_light(*ray, normal, scene, ray->obj));
	}
}

void	raytosquare(t_ray *ray, t_scene scene)
{
	t_list			*square_list;
	t_square		*square;

	square_list = scene.square;
	while (square_list->next)
	{
		square = square_list->content;
		square_intersec_color(square, ray, scene);
		square_list = square_list->next;
	}
}
