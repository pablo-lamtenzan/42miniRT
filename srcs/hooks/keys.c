/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 21:07:30 by user42            #+#    #+#             */
/*   Updated: 2020/07/01 22:55:00 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <allocations.h>
#include <stdio.h>
#include <hooks.h>
#include <aux.h>

int         switch_cam_or_obj(int key, t_scene *s) // good
{
    if (key == 43) // '+'
	{
		s->cams = s->cams->next;
		ft_putstr_fd("\033[35m SWICHING TO NEXT CAM\033[0m\n", 1);
	}
    else if (key == 65104) // '`'
	{
		s->cams = s->cams->back;
		ft_putstr_fd("\033[35m SWICHING TO BACK CAM\033[0m\n", 1);
	}
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
    if (key == 32) // 'esp'
    {
		ft_putstr_fd("\033[35m UPGRADING QUALITY...\033[0m\n", 1);
        mlx_destroy_image(s->image->mlx, s->image->img);
        s->image->img = NULL;
        mlx_clear_window(s->image->mlx, s->image->win);
		calc_image(s);
		printf("%p\n", s->image->img);
        (void)mlx_put_image_to_window(s->image->mlx, s->image->win, s->image->img, 0, 0);
        return (-1);
    }
    return (key);
}

int         key_hook(int key, void *fill)
{
    t_scene *s;

	printf("[keyhook: %d]\n", key);
    s = (t_scene *)fill;
    if (key == XK_Escape) // ESC
        free_all(s);
    switch_cam_or_obj(key, s);
    key_rotation(key, s->objs);
    // key_rotaion_bis(key, s->objs);
    // key atribute (no need i think)
    key_translation(key, s->objs);
    // key effect (no needed)
	if (key == 32)
	{
		s->threads = s->threads != 1 ? 1 : 8;
	}
    if (key_normal(key, s) == -1)
        return (key);
    mlx_destroy_image(s->image->mlx, s->image->img);
    s->image->img = NULL;
    calc_image_hooks(s);
    return (key);
}