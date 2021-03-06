/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytoplane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 14:45:18 by user42            #+#    #+#             */
/*   Updated: 2021/03/27 17:27:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

double	plane_intersec_equation(t_ray *ray, t_plane *plane)
{
	t_vector	dist;
	double		a;
	double		t;

	a = vec_dot(ray->dir, plane->ori);
	if (fabs(a) < 0.00000001)
		return (INFINITY);
	dist = vec_diff(plane->cord, ray->origin);
	t = vec_dot(dist, plane->ori) / a;
	if (t < 0)
		return (INFINITY);
	return (t);
}

void	plane_intersec_color(t_plane *plane, t_ray *ray, t_scene scene)
{
	t_vector		normal;
	double			t_;

	t_ = plane_intersec_equation(ray, plane);
	if (t_ > ray->dir.z && t_ < INFINITY && t_ < ray->ray_t)
	{
		ray->ray_t = t_;
		ray->obj = plane;
		ray->ray_color = plane->color;
		ray->ray_n_t = ray_equation(ray, ray->ray_t);
		normal = plane->ori;
		if (vec_dot(ray->dir, normal) > 0)
			normal = vec_multipli_coeff(normal, -1);
		ray->ray_color = color_multipli(color_range1(ray->ray_color),
		compute_light(*ray, normal, scene, ray->obj));
	}
}

void	raytoplane(t_ray *ray, t_scene scene)
{
	t_list			*plane_list;
	t_plane			*plane;

	plane_list = scene.plane;
	while (plane_list->next)
	{
		plane = plane_list->content;
		plane_intersec_color(plane, ray, scene);
		plane_list = plane_list->next;
	}
}
