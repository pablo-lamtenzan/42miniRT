/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_pos_obj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 14:23:53 by user42            #+#    #+#             */
/*   Updated: 2020/06/26 18:35:51 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shape.h>
#include <hooks.h>

void            change_pos_sq(int key, t_square *w)
{
    if (key == 126)
        w->pos.y += 20;
    else if (key == 125)
        w->pos.y -= 20;
    else if (key == 123)
        w->pos.x -= 20;
    else if (key == 124)
        w->pos.x += 20;
    else if (key == 78)
        w->pos.z += 20;
    else if (key == 69)
        w->pos.z -= 20;
}

void            change_pos_cy(int key, t_cyl *w)
{
    if (key == 126)
        w->pos.y += 20;
    else if (key == 125)
        w->pos.y -= 20;
    else if (key == 123)
        w->pos.x -= 20;
    else if (key == 124)
        w->pos.x += 20;
    else if (key == 78)
        w->pos.z += 20;
    else if (key == 69)
        w->pos.z -= 20;
}

void            change_pos_pl(int key, t_plane *w)
{
    if (key == 126)
        w->pos.y += 20;
    else if (key == 125)
        w->pos.y -= 20;
    else if (key == 123)
        w->pos.x -= 20;
    else if (key == 124)
        w->pos.x += 20;
    else if (key == 78)
        w->pos.z += 20;
    else if (key == 69)
        w->pos.z -= 20;
}

void            change_pos_sp(int key, t_sphere *w)
{
    if (key == 126)
        w->pos.y += 20;
    else if (key == 125)
        w->pos.y -= 20;
    else if (key == 123)
        w->pos.x -= 20;
    else if (key == 124)
        w->pos.x += 20;
    else if (key == 78)
        w->pos.z += 20;
    else if (key == 69)
        w->pos.z -= 20;
}

void            change_pos_co(int key, t_co *w)
{
    if (key == 126)
        w->pos.y += 20;
    else if (key == 125)
        w->pos.y -= 20;
    else if (key == 123)
        w->pos.x -= 20;
    else if (key == 124)
        w->pos.x += 20;
    else if (key == 78)
        w->pos.z += 20;
    else if (key == 69)
        w->pos.z -= 20;
}

void            change_pos_tr(int key, t_tri *w)
{
    t_vec3      pos; // think this could be true_o

    pos = w->v0;
    if (key == 126)
        w->v0.y += 20;
    else if (key == 125)
        w->v0.y -= 20;
    else if (key == 123)
        w->v0.x -= 20;
    else if (key == 124)
        w->v0.x += 20;
    else if (key == 78)
        w->v0.z += 20;
    else if (key == 69)
        w->v0.z -= 20;
    w->v1 = vec_add(w->v1, vec_sub(w->v0, pos));
    w->v2 = vec_add(w->v2, vec_sub(w->v0, pos));
}
