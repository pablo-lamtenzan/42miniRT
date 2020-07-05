/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 19:57:10 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/05 20:51:01 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <allocations.h>
#include <stdio.h>
#include <hooks.h>
#include <aux.h>

#include <stdio.h>

static int		swicth_cam_or_obj_fill6(const int key, t_scene *s)
{
	if (s->objs->back && ((t_obj *)s->objs->back)->cmp == CUBE)
	{
		if (s->objs->back && ((t_obj *)s->objs->back)->back &&
				((t_obj *)((t_obj *)s->objs->back)->back)->back &&
				((t_obj *)((t_obj *)(\
						(t_obj *)s->objs->back)->back)->back)->back &&
				((t_obj *)((t_obj *)(\
				(t_obj *)(\
				(t_obj *)s->objs->back)->back)->back)->back)->back &&
				((t_obj *)((t_obj *)((t_obj *)(\
				(t_obj *)(\
				(t_obj *)s->objs->back)->back)->back)->back)->back)->back)
		{
			s->objs = ((t_obj *)((t_obj *)((t_obj *)(\
					(t_obj *)(\
				(t_obj *)s->objs->back)->back)->back)->back)->back)->back;
			printf("[%p]\n", s->objs);
			ft_putstr_fd("\033[35m SWICHING TO BACK SHAPE\033[0m\n", 1);
			ft_putstr_fd(get_obj_type(s->objs->type), 1);
		}
		else
			ft_putstr_fd("\033[35m THERE'S NO MORE NEXT \
					SHAPES\033[0m\n", 1);
	}
	return (key);
}

static int		swicth_cam_or_obj_fill8(const int key, t_scene *s)
{
	if (s->objs->back && ((t_obj *)s->objs->back)->type == DISK)
	{
		if ((t_obj *)s->objs->back && (t_obj *)(\
				(t_obj *)s->objs->back)->back
				/*&& (t_obj *)((t_obj *)(\
				(t_obj *)s->objs->back)->back)->back*/)
		{
			/*s->objs = (t_obj *)((t_obj *)(\
				(t_obj *)s->objs->back)->back)->back;*/
			s->objs = (t_obj *)(\
				(t_obj *)s->objs->back)->back;
			ft_putstr_fd("\033[35m SWICHING TO BACK SHAPE\033[0m\n", 1);
			ft_putstr_fd(get_obj_type(s->objs->type), 1);
		}
		else
			ft_putstr_fd("\033[35m THERE'S NO MORE NEXT \
				SHAPES\033[0m\n", 1);
	}
	return (key);
}

static int		swicth_cam_or_obj_fill7(const int key, t_scene *s)
{
	if (s->objs->back && ((t_obj *)s->objs->back)->cmp == PYRAMID)
	{
		if (s->objs->back && ((t_obj *)s->objs->back)->back &&
				((t_obj *)((t_obj *)s->objs->back)->back)->back &&
				((t_obj *)((t_obj *)(\
				(t_obj *)s->objs->back)->back)->back)->back &&
				((t_obj *)((t_obj *)(\
				(t_obj *)(\
				(t_obj *)s->objs->back)->back)->back)->back)->back)
		{
			s->objs = ((t_obj *)((t_obj *)((t_obj *)\
					((t_obj *)s->objs->back)->back)->back)->back)->back;
			ft_putstr_fd("\033[35m SWICHING TO BACK SHAPE\033[0m\n", 1);
			ft_putstr_fd(get_obj_type(s->objs->type), 1);
		}
		else
			ft_putstr_fd("\033[35m THERE'S NO MORE BACK \
					SHAPES\033[0m\n", 1);
	}
	return (key);
}

int				swicth_cam_or_obj_fill5(const int key, t_scene *s)
{
	if (key == XK_o)
	{
		swicth_cam_or_obj_fill6(key, s);
		swicth_cam_or_obj_fill7(key, s);
		swicth_cam_or_obj_fill8(key, s);
		if (s->objs->back && ((t_obj *)s->objs->back)->cmp != CUBE
				&& ((t_obj *)s->objs->back)->cmp != PYRAMID
				&& ((t_obj *)s->objs->back)->type != DISK)
		{
			s->objs = s->objs->back;
			ft_putstr_fd("\033[35m SWICHING TO BACK SHAPE\033[0m\n", 1);
			ft_putstr_fd(get_obj_type(s->objs->type), 1);
		}
		else if (!s->objs->back)
			ft_putstr_fd("\033[35m CAN'T GO BACK MORE THIS IS THE FIRST \
					SHAPE\033[0m\n", 1);
	}
	return (key);
}
