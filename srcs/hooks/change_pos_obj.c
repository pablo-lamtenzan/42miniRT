/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_pos_obj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 14:23:53 by user42            #+#    #+#             */
/*   Updated: 2020/07/02 17:45:08 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shape.h>
#include <hooks.h>
#include <aux.h>

void            change_pos_sq(int key, t_square *w)
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
	map_square(w);
}

void            change_pos_cy(int key, t_cyl *w)
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
		ft_putstr_fd("\033[35m CYLINDER TRANSLATION\033[0m\n", 1);
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
