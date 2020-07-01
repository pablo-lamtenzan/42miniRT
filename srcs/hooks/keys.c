/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 21:07:30 by user42            #+#    #+#             */
/*   Updated: 2020/06/26 18:40:46 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <allocations.h>
#include <stdio.h>
#include <hooks.h>

int         switch_cam_or_obj(int key, t_scene *s) // good
{
    if (key == 24) // '*'
        s->cams = s->cams->next;
    else if (key == 27) // '-'
        s->cams = s->cams->back;
    else if (key == 35) // 'p'
        s->objs = s->objs->next;
    else if (key == 31) // 'o'
        s->objs = s->objs->back;
    return (key);
}

int         key_normal(int key, void *fill) // good
{
    t_scene *s;

    s = (t_scene *)fill;
    if (key == 49 || (key >= 83 && key <= 88)) // 'esp' or 'digit'
    {
        mlx_destroy_image(s->image->mlx, s->image->img);
        s->image->img = NULL;
        mlx_clear_window(s->image->mlx, s->image->win);
        calc_image(s);
        mlx_put_image_to_window(s->image->mlx, s->image->win, s->image, 0,0);
        return (-1);
    }
    return (key);
}

int         key_hook(int key, void *fill)
{
    t_scene *s;
    
    s = (t_scene *)fill;
    if (key == 53) // ESC
        free_all(s);
    switch_cam_or_obj(key, s);
    key_rotation(key, s->objs);
    // key_rotaion_bis(key, s->objs);
    // key atribute (no need i think)
    key_translation(key, s->objs);
    // key effect (no needed)
    // WEIRD THINGS WITH PTHREADS TO SEE
    if (key_normal(key, s) == -1)
        return (key);
    mlx_destroy_image(s->image->mlx, s->image->img);
    s->image->img = NULL;
    calc_image_hooks(s);
    return (key);
}