/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image_hooks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 14:53:35 by user42            #+#    #+#             */
/*   Updated: 2020/07/01 22:01:50 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <hooks.h>
#include <pthread.h>
#include <X11/X.h>

bool			start_multithreading_hooks(t_scene *s)
{
	pthread_t  		threads[NB_PTHREADS];
    t_scene     	*instances[NB_PTHREADS];
    int             i;
    
    i = -1;
    while (++i < s->threads)
    {
        if (!(instances[i] = copy_structure(s)))
            return (false);
        instances[i]->index = i;
        if (pthread_create(&threads[i], NULL, engine_hooks, instances[i]))
            return (false);
    }
    i = -1;
    while (++i < s->threads)
    {
        if (pthread_join(threads[i], NULL))
            return (false);
        free(instances[i]); 
    }
    return (true);
}

bool                calc_image_hooks(t_scene *s)
{
    int 			tmp;

    s->image->max_h /= 2;
    s->image->max_w /= 2;
    if (!(s->image->img = mlx_new_image(s->image->mlx, \
			s->image->max_w, s->image->max_h))
            || !(s->image->end_buff = (t_color *)mlx_get_data_addr( \
			s->image->img, &tmp, &tmp, &tmp))
            || !(s->image->buff = malloc(s->image->max_w * s->image->max_h \
			 * sizeof(t_color_precision)))
			|| start_multithreading_hooks(s) == false)
        return (false);
    copy_buff(s);
    s->image->max_h *= 2;
    s->image->max_w *= 2;
    (void)mlx_put_image_to_window(s->image->mlx, s->image->win, \
		s->image->img, 0, 0);
    mlx_key_hook(s->image->win, key_hook, s);
    mlx_mouse_hook(s->image->win, mouse_hook, s);
    mlx_hook(s->image->win, 6, (1L << 6), motion_hook, s);
    mlx_hook(s->image->win, DestroyNotify, StructureNotifyMask, motion_end, s);
    mlx_loop(s->image->mlx);
    return (true);
}
