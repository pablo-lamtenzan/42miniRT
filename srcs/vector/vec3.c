/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 15:15:38 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/07 20:14:55 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vec3.h>

t_vec3			vec3(const double x, const double y, const double z)
{
	t_vec3 vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_ray			ray2(const t_vec3 pos, const t_vec3 dir)
{
	t_ray ray;

	ray.pos = pos;
	ray.dir = dir;
	return (ray);
}

t_vec3			get_rad(const t_vec3 ang)
{
	t_vec3		rad;

	rad.x = M_PI * ang.x / 180;
	rad.y = M_PI * ang.y / 180;
	rad.z = M_PI * ang.z / 180;
	return (rad);
}
