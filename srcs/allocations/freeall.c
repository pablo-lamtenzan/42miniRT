/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:19:04 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/06 21:18:33 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shape.h>
#include <stdlib.h>
#include <aux.h>

static void			free_objs(t_obj *start)
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

static void			free_lights(t_light *start)
{
	t_light			*tmp;

	while (start)
	{
		tmp = start;
		start = start->next;
		free(tmp);
	}
}

static void			free_cams(t_cam *start)
{
	t_cam			*tmp;
	t_cam			*tmp2;

	if (start->next && start->next != start)
	{
		start = start->next;
		tmp2 = start->start;
		while (start && start != start->start)
		{
			tmp = start;
			start = start->next;
			free(tmp);
		}
	}
	if (start == NULL && tmp2)
		free(tmp2);
	if (start && start->start)
		free(start->start);
}

static void			free_mlx(t_mlx *i)
{
	if (i->img && i->mlx)
		mlx_destroy_image(i->mlx, i->img);
	if (i->win && i->mlx)
		mlx_destroy_window(i->mlx, i->win);
	free(i->mlx);
	free(i);
}

void				free_all(t_scene *s)
{
	if (!s)
		return ;
	if (s->objs && s->objs->start)
		free_objs(s->objs->start);
	if (s->lights)
		free_lights(s->lights->start);
	if (s->cams)
		free_cams(s->cams->start);
	if (s->image)
		free_mlx(s->image);
	free(s);
	ft_putstr_fd("\n\033[32m[MINIRT EXIT WITH SUCCESS]\033[0m\n", 1);
	exit(EXIT_SUCCESS);
}
