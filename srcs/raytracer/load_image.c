/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 15:57:25 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/04 16:02:02 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <allocations.h>
#include <pthread.h>
#include <hooks.h>
#include <stdlib.h>
#include <aux.h>
#include <X11/X.h>

t_scene				*copy_structure(t_scene *s)
{
	t_scene			*new;

	if (!(new = malloc(sizeof(t_scene))))
		return (NULL);
	(void)ft_memcpy(new, s, sizeof(t_scene));
	return (new);
}

static bool			start_multithreading(t_scene *s)
{
	pthread_t		threads[s->threads];
	t_scene			*instances[s->threads];
	int				i;

	i = -1;
	while (++i < s->threads)
	{
		if (!(instances[i] = copy_structure(s)))
			return (false);
		instances[i]->index = i;
		if (pthread_create(&threads[i], NULL, engine, instances[i]))
			return (false);
	}
	i = -1;
	while (++i < s->threads)
	{
		if (pthread_join(threads[i], NULL))
			return (false);
		free(instances[i]);
	}
	ft_putstr_fd("\n\n\033[35m==================\n\033[0m", 1);
	ft_putstr_fd("\033[1m\033[32m Drawing ... \033[0m\n", 1);
	ft_putstr_fd("\033[35m==================\033[0m\n", 1);
	return (true);
}

int					calc_image(t_scene *x)
{
	int				tmp;
	t_scene			*s;

	s = (t_scene *)x;
	ft_putstr_fd("\033[35m==================\n\n\033[0m", 1);
	ft_putstr_fd("\033[1m\033[5m Processing Shapes ...  \033[0m\n", 1);
	if (!(s->image->img = mlx_new_image(s->image->mlx, \
				s->image->max_w, s->image->max_h))
			|| !(s->image->end_buff = (t_color *)mlx_get_data_addr(\
				s->image->img, &tmp, &tmp, &tmp))
			|| !(s->image->buff = malloc(s->image->max_w * \
				s->image->max_h * sizeof(t_color_precision)))
			|| start_multithreading(s) == false)
	{
		return (false);
	}
	copy_buff(s);
	return (true);
}

int					test(void *fill)
{
	(void)fill;
	printf("Goes in\n");
	return (true);
}

int					load_image(void *x)
{
	t_scene			*s;

	s = (t_scene *)x;
	if (!(s->image->win = mlx_new_window(s->image->mlx, s->image->max_w, \
			s->image->max_h, "plamtenz's miniRT")) || calc_image(s) == false)
		return (false);
	if (!(s->flags & SAVE))
	{
		//mlx_loop_hook(s->image->mlx, calc_image, s);
		//printf("[%p]\n", s->image->img);
		(void)mlx_put_image_to_window(s->image->mlx, s->image->win, \
				s->image->img, 0, 0);
		mlx_key_hook(s->image->win, key_hook, s);
		mlx_mouse_hook(s->image->win, mouse_hook, s);
		mlx_hook(s->image->win, 6, (1L << 6), motion_hook, s);
		//mlx_hook(s->image->win, VisibilityChangeMask, FocusOut, test, s);
		mlx_hook(s->image->win, DestroyNotify, StructureNotifyMask, \
				motion_end, s);
		mlx_loop(s->image->mlx);
	}
	else
		export_bmp(s);
	return (true);
}
