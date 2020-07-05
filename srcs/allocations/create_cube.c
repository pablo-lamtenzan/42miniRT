/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cube.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:03:15 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/05 22:06:04 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <allocations.h>
#include <aux.h>
#include <stdlib.h>

void			map_square_fb(t_square *sq)
{
	sq->map[0] = vec_add(sq->pos, rotv(vec3(0, -sq->height / 2, \
			sq->height / 2), sq->dir));
	sq->map[1] = vec_add(sq->pos, rotv(vec3(0, sq->height / 2, \
			-sq->height / 2), sq->dir));
	sq->map[2] = vec_add(sq->pos, rotv(vec3(0, sq->height / 2, \
			sq->height / 2), sq->dir));
	sq->map[3] = vec_add(sq->pos, rotv(vec3(0, -sq->height / 2, \
			-sq->height / 2), sq->dir));
}

void			map_square_lr(t_square *sq)
{
	sq->map[0] = vec_add(sq->pos, rotv(vec3(-sq->height / 2, \
			-sq->height / 2, 0), sq->dir));
	sq->map[1] = vec_add(sq->pos, rotv(vec3(sq->height / 2, \
			sq->height / 2, 0), sq->dir));
	sq->map[2] = vec_add(sq->pos, rotv(vec3(-sq->height / 2, \
			sq->height / 2, 0), sq->dir));
	sq->map[3] = vec_add(sq->pos, rotv(vec3(sq->height / 2, \
			-sq->height / 2, 0), sq->dir));
}

static t_square	*alloc_sq_bonus(const t_square sq,
		void (*square_put)(t_square *sq))
{
	t_square	*new;

	if (!(new = malloc(sizeof(t_square))))
		return (NULL);
	new->pos = sq.pos;
	new->dir = sq.dir;
	new->height = sq.height;
	new->color = sq.color;
	square_put(new);
	return (new);
}

static bool		put_square(t_scene *s, t_obj *obj, const t_square sq,
	void (*square_put)(t_square *w))
{
	t_obj		*new;

	if (!(new = rt_new_obj(CUBE)))
		return (false);
	*new = *obj;
	new->cmp = CUBE;
	ft_objadd_back(&s->objs, new);
	rt_square_obj(new, alloc_sq_bonus(sq, square_put));
	return (true);
}

bool			create_cube(t_scene *s, t_obj *obj, const t_cu cu)
{
	t_square	sq;

	sq.pos = vec_add(cu.pos, rotv(vec3(0, -cu.height / 2, 0), cu.dir));
	sq.dir = cu.dir;
	sq.height = cu.height;
	sq.color = cu.color;
	if (!put_square(s, obj, sq, map_square))
		return (false);
	sq.pos = vec_add(cu.pos, rotv(vec3(0, cu.height / 2, 0), cu.dir));
	if (!put_square(s, obj, sq, map_square))
		return (false);
	sq.pos = vec_add(cu.pos, rotv(vec3(cu.height / 2, 0, 0), cu.dir));
	if (!put_square(s, obj, sq, map_square_fb))
		return (false);
	sq.pos = vec_add(cu.pos, rotv(vec3(-cu.height / 2, 0, 0), cu.dir));
	if (!put_square(s, obj, sq, map_square_fb))
		return (false);
	sq.pos = vec_add(cu.pos, rotv(vec3(0, 0, cu.height / 2), cu.dir));
	if (!put_square(s, obj, sq, map_square_lr))
		return (false);
	sq.pos = vec_add(cu.pos, rotv(vec3(0, 0, -cu.height / 2), cu.dir));
	if (!put_square(s, obj, sq, map_square_lr))
		return (false);
	return (true);
}
