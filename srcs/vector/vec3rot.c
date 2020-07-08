/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 20:19:24 by user42            #+#    #+#             */
/*   Updated: 2020/07/07 20:15:01 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vec3.h>

t_vec3			vec_rotation(const t_vec3 dir, const t_vec3 rad)
{
	t_vec3		res;

	res.x = (((dir.x * cos(rad.y)) - (dir.z * cos(rad.x)) -
				(dir.y * sin(rad.x)) * sin(rad.y) * cos(rad.z)) +
			(((dir.y * cos(rad.x)) + (dir.z * sin(rad.x))) * sin(rad.z)));
	res.y = (((dir.y * cos(rad.x)) - (dir.z * sin(rad.x))) * cos(rad.z)) -
				(((dir.x * cos(rad.y)) - (((dir.z * cos(rad.x)) -
			(dir.y * sin(rad.x))) * sin(rad.x))) * sin(rad.z));
	res.z = (((dir.z * cos(rad.x)) - (dir.y * sin(rad.x))) *
			cos(rad.y)) + (dir.x * sin(rad.y));
	return (res);
}

static t_vec3	rot_x(const t_vec3 v, const double r)
{
	t_vec3		result;

	result.x = v.x;
	result.y = v.y * cos(r) - v.z * sin(r);
	result.z = v.y * sin(r) + v.z * cos(r);
	return (result);
}

static t_vec3	rot_y(const t_vec3 v, const double r)
{
	t_vec3		result;

	result.y = v.y;
	result.x = v.x * cos(r) + v.z * sin(r);
	result.z = -v.x * sin(r) + v.z * cos(r);
	return (result);
}

static t_vec3	rot_z(const t_vec3 v, const double r)
{
	t_vec3		result;

	result.z = v.z;
	result.x = v.x * cos(r) - v.y * sin(r);
	result.y = v.x * sin(r) + v.y * cos(r);
	return (result);
}

t_vec3			rotv(const t_vec3 v, const t_vec3 r)
{
	t_vec3		result;

	result = v;
	result = rot_x(result, r.x * M_PI);
	result = rot_y(result, r.y * M_PI);
	result = rot_z(result, r.z * M_PI);
	return (result);
}
