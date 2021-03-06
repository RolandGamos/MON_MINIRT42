/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 14:44:51 by lweglarz          #+#    #+#             */
/*   Updated: 2021/03/19 19:12:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

t_vector	vec_diff(t_vector v1, t_vector v2)
{
	t_vector	v3;

	v3.x = v1.x - v2.x;
	v3.y = v1.y - v2.y;
	v3.z = v1.z - v2.z;
	return (v3);
}

t_vector	vec_multipli_coeff(t_vector v1, double coeff)
{
	t_vector	v3;

	v3.x = v1.x * coeff;
	v3.y = v1.y * coeff;
	v3.z = v1.z * coeff;
	return (v3);
}

t_vector	vec_add(t_vector v1, t_vector v2)
{
	t_vector	v3;

	v3.x = v1.x + v2.x;
	v3.y = v1.y + v2.y;
	v3.z = v1.z + v2.z;
	return (v3);
}

t_vector	vec_div(t_vector v1, double nb)
{
	t_vector	v3;

	v3.x = v1.x / nb;
	v3.y = v1.y / nb;
	v3.z = v1.z / nb;
	return (v3);
}

t_vector	cross_product(t_vector v1, t_vector v2)
{
	t_vector result;

	result.x = v1.y * v2.z - v1.z * v2.y;
	result.y = v1.z * v2.x - v1.x * v2.z;
	result.z = v1.x * v2.y - v1.y * v2.x;
	return (result);
}
