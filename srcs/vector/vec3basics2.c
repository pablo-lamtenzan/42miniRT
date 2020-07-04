/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3basics2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 20:23:03 by user42            #+#    #+#             */
/*   Updated: 2020/07/04 15:17:46 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vec3.h>

t_vec3			normalise(t_vec3 v)
{
	double		md;

	if ((md = sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2))) <= 0)
		return (vec3(0, 0, 0));
	return (vec_div(v, md));
}

double			dot(t_vec3 v1, t_vec3 v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

double			vec_len(t_vec3 a)
{
	return (sqrt((a.x * a.x) + (a.y * a.y) + (a.z * a.z)));
}

t_vec3			cross_product(t_vec3 v1, t_vec3 v2)
{
	t_vec3		res;

	res.x = v1.y * v2.z - v1.z * v2.y;
	res.y = v1.z * v2.x - v1.x * v2.z;
	res.z = v1.x * v2.y - v1.y * v2.x;
	return (res);
}

double			norm_vec3(t_vec3 v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}
