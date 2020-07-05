/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_dir_pos_obj2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 18:46:45 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/05 23:14:06 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shape.h>
#include <hooks.h>
#include <aux.h>

void			change_pos_pl(const int key, t_plane *w)
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
		ft_putstr_fd("\033[35m PLANE TRANSLATION\033[0m\n", 1);
}

void			change_pos_sp(const int key, t_sphere *w)
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
		ft_putstr_fd("\033[35m SPHERE TRANSLATION\033[0m\n", 1);
}

void			change_pos_co(const int key, t_co *w)
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
		ft_putstr_fd("\033[35m CONE TRANSLATION\033[0m\n", 1);
}

void			change_pos_tr(int key, t_tri *w)
{
	t_vec3		pos;
	bool		update;

	pos = w->v0;
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
		ft_putstr_fd("\033[35m TRIANGLE TRANSLATION\033[0m\n", 1);
}

void			change_dir_co(const int key, t_co *w)
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
