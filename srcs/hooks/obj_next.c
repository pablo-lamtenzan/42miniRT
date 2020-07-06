/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_next.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 19:52:37 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/06 22:47:07 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <allocations.h>
#include <hooks.h>
#include <aux.h>

static int		swicth_cam_or_obj_next_fill(const int key, t_scene *s)
{
	while (s->objs->next)
	{
		if (((t_obj *)s->objs->next)->type == DISK
				|| ((t_obj *)s->objs->next)->cmp == CUBE
				|| ((t_obj *)s->objs->next)->cmp == PYRAMID)
		{
			s->objs = s->objs->next;
			if (s->objs->next && (((t_obj *)s->objs->next)->type == CUBE
				|| ((t_obj *)s->objs->next)->type == PYRAMID))
			{
				s->objs = s->objs->next;
				return (key);
			}
		}
		else if (s->objs->next)
		{
			s->objs = s->objs->next;
			ft_putstr_fd("\033[35m MOVING TO NEXT SHAPE\033[0m\n", 1);
			ft_putstr_fd(get_obj_type(s->objs->type), 1);
			return (key);
		}
	}
	return (key);
}

int				swicth_cam_or_obj_next(const int key, t_scene *s)
{
	if (key == XK_p)
	{
		if (s->objs->next)
		{
			if (s->objs->type != PYRAMID && s->objs->type != CUBE
					&& s->objs->type != CYLINDER)
			{
				s->objs = s->objs->next;
				ft_putstr_fd("\033[35m MOVING TO NEXT SHAPE\033[0m\n", 1);
				ft_putstr_fd(get_obj_type(s->objs->type), 1);
			}
			else
			{
				swicth_cam_or_obj_next_fill(key, s);
				if (!s->objs->next && (s->objs->cmp == CUBE
						|| s->objs->cmp == PYRAMID || s->objs->type == DISK)
						&& (s->objs = s->objs->start))
					ft_putstr_fd("\033[35m GOING TO START\033[0m\n", 1);
			}
		}
		else
			ft_putstr_fd("\033[35m CAN'T MOVE NEXT FURTHER\033[0m\n", 1);
	}
	return (key);
}
