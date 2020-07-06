/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 19:57:10 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/06 22:43:26 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <allocations.h>
#include <stdio.h>
#include <hooks.h>
#include <aux.h>

static int		swicth_cam_or_obj_back_fill(const int key, t_scene *s)
{
	while (s->objs->back)
	{
		if (s->objs->type == CUBE || s->objs->type == PYRAMID
				|| s->objs->type == CYLINDER)
		{
			ft_putstr_fd(get_obj_type(s->objs->type), 1);
			return (key);
		}
		if (((t_obj *)s->objs->back)->type == DISK
				|| ((t_obj *)s->objs->back)->type == CYLINDER
				|| ((t_obj *)s->objs->back)->cmp == CUBE
				|| ((t_obj *)s->objs->back)->cmp == PYRAMID)
			s->objs = s->objs->back;
	}
	return (key);
}

int				swicth_cam_or_obj_back(const int key, t_scene *s)
{
	if (key == XK_o)
	{
		if (s->objs->back)
		{
			if (((t_obj *)s->objs->back)->type != DISK
					&& ((t_obj *)s->objs->back)->cmp != CUBE
					&& ((t_obj *)s->objs->back)->cmp != PYRAMID)
			{
				s->objs = s->objs->back;
				ft_putstr_fd("\033[35m MOVING TO BACK SHAPE\033[0m\n", 1);
				ft_putstr_fd(get_obj_type(s->objs->type), 1);
			}
			else
			{
				swicth_cam_or_obj_back_fill(key, s);
				if (!s->objs->back)
					ft_putstr_fd("\033[35m MOVING TO BACK SHAPE\033[0m\n", 1);
			}
		}
		else
			ft_putstr_fd("\033[35m CAN'T MOVE BACK MORE\033[0m\n", 1);
	}
	return (key);
}
