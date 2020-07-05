/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pyramid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:10:27 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/05 21:03:32 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <allocations.h>
#include <aux.h>
#include <stdlib.h>

static bool		put_triangle(t_scene *s, t_obj *obj, const t_tri t)
{
	t_obj		*tr;

	if (!(tr = rt_new_obj(PYRAMID)))
		return (false);
	*tr = *obj;
	tr->cmp = PYRAMID;
	ft_objadd_back(&s->objs, tr);
	rt_triangle_obj(tr, rt_new_triangle(t.v0, t.v1, t.v2, t.color));
	return (true);
}

static bool		create_pyramid_fill(t_scene *s, t_obj *obj, t_obj *sq, t_tri t)
{
	t.v1 = ((t_square *)sq->target)->map[2];
	t.v2 = ((t_square *)sq->target)->map[1];
	if (!put_triangle(s, obj, t))
		return (false);
	t.v1 = ((t_square *)sq->target)->map[1];
	t.v2 = ((t_square *)sq->target)->map[3];
	if (!put_triangle(s, obj, t))
		return (false);
	t.v1 = ((t_square *)sq->target)->map[3];
	t.v2 = ((t_square *)sq->target)->map[0];
	if (!put_triangle(s, obj, t))
		return (false);
	return (true);
}

bool			create_pyramid(t_scene *s, t_obj *obj, const t_py py)
{
	t_tri		t;
	t_vec3		pos;
	t_vec3		c;
	t_obj		*sq;

	if (!(sq = rt_new_obj(PYRAMID)))
		return (false);
	*sq = *obj;
	sq->cmp = PYRAMID;
	ft_objadd_back(&s->objs, sq);
	pos = vec_add(py.pos, rotv(vec3(0, -py.base_height / 2, 0), py.dir));
	rt_square_obj(sq, rt_new_square(pos, py.dir, py.base_height, py.color));
	c = vec3(0, py.base_height / 2, 0);
	c = vec_add(py.pos, rotv(c, py.dir));
	t.v0 = c;
	t.v1 = ((t_square *)sq->target)->map[0];
	t.v2 = ((t_square *)sq->target)->map[2];
	t.color = py.color;
	if (!put_triangle(s, obj, t))
		return (false);
	return (create_pyramid_fill(s, obj, sq, t));
}
