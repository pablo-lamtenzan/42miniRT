/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_next.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 19:52:37 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/04 20:04:25 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <allocations.h>
#include <stdio.h>
#include <hooks.h>
#include <aux.h>

static int		swicth_cam_or_obj_fill2(int key, t_scene *s)
{
	if (s->objs->type == CUBE)
	{
		if (s->objs->next && ((t_obj *)s->objs->next)->next &&
				((t_obj *)((t_obj *)s->objs->next)->next)->next &&
				((t_obj *)((t_obj *)(\
				(t_obj *)s->objs->next)->next)->next)->next &&
				((t_obj *)((t_obj *)(\
				(t_obj *)(\
				(t_obj *)s->objs->next)->next)->next)->next)->next &&
				((t_obj *)((t_obj *)((t_obj *)((t_obj *)(\
				(t_obj *)s->objs->next)->next)->next)->next)->next)->next)
		{
			s->objs = ((t_obj *)((t_obj *)((t_obj *)((t_obj *)(\
					(t_obj *)s->objs->next)->next)->next)->next)->next)->next;
			ft_putstr_fd("\033[35m SWICHING TO NEXT SHAPE\033[0m\n", 1);
			ft_putstr_fd(get_obj_type(s->objs->type), 1);
		}
		else
			ft_putstr_fd("\033[35m THERE'S NO MORE NEXT \
					SHAPES\033[0m\n", 1);
	}
	return (key);
}

static int		swicth_cam_or_obj_fill3(int key, t_scene *s)
{
	if (s->objs->cmp == PYRAMID)
	{
		s->objs->type = PYRAMID;
		if (s->objs->next && ((t_obj *)s->objs->next)->next &&
				((t_obj *)((t_obj *)s->objs->next)->next)->next &&
				((t_obj *)((t_obj *)(\
				(t_obj *)s->objs->next)->next)->next)->next &&
				((t_obj *)((t_obj *)((t_obj *)(\
					(t_obj *)s->objs->next)->next)->next)->next)->next)
		{
			s->objs = ((t_obj *)(\
					(t_obj *)((t_obj *)(\
					(t_obj *)s->objs->next)->next)->next)->next)->next;
			ft_putstr_fd("\033[35m SWICHING TO NEXT SHAPE\033[0m\n", 1);
			ft_putstr_fd(get_obj_type(s->objs->type), 1);
		}
		else
			ft_putstr_fd("\033[35m THERE'S NO MORE NEXT \
					SHAPES\033[0m\n", 1);
	}
	return (key);
}

static int		swicth_cam_or_obj_fill4(int key, t_scene *s)
{
	if (s->objs->type == CYLINDER)
	{
		if ((t_obj *)s->objs->next && (t_obj *)(\
		(t_obj *)s->objs->next)->next && (t_obj *)(\
				(t_obj *)(\
				(t_obj *)s->objs->next)->next)->next)
		{
			s->objs = (t_obj *)((t_obj *)(\
					(t_obj *)s->objs->next)->next)->next;
			ft_putstr_fd("\033[35m SWICHING TO NEXT \
					SHAPE\033[0m\n", 1);
			ft_putstr_fd(get_obj_type(s->objs->type), 1);
			ft_putstr_fd("\033[35m THERE'S NO MORE NEXT \
					SHAPES\033[0m\n", 1);
		}
	}
	return (key);
}

int				swicth_cam_or_obj_fill1(int key, t_scene *s)
{
	if (key == XK_p)
	{
		if (s->objs->next && ((t_obj *)s->objs->next)->cmp == CUBE)
			((t_obj *)s->objs->next)->type = CUBE;
		swicth_cam_or_obj_fill2(key, s);
		if (s->objs->next && ((t_obj *)s->objs->next)->cmp == PYRAMID)
			((t_obj *)s->objs->next)->type = PYRAMID;
		swicth_cam_or_obj_fill3(key, s);
		swicth_cam_or_obj_fill4(key, s);
		if (s->objs->next && s->objs->type != CYLINDER &&
			s->objs->type != PYRAMID && s->objs->type != CUBE)
		{
			s->objs = s->objs->next;
			ft_putstr_fd("\033[35m SWICHING TO NEXT \
					SHAPE\033[0m\n", 1);
			ft_putstr_fd(get_obj_type(s->objs->type), 1);
		}
		else
			ft_putstr_fd("\033[35m THERE'S NO MORE NEXT \
					SHAPES\033[0m\n", 1);
	}
	swicth_cam_or_obj_fill5(key, s);
	return (key);
}
