/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 21:29:26 by user42            #+#    #+#             */
/*   Updated: 2020/07/02 22:17:04 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shape.h>
#include <hooks.h>
#include <aux.h>

void            key_rotation(int key, t_obj *obj)
{
    if (obj->type == SQUARE)
        change_dir_sq(key, (t_square *)obj->target, 0);
    else if (obj->type == CYLINDER)
        change_dir_cy(key, obj);
    else if (obj->type == PLANE)
        change_dir_pl(key, (t_plane *)obj->target);
    else if (obj->type == CONE)
        change_dir_co(key, (t_co *)obj->target);
	else if (obj->type == CUBE)
		change_dir_cu(key , obj);
	else if ((key == XK_w || key == XK_s || key == XK_a || key == XK_d || key == XK_x || key == XK_y) &&
			(obj->type == TRIANGLE || obj->type == SPHERE || obj->type == PYRAMID))
		ft_putstr_fd("\033[35m SUJECT DOESN'T ALLOW THIS SHAPE ROTATION\033[0m\n", 1);
}

void            key_translation(int key, t_obj *obj)
{
    if (obj->type == SQUARE)
        change_pos_sq(key, (t_square *)obj->target, 0);
    else if (obj->type == CYLINDER)
        change_pos_cy(key, obj);
    else if (obj->type == PLANE)
        change_pos_pl(key, (t_plane *)obj->target);
    else if (obj->type == SPHERE)
        change_pos_sp(key, (t_sphere *)obj->target);
    else if (obj->type == TRIANGLE)
        change_pos_tr(key, (t_tri *)obj->target);
    else if (obj->type == CONE)
        change_pos_co(key, (t_co *)obj->target);
	else if (obj->type == CUBE)
		change_pos_cu(key, obj);
	else if (obj->type == PYRAMID)
		change_pos_py(key, obj);
}
