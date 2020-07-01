/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_dir_obj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 14:11:13 by user42            #+#    #+#             */
/*   Updated: 2020/06/26 18:35:39 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shape.h>
#include <hooks.h>

void            change_dir_sq(int key, t_square *w)
{
    if (key == 13)
        resize_dir(&w->dir.x, 0.05);
    else if (key == 1)
        resize_dir(&w->dir.x, -0.05);
    else if (key == 0)
        resize_dir(&w->dir.y, 0.05);
    else if (key == 2)
        resize_dir(&w->dir.y, -0.05);
    else if (key == 12)
        resize_dir(&w->dir.z, 0.05);
    else if (key == 14)
        resize_dir(&w->dir.z, -0.05);
}

void            change_dir_cy(int key, t_cyl *w)
{
    if (key == 13)
        resize_dir(&w->dir.x, 0.05);
    else if (key == 1)
        resize_dir(&w->dir.x, -0.05);
    else if (key == 0)
        resize_dir(&w->dir.y, 0.05);
    else if (key == 2)
        resize_dir(&w->dir.y, -0.05);
    else if (key == 12)
        resize_dir(&w->dir.z, 0.05);
    else if (key == 14)
        resize_dir(&w->dir.z, -0.05);
}

void            change_dir_pl(int key, t_plane *w)
{
    if (key == 13)
        resize_dir(&w->dir.x, 0.05);
    else if (key == 1)
        resize_dir(&w->dir.x, -0.05);
    else if (key == 0)
        resize_dir(&w->dir.y, 0.05);
    else if (key == 2)
        resize_dir(&w->dir.y, -0.05);
    else if (key == 12)
        resize_dir(&w->dir.z, 0.05);
    else if (key == 14)
        resize_dir(&w->dir.z, -0.05);
}

void            change_dir_co(int key, t_co *w)
{
    if (key == 13)
        resize_dir(&w->dir.x, 0.05);
    else if (key == 1)
        resize_dir(&w->dir.x, -0.05);
    else if (key == 0)
        resize_dir(&w->dir.y, 0.05);
    else if (key == 2)
        resize_dir(&w->dir.y, -0.05);
    else if (key == 12)
        resize_dir(&w->dir.z, 0.05);
    else if (key == 14)
        resize_dir(&w->dir.z, -0.05);
}