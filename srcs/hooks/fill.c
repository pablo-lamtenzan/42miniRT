/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 21:29:26 by user42            #+#    #+#             */
/*   Updated: 2020/07/02 18:23:53 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shape.h>
#include <hooks.h>

void            key_rotation(int key, t_obj *obj)
{
    if (obj->type == SQUARE)
        change_dir_sq(key, (t_square *)obj->target);
    else if (obj->type == CYLINDER)
        change_dir_cy(key, (t_cyl *)obj->target);
        // + disck dir
    else if (obj->type == PLANE)
        change_dir_pl(key, (t_plane *)obj->target);
    else if (obj->type == CONE)
        change_dir_co(key, (t_co *)obj->target);
    else if (obj->type == PYRAMID || obj->type == CUBE)
    {
		; // think about
	}
}

void            key_translation(int key, t_obj *obj)
{
    if (obj->type == SQUARE)
        change_pos_sq(key, (t_square *)obj->target);
    else if (obj->type == CYLINDER)
        change_pos_cy(key, (t_cyl *)obj->target);
        // + disks
    else if (obj->type == PLANE)
        change_pos_pl(key, (t_plane *)obj->target);
    else if (obj->type == SPHERE)
        change_pos_sp(key, (t_sphere *)obj->target);
    else if (obj->type == TRIANGLE)
        change_pos_tr(key, (t_tri *)obj->target);
    else if (obj->type == CONE)
        change_pos_co(key, (t_co *)obj->target);
}
