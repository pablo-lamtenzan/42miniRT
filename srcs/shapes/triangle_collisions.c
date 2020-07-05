/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_collisions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 15:13:14 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/05 16:37:32 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shape.h>

bool			collisions_triangle(const t_ray r, void *tr, double *t)
{
	t_vec3		d;
	t_vec3		v[5];

	v[0] = vec_sub(((t_tri *)tr)->v1, ((t_tri *)tr)->v0);
	v[1] = vec_sub(((t_tri *)tr)->v2, ((t_tri *)tr)->v0);
	v[2] = cross_product(r.dir, v[1]);
	if (!(d.x = dot(v[0], v[2])))
		return (false);
	d.x = 1 / d.x;
	v[3] = vec_sub(r.pos, ((t_tri *)tr)->v0);
	d.y = d.x * dot(v[3], v[2]);
	if (d.y < 0 || d.y > 1)
		return (false);
	v[4] = cross_product(v[3], v[0]);
	d.z = d.x * dot(r.dir, v[4]);
	if (d.z < 0.0 || d.y + d.z > 1.0)
		return (false);
	d.y = d.x * dot(v[1], v[4]);
	if (d.y > 0.001)
	{
		*t = d.y;
		return (true);
	}
	return (false);
}
