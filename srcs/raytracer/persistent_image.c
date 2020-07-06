/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   persistent_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 13:55:12 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/06 16:28:42 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <stdio.h>

int					persistent_image(void *fill)
{
	t_scene 	*s;

	s = (t_scene *)fill;
	(void)s;
	//printf("[mlx: %p]\n", s->image->mlx);
	//printf("[win: %p]\n", s->image->win);
	//printf("[img: %p]\n", s->image->img);
	//printf("[run: %d]\n", s->run);
	mlx_put_image_to_window(s->image->mlx, s->image->win, \
			s->image->img, 0, 0);
	//mlx_destroy_image(s->image->mlx, s->image->img);
	return (true);
}
