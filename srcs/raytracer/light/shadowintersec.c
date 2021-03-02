/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadowintersec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 16:19:34 by user42            #+#    #+#             */
/*   Updated: 2021/03/02 16:19:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

int	sphere_intersec(t_scene scene, t_ray *ray, double length)
{
	double			t[2];
	double	t_;
	t_list			*sphere_list;
	t_sphere		*sphere;

	sphere_list = scene.sphere;
	while (sphere_list->next)
	{
		sphere = sphere_list->content;
		t_ = sphere_intersec_equation(ray, sphere, t);
		if (t_ > 0.0001 && t_ < length && t_ < ray->ray_t)
		{
			ray->ray_t = t_;
			ray->obj = sphere;
		}
		sphere_list = sphere_list->next;
	}
	if (ray->ray_t != INFINITY)
		return (1);
	return (0);
}