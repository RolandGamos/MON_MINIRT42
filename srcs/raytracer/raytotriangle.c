/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytotriangle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 21:46:13 by user42            #+#    #+#             */
/*   Updated: 2021/03/02 16:28:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"


double	triangle_intersec_equation(t_ray *ray, t_triangle *triangle, t_vector *normal)
{
	t_vector	v1;
	t_vector	v2;
	t_vector	cross;
	v1 = vec_diff(triangle->cord2, triangle->cord1);
	v2 = vec_diff(triangle->cord3, triangle->cord1);
	cross.x = ray->dir.x * v2.z - ray->dir.z * v2.y;
	cross.y = ray->dir.y * v2.x - ray->dir.x * v2.z;
	cross.z = ray->dir.x * v2.y - ray->dir.y * v2.x;
	double a = vec_dot(cross, v1);
	if (a > -0.00000001 && a < 0.00000001)
		return (INFINITY);
	double f = 1.0 / a;
	t_vector s = vec_diff(ray->origin, triangle->cord1);
	double u = f * vec_dot(s, cross);
	if (u < 0.0 || u > 1.0)
		return (INFINITY);
	t_vector q;
	q.x = s.x * v1.z - s.z * v1.y;
	q.y = s.y * v1.x - s.x * v1.z;
	q.z = s.x * v1.y - s.y * v1.x;
	double v = f * vec_dot(ray->dir, q);
	if (v < 0.0 || u + v > 1.0)
		return (INFINITY);
	double t = f * vec_dot(v2, q);
	*normal = q;
	return t;
}

void	triangle_intersec_color(t_triangle *triangle, t_ray *ray, t_scene *scene)
{
	t_vector		ray_pos;
	t_vector		normal;
	double			t_;

	t_ = triangle_intersec_equation(ray, triangle, &normal);
	if (t_ < INFINITY && t_ > 1 && t_ < ray->ray_t)
	{
		ray->ray_t = t_;
		ray->obj = triangle;
		ray->ray_color = triangle->color;
		(void)ray_pos;
		(void)scene;
		ray_pos = ray_equation(ray, ray->ray_t);
		ray->ray_color = color_multipli(color_range1(ray->ray_color),
		compute_light(ray_pos, normal, scene, ray->obj));	
	}
}

void		raytotriangle(t_ray *ray, t_scene *scene)
{
	t_list			*triangle_list;
	t_triangle		*triangle;


	triangle_list = scene->triangle;
	while (triangle_list->next)
	{
		triangle = triangle_list->content;
		triangle_intersec_color(triangle, ray, scene);
		triangle_list = triangle_list->next;
	}
}