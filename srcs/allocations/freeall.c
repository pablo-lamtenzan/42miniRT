/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:19:04 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/04 17:11:03 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shape.h>
#include <stdlib.h>
#include <aux.h>

void				free_objs(t_obj *start)
{
	t_obj			*tmp;

	while (start)
	{
		tmp = start;
		start = start->next;
		if (tmp->uvmap)
		{
			mlx_destroy_image(tmp->mlx_ptr, tmp->uvmap->addr);
			free(tmp->uvmap);
		}
		if (tmp->target)
			free(tmp->target);
		free(tmp);
	}
}

void				free_lights(t_light *start)
{
	t_light			*tmp;

	while (start)
	{
		tmp = start;
		start = start->next;
		free(tmp);
	}
}

void				free_cams(t_cam *start)
{
	t_cam			*tmp;

	if (start->next && start->next != start)
	{
		start = start->next;
		while (start != start->start)
		{
			tmp = start;
			start = start->next;
			free(tmp);
		}
	}
	free(start->start);
}

void				free_mlx(t_mlx *i)
{
	if (i->img && i->mlx)
		mlx_destroy_image(i->mlx, i->img);
	if (i->win && i->mlx)
		mlx_destroy_window(i->mlx, i->win);
}

void				free_all(t_scene *s)
{
	if (s->objs)
		free_objs(s->objs->start);
	if (s->lights)
		free_lights(s->lights->start);
	if (s->cams)
		free_cams(s->cams->start);
	if (s->image)
		free_mlx(s->image);
	free(s);
	ft_putstr_fd("\033[32m[MINIRT EXIT WITH SUCCESS]\033[0m\n", 1);
	exit(EXIT_SUCCESS);
}
