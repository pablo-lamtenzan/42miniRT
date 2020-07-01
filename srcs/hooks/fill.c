/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 21:29:26 by user42            #+#    #+#             */
/*   Updated: 2020/06/26 18:39:32 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shape.h>
#include <hooks.h>

// 2 types of rotation for 2 different objs ????
void            key_rotation(int key, t_obj *obj)
{
    t_square    *sq;
    t_cyl       *cy;
    t_plane     *pl;
    t_co        *co;

    if (obj->type == SQUARE)
    {
        sq = (t_square *)obj->target;
        change_dir_sq(key, sq);
    }
    else if (obj->type == CYLINDER)
    {
        cy = (t_cyl *)obj->target;
        change_dir_cy(key, cy);
        // + disck dir
    }
    else if (obj->type == PLANE)
    {
        pl = (t_plane *)obj->target;
        change_dir_pl(key, pl);
    }
    else if (obj->type == CONE)
    {
        co = (t_co *)obj->target;
        change_dir_co(key, co);
    }
    else if (obj->type == PYRAMID || obj->type == CUBE)
    {
		; // think about
	}
}

/*
// do the same with key_rotation_bis using vec_rot_p()
void            key_rotation_bis(int key, t_obj *obj)
{
    // TO DO
}
*/


void            key_translation(int key, t_obj *obj)
{
    t_square    *sq;
    t_cyl       *cy;
    t_plane     *pl;
    t_sphere    *sp;
    t_tri       *tr;
    t_co        *co;

    if (obj->type == SQUARE)
    {
        sq = (t_square *)obj->target;
        change_pos_sq(key, sq);
    }
    else if (obj->type == CYLINDER)
    {
        cy = (t_cyl *)obj->target;
        change_pos_cy(key, cy);
        // + disks
    }
    else if (obj->type == PLANE)
    {
        pl = (t_plane *)obj->target;
        change_pos_pl(key, pl);
    }
    else if (obj->type == SPHERE)
    {
        sp = (t_sphere *)obj->target;
        change_pos_sp(key, sp);
    }
    else if (obj->type == TRIANGLE)
    {
        tr = (t_tri *)obj->target;
        change_pos_tr(key, tr);
    }
    else if (obj->type == CONE)
    {
        co = (t_co *)obj->target;
        change_pos_co(key, co);
    }
}
