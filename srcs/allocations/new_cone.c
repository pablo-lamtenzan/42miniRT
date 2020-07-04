/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:21:51 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/04 14:21:55 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shape.h>
#include <stdlib.h>
#include <aux.h>

t_co			*rt_new_cone(t_ray posdir, double curve, double height,
		t_color_precision color)
{
	t_co		*co;

	if (!(co = ft_calloc(sizeof(t_co), 1)))
		return (NULL);
	co->color = color;
	co->pos = posdir.pos;
	co->dir = posdir.dir;
	co->curve = curve;
	co->height = height;
	return (co);
}

void			rt_cone_obj(t_obj *obj, t_co *co)
{
	obj->type = CONE;
	obj->collision = collisions_cone;
	obj->get_normal = normal_cone;
	obj->target = co;
	obj->color = co->color;
}
