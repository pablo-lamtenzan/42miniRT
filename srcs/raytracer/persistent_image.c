/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   persistent_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 13:55:12 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/06 22:57:58 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <stdio.h>

static int g_i = XFRAME;

int					draw_in_frames(void *fill)
{
	t_scene			*s;

	s = (t_scene *)fill;
	g_i++;
	if (g_i == XFRAME)
		mlx_put_image_to_window(s->image->mlx, s->image->win, \
			s->image->img, 0, 0);
	if (g_i >= XFRAME)
		g_i = 0;
	return (true);
}
