/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_pos_obj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 18:50:11 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/07 20:13:25 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shape.h>
#include <hooks.h>
#include <aux.h>

void			change_pos_sq(const int key, t_square *w, int dir)
{
	bool		update;

	update = false;
	if (key == XK_Up && (update = true))
		w->pos.y += 20;
	else if (key == XK_Down && (update = true))
		w->pos.y -= 20;
	else if (key == XK_Left && (update = true))
		w->pos.x -= 20;
	else if (key == XK_Right && (update = true))
		w->pos.x += 20;
	else if (key == XK_m && (update = true))
		w->pos.z += 20;
	else if (key == XK_n && (update = true))
	{
		w->pos.z -= 20;
	}
	if (update)
		ft_putstr_fd("\033[35m SQUARE TRANSLATION\033[0m\n", 1);
	if (dir == 0)
		map_square(w);
	else if (dir == 1)
		map_square_fb(w);
	else if (dir == 2)
		map_square_lr(w);
}

void			change_pos_py(const int key, t_obj *py)
{
	change_pos_sq(key, (t_square *)py->target, 0);
	change_pos_tr(key, (t_tri *)((t_obj *)py->next)->target);
	change_pos_tr(key, (t_tri *)((t_obj *)((t_obj *)py->next)->next)->target);
	change_pos_tr(key, (t_tri *)((t_obj *)((t_obj *)(\
			(t_obj *)py->next)->next)->next)->target);
	change_pos_tr(key, (t_tri *)((t_obj *)((t_obj *)((t_obj *)(\
			(t_obj *)py->next)->next)->next)->next)->target);
}

void			change_pos_cu(const int key, t_obj *cu)
{
	change_pos_sq(key, (t_square *)cu->target, 0);
	change_pos_sq(key, (t_square *)((t_obj *)cu->next)->target, 0);
	change_pos_sq(key, (t_square *)((t_obj *)(\
			(t_obj *)cu->next)->next)->target, 1);
	change_pos_sq(key, (t_square *)((t_obj *)((t_obj *)(\
			(t_obj *)cu->next)->next)->next)->target, 1);
	change_pos_sq(key, (t_square *)((t_obj *)((t_obj *)((t_obj *)(\
			(t_obj *)cu->next)->next)->next)->next)->target, 2);
	change_pos_sq(key, (t_square *)((t_obj *)((t_obj *)((t_obj *)((t_obj *)(\
			(t_obj *)cu->next)->next)->next)->next)->next)->target, 2);
}

static void		change_pos_cy_fill(t_obj *obj, t_vec3 pos)
{
	((t_disk *)((t_obj *)obj->next)->target)->pos = \
			vec_sub(((t_cyl *)obj->target)->pos, pos);
	((t_disk *)((t_obj *)((t_obj *)obj->next)->next)->target)->pos = \
			vec_add(((t_cyl *)obj->target)->pos, pos);
	ft_putstr_fd("\033[35m CYLINDER TRANSLATION\033[0m\n", 1);
}

void			change_pos_cy(const int key, t_obj *obj)
{
	bool		update;
	t_vec3		pos;

	update = false;
	pos = vec_scale(((t_cyl *)obj->target)->dir, \
			((t_cyl *)obj->target)->height / 2);
	if (key == XK_Up && (update = true))
		((t_cyl *)obj->target)->pos.y += 20;
	else if (key == XK_Down && (update = true))
		((t_cyl *)obj->target)->pos.y -= 20;
	else if (key == XK_Left && (update = true))
		((t_cyl *)obj->target)->pos.x -= 20;
	else if (key == XK_Right && (update = true))
		((t_cyl *)obj->target)->pos.x += 20;
	else if (key == XK_m && (update = true))
		((t_cyl *)obj->target)->pos.z += 20;
	else if (key == XK_n && (update = true))
	{
		((t_cyl *)obj->target)->pos.z -= 20;
	}
	if (update)
		change_pos_cy_fill(obj, pos);
}
