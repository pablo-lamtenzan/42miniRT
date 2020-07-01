/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 22:10:26 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/01 14:53:57 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3		vec3(double x, double y, double z)
{
	t_vec3 vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_ray			ray2(t_vec3 pos, t_vec3 dir)
{
	t_ray ray;

	ray.pos = pos;
	ray.dir = dir;
	return (ray);
}

t_vec3		get_rad(t_vec3 ang)
{
	t_vec3	rad;

	rad.x = M_PI * ang.x / 180;
	rad.y = M_PI * ang.y / 180;
	rad.z = M_PI * ang.z / 180;
	return (rad);
}