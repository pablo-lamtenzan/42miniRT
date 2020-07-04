/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:28:20 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/04 14:29:07 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <stdlib.h>
#include <aux.h>

t_mlx			*rt_new_image(void)
{
	t_mlx		*new;

	if (!(new = malloc(sizeof(t_mlx))))
		return (NULL);
	new->buff = NULL;
	new->end_buff = NULL;
	new->img = NULL;
	new->max_h = 500;
	new->max_w = 500;
	new->mlx = NULL;
	new->win = NULL;
	return (new);
}

t_scene			*rt_new_scene(void)
{
	t_scene		*new;

	if (!(new = malloc(sizeof(t_scene))))
		return (NULL);
	new->cams = NULL;
	new->filter = 0;
	new->flags = 0;
	new->amb_intensity = 0;
	new->amb_color = set_color_precision(0x0, 0x0, 0x0);
	if (!(new->image = rt_new_image()))
		return (NULL);
	new->index = 0;
	new->lights = NULL;
	new->mouse = -1;
	new->threads = 8;
	new->objs = NULL;
	new->aa = 1;
	new->aarainbow = 0;
	new->filename = NULL;
	if (!(new->image->mlx = mlx_init()))
		return (NULL);
	return (new);
}
