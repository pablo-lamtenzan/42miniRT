/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_dir_obj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 14:11:13 by user42            #+#    #+#             */
/*   Updated: 2020/07/02 18:25:00 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shape.h>
#include <hooks.h>
#include <aux.h>

void            change_dir_sq(int key, t_square *w)
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
	map_square(w);
}

void            change_dir_cy(int key, t_cyl *w)
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
		ft_putstr_fd("\033[35m CYLINDER ROTATION\033[0m\n", 1);
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