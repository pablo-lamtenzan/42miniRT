/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_triangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 14:29:31 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/07 20:13:07 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shape.h>
#include <stdlib.h>
#include <aux.h>

t_tri			*rt_new_triangle(const t_vec3 v0, const t_vec3 v1,
		const t_vec3 v2, const t_color_precision color)
{
	t_tri		*tri;

	if (!(tri = ft_calloc(sizeof(t_tri), 1)))
		return (NULL);
	tri->v0 = v0;
	tri->v1 = v1;
	tri->v2 = v2;
	tri->color = color;
	return (tri);
}

void			rt_triangle_obj(t_obj *obj, t_tri *t)
{
	obj->type = TRIANGLE;
	obj->collision = collisions_triangle;
	obj->get_normal = normal_triangle;
	obj->target = t;
	obj->color = t->color;
}
