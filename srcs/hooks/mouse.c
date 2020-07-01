/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 20:25:25 by user42            #+#    #+#             */
/*   Updated: 2020/07/01 15:18:36 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <allocations.h>
#include <hooks.h>

void            resize_dir(double *point, double resize) // good
{
    if (*point + resize > 1)
        *point = -1;
    else if (*point + resize < 1)
        *point = 1;
    else
        *point += resize;
}

int             motion_hook(int x, int y, void *fill) // good
{
    t_scene *s;

    s = (t_scene *)fill;
    if (s->mouse < 0)
        return (-1);
    if (x > s->image->max_w / 3 && x < s->image->max_w / 2)
        resize_dir(&s->cams->dir.y, -0.01 * s->mouse);
    else if (x < s->image->max_w / 2 / 3)
        resize_dir(&s->cams->dir.y, 0.01 * s->mouse);
    if (y > s->image->max_h / 3 && y < s->image->max_h / 2)
        resize_dir(&s->cams->dir.x, -0.01 * s->mouse);
    else if (y < s->image->max_h / 2 / 3)
        resize_dir(&s->cams->dir.x, 0.01 * s->mouse);
    mlx_destroy_image(s->image->mlx, s->image->img);
    s->image->img = NULL;
    calc_image_hooks(s);
    return (0);
}

int             motion_end(void *fill) // good
{
    t_scene *s;

    s = (t_scene *)fill;
    free_all(s);
    return (0);
}

int             mouse_hook(int key, int x, int y, void *fill)
{
    t_scene     *s;
    bool        update;

    s = (t_scene *)fill;
    update = false;
    x += x - x;
    y += y - y;
    if (key == 4 && (update = true)) // 'h'
        s->cams->pos.z -= 20;
    else if (key == 5 && (update = true)) // 'g'
        s->cams->pos.z += 20;
    if (key == 3 && (update == true)) // 'f'
        s->mouse = -s->mouse;
    else if (key == 1 && s->mouse > 0 && (update = true)) // 's'
        s->mouse++;
    else if (key == 2 && s->mouse > 1 && (update = true)) // 'd'
        s->mouse--;
    if (update)
    {
        mlx_destroy_image(s->image->mlx, s->image->img);
        s->image->img = NULL;
        calc_image_hooks(s);
    }
    return (key);
}