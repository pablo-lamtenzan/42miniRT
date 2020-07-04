/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_collisions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 15:08:24 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/04 15:09:01 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shape.h>

bool		collisions_plane(t_ray r, void *pl, double *t)
{
	t_vec2	d;

	d.x = dot(vec_sub(r.pos, ((t_plane *)pl)->pos), ((t_plane *)pl)->dir);
	if (!(d.y = dot(r.dir, ((t_plane *)pl)->dir)))
		return (false);
	if (-d.x / d.y > 0)
	{
		*t = -d.x / d.y;
		return (true);
	}
	return (false);
}
