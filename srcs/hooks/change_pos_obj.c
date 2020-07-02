/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_pos_obj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 14:23:53 by user42            #+#    #+#             */
/*   Updated: 2020/07/02 21:58:35 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shape.h>
#include <hooks.h>
#include <aux.h>

void            change_pos_sq(int key, t_square *w, int dir)
{
	bool 		update;

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

void			change_pos_py(int key, t_obj *py)
{
	change_pos_sq(key, (t_square *)py->target, 0);
	change_pos_tr(key, (t_tri *)((t_obj *)py->next)->target);
	change_pos_tr(key, (t_tri *)((t_obj *)((t_obj *)py->next)->next)->target);
	change_pos_tr(key, (t_tri *)((t_obj *)((t_obj *)((t_obj *)py->next)->next)->next)->target);
	change_pos_tr(key, (t_tri *)((t_obj *)((t_obj *)((t_obj *)((t_obj *)py->next)->next)->next)->next)->target);
}

void			change_pos_cu(int key , t_obj *cu)
{
	change_pos_sq(key, (t_square *)cu->target, 0);
	change_pos_sq(key, (t_square *)((t_obj *)cu->next)->target, 0);
	change_pos_sq(key, (t_square *)((t_obj *)((t_obj *)cu->next)->next)->target, 1);
	change_pos_sq(key, (t_square *)((t_obj *)((t_obj *)((t_obj *)cu->next)->next)->next)->target, 1);
	change_pos_sq(key, (t_square *)((t_obj *)((t_obj *)((t_obj *)((t_obj *)cu->next)->next)->next)->next)->target, 2);
	change_pos_sq(key, (t_square *)((t_obj *)((t_obj *)((t_obj *)((t_obj *)((t_obj *)cu->next)->next)->next)->next)->next)->target, 2);
}

void            change_pos_cy(int key, t_obj *obj)
{
	bool 		update;
	t_vec3		pos;

	update = false;
	pos = vec_scale(((t_cyl *)obj->target)->dir, ((t_cyl *)obj->target)->height / 2);
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
	{
		((t_disk *)((t_obj *)obj->next)->target)->pos = vec_sub(((t_cyl *)obj->target)->pos, pos);
		((t_disk *)((t_obj *)((t_obj *)obj->next)->next)->target)->pos = vec_add(((t_cyl *)obj->target)->pos, pos);
		ft_putstr_fd("\033[35m CYLINDER TRANSLATION\033[0m\n", 1);
	}
}

void            change_pos_pl(int key, t_plane *w)
{
	bool 		update;

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
		ft_putstr_fd("\033[35m PLANE TRANSLATION\033[0m\n", 1);
}

void            change_pos_sp(int key, t_sphere *w)
{
	bool 		update;

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
		ft_putstr_fd("\033[35m SPHERE TRANSLATION\033[0m\n", 1);
} 
void            change_pos_co(int key, t_co *w)
{
	bool 		update;

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
		ft_putstr_fd("\033[35m CONE TRANSLATION\033[0m\n", 1);
}

void            change_pos_tr(int key, t_tri *w)
{
    t_vec3      pos;

    pos = w->v0;
	bool 		update;

	update = false;
    if (key == XK_Up && (update = true))
        w->v0.y += 20;
    else if (key == XK_Down && (update = true))
        w->v0.y -= 20;
    else if (key == XK_Left && (update = true))
        w->v0.x -= 20;
    else if (key == XK_Right && (update = true))
        w->v0.x += 20;
    else if (key == XK_m && (update = true))
        w->v0.z += 20;
    else if (key == XK_n && (update = true))
        w->v0.z -= 20;
    w->v1 = vec_add(w->v1, vec_sub(w->v0, pos));
    w->v2 = vec_add(w->v2, vec_sub(w->v0, pos));
	if (update)
		ft_putstr_fd("\033[35m TRAINGLE TRANSLATION\033[0m\n", 1);
}
