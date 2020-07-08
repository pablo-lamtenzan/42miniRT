/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:26:31 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/07 20:12:54 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shape.h>
#include <stdlib.h>
#include <aux.h>

t_plane		*rt_new_plane(const t_vec3 pos, const t_vec3 dir,
		const t_color_precision color)
{
	t_plane		*p;

	if (!(p = ft_calloc(sizeof(t_plane), 1)))
		return (NULL);
	p->pos = pos;
	p->dir = dir;
	p->color = color;
	return (p);
}

void		rt_plane_obj(t_obj *obj, t_plane *p)
{
	obj->type = PLANE;
	obj->collision = collisions_plane;
	obj->get_normal = normal_plane;
	obj->target = p;
	obj->color = p->color;
}
