/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_dir_obj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 14:11:13 by user42            #+#    #+#             */
/*   Updated: 2020/07/02 22:42:34 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shape.h>
#include <hooks.h>
#include <aux.h>

void            change_dir_sq(int key, t_square *w, int dir)
{
	bool		update;

	update = false;
    if (key == XK_w && (update = true))
        resize_dir(&w->dir.x, 0.05);
    else if (key == XK_s && (update = true))
        resize_dir(&w->dir.x, -0.05);
    else if (key == XK_a && (update = true))
        resize_dir(&w->dir.y, 0.05);
    else if (key == XK_d && (update = true))
        resize_dir(&w->dir.y, -0.05);
    else if (key == XK_x && (update = true))
        resize_dir(&w->dir.z, 0.05);
    else if (key == XK_z && (update = true))
	{
        resize_dir(&w->dir.z, -0.05);
	}
	if (update)
		ft_putstr_fd("\033[35m SQUARE ROTATION\033[0m\n", 1);
	if (dir == 0)
		map_square(w);
	else if (dir == 1)
		map_square_fb(w);
	else if (dir == 2)
		map_square_lr(w);
}

void			change_dir_cu(int key , t_obj *cu)
{
	change_dir_sq(key, (t_square *)cu->target, 0);
	change_dir_sq(key, (t_square *)((t_obj *)cu->next)->target, 0);
	change_dir_sq(key, (t_square *)((t_obj *)((t_obj *)cu->next)->next)->target, 1);
	change_dir_sq(key, (t_square *)((t_obj *)((t_obj *)((t_obj *)cu->next)->next)->next)->target, 1);
	change_dir_sq(key, (t_square *)((t_obj *)((t_obj *)((t_obj *)((t_obj *)cu->next)->next)->next)->next)->target, 2);
	change_dir_sq(key, (t_square *)((t_obj *)((t_obj *)((t_obj *)((t_obj *)((t_obj *)cu->next)->next)->next)->next)->next)->target, 2);
}

void            change_dir_cy(int key, t_obj *obj)
{
	bool		update;
	t_vec3		pos;

	update = false;
    if (key == XK_w && (update = true))
        resize_dir(&((t_cyl *)obj->target)->dir.x, 0.05);
    else if (key == XK_s && (update = true))
        resize_dir(&((t_cyl *)obj->target)->dir.x, -0.05);
    else if (key == XK_a && (update = true))
        resize_dir(&((t_cyl *)obj->target)->dir.y, 0.05);
    else if (key == XK_d && (update = true))
        resize_dir(&((t_cyl *)obj->target)->dir.y, -0.05);
    else if (key == XK_x && (update = true))
        resize_dir(&((t_cyl *)obj->target)->dir.z, 0.05);
    else if (key == XK_z && (update = true))
	{
        resize_dir(&((t_cyl *)obj->target)->dir.z, -0.05);
	}
	//printf("[%f][%f][%f][h: %f][d: %f]\n", ((t_cyl *)obj->target)->dir.x, ((t_cyl *)obj->target)->dir.y, ((t_cyl *)obj->target)->dir.z, ((t_cyl *)obj->target)->height, ((t_cyl *)obj->target)->d);
	if (update)
	{
		(void)pos;
		pos = vec_scale(((t_cyl *)obj->target)->dir, ((t_cyl *)obj->target)->height / 2);
		((t_disk *)((t_obj *)obj->next)->target)->dir = ((t_cyl *)obj->target)->dir;
		((t_disk *)((t_obj *)((t_obj *)obj->next)->next)->target)->dir = ((t_cyl *)obj->target)->dir;
		((t_disk *)((t_obj *)obj->next)->target)->pos = vec_sub(((t_cyl *)obj->target)->pos, pos);
		((t_disk *)((t_obj *)((t_obj *)obj->next)->next)->target)->pos = vec_add(((t_cyl *)obj->target)->pos, pos);
		ft_putstr_fd("\033[35m CYLINDER ROTATION\033[0m\n", 1);
	}
}

void            change_dir_pl(int key, t_plane *w)
{
	bool		update;

	update = false;
    if (key == XK_w && (update = true))
        resize_dir(&w->dir.x, 0.05);
    else if (key == XK_s && (update = true))
        resize_dir(&w->dir.x, -0.05);
    else if (key == XK_a && (update = true))
        resize_dir(&w->dir.y, 0.05);
    else if (key == XK_d && (update = true))
        resize_dir(&w->dir.y, -0.05);
    else if (key == XK_x && (update = true))
        resize_dir(&w->dir.z, 0.05);
    else if (key == XK_z && (update = true))
	{
        resize_dir(&w->dir.z, -0.05);
	}
	if (update)
		ft_putstr_fd("\033[35m PLANE ROTATION\033[0m\n", 1);
}

void            change_dir_co(int key, t_co *w)
{
	bool		update;

	update = false;
    if (key == XK_w && (update = true))
        resize_dir(&w->dir.x, 0.05);
    else if (key == XK_s && (update = true))
        resize_dir(&w->dir.x, -0.05);
    else if (key == XK_a && (update = true))
        resize_dir(&w->dir.y, 0.05);
    else if (key == XK_d && (update = true))
        resize_dir(&w->dir.y, -0.05);
    else if (key == XK_x && (update = true))
        resize_dir(&w->dir.z, 0.05);
    else if (key == XK_z && (update = true))
	{
        resize_dir(&w->dir.z, -0.05);
	}
	if (update)
		ft_putstr_fd("\033[35m CONE ROTATION\033[0m\n", 1);
}