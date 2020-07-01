/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3basics1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 20:21:54 by user42            #+#    #+#             */
/*   Updated: 2020/05/20 20:22:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3		vec_sub(t_vec3 v1, t_vec3 v2)
{
	t_vec3 res;

	res.x = v1.x - v2.x;
	res.y = v1.y - v2.y;
	res.z = v1.z - v2.z;
	return (res);
}

t_vec3		vec_add(t_vec3 v1, t_vec3 v2)
{
	t_vec3 res;

	res.x = v1.x + v2.x;
	res.y = v1.y + v2.y;
	res.z = v1.z + v2.z;
	return (res);
}

t_vec3		vec_scale(t_vec3 v, double c)
{
	t_vec3 res;

	res.x = v.x * c;
	res.y = v.y * c;
	res.z = v.z * c;
	return (res);
}

t_vec3		vec_div(t_vec3 v, double c)
{
	t_vec3 res;

	res.x = v.x / c;
	res.y = v.y / c;
	res.z = v.z / c;
	return (res);
}
