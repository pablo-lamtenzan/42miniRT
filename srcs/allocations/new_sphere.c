/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:29:20 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/04 14:29:43 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shape.h>
#include <stdlib.h>
#include <aux.h>

t_sphere		*rt_new_sphere(t_vec3 pos, double d, t_color_precision color)
{
	t_sphere	*s;

	if (!(s = ft_calloc(sizeof(t_sphere), 1)))
		return (NULL);
	s->color = color;
	s->pos = pos;
	s->d = d;
	return (s);
}

void			rt_sphere_obj(t_obj *obj, t_sphere *s)
{
	obj->type = SPHERE;
	obj->collision = collisions_sphere;
	obj->get_normal = normal_sphere;
	obj->target = s;
	obj->color = s->color;
}
