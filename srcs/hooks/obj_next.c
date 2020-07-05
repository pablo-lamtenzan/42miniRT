/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_next.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 19:52:37 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/05 23:10:10 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <allocations.h>
#include <hooks.h>
#include <aux.h>

static int		swicth_cam_or_obj_fill2(const int key, t_scene *s)
{
	if (s->objs->type == CUBE)
	{
		if (s->objs->next && ((t_obj *)s->objs->next)->next &&
				((t_obj *)((t_obj *)s->objs->next)->next)->next &&
				((t_obj *)((t_obj *)(\
				(t_obj *)s->objs->next)->next)->next)->next &&
				((t_obj *)((t_obj *)(\
				(t_obj *)(\
				(t_obj *)s->objs->next)->next)->next)->next)->next /*&&
				((t_obj *)((t_obj *)((t_obj *)((t_obj *)(\
				(t_obj *)s->objs->next)->next)->next)->next)->next)->next*/)
		{
			
			/*s->objs = ((t_obj *)((t_obj *)((t_obj *)((t_obj *)(\
					(t_obj *)s->objs->next)->next)->next)->next)->next)->next;*/
			s->objs = ((t_obj *)((t_obj *)(\
				(t_obj *)(\
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

static int		swicth_cam_or_obj_fill3(const int key, t_scene *s)
{
	if (s->objs->cmp == PYRAMID)
	{
		s->objs->type = PYRAMID;
		if (s->objs->next && ((t_obj *)s->objs->next)->next &&
				((t_obj *)((t_obj *)s->objs->next)->next)->next &&
				((t_obj *)((t_obj *)(\
				(t_obj *)s->objs->next)->next)->next)->next /*&&
				((t_obj *)((t_obj *)((t_obj *)(\
					(t_obj *)s->objs->next)->next)->next)->next)->next*/)
		{
			/*s->objs = ((t_obj *)(\
					(t_obj *)((t_obj *)(\
					(t_obj *)s->objs->next)->next)->next)->next)->next;*/
			s->objs = ((t_obj *)((t_obj *)(\
				(t_obj *)s->objs->next)->next)->next)->next;
			ft_putstr_fd("\033[35m SWICHING TO NEXT SHAPE\033[0m\n", 1);
			ft_putstr_fd(get_obj_type(s->objs->type), 1);
		}
		else
			ft_putstr_fd("\033[35m THERE'S NO MORE NEXT \
					SHAPES\033[0m\n", 1);
	}
	return (key);
}

static int		swicth_cam_or_obj_fill4(const int key, t_scene *s)
{
	if (s->objs->type == CYLINDER)
	{
		if ((t_obj *)s->objs->next && (t_obj *)(\
		(t_obj *)s->objs->next)->next /*&& (t_obj *)(\
				(t_obj *)(\
				(t_obj *)s->objs->next)->next)->next*/)
		{
			/*s->objs = (t_obj *)((t_obj *)(\
					(t_obj *)s->objs->next)->next)->next;*/
			s->objs = (t_obj *)(\
		(t_obj *)s->objs->next)->next;
			ft_putstr_fd("\033[35m SWICHING TO NEXT \
					SHAPE\033[0m\n", 1);
			ft_putstr_fd(get_obj_type(s->objs->type), 1);
		}
		else
			ft_putstr_fd("\033[35m THERE'S NO MORE NEXT \
				SHAPES\033[0m\n", 1);
	}
	return (key);
}

#include <stdio.h>

int				swicth_cam_or_obj_next(const int key, t_scene *s)
{
	if (key == XK_p)
	{
		if (s->objs->next)
		{
			if (((t_obj *)s->objs->next)->cmp == CUBE)
				((t_obj *)s->objs->next)->type = CUBE;
			if (((t_obj *)s->objs->next)->cmp == PYRAMID)
				((t_obj *)s->objs->next)->type = PYRAMID;
			// only first elem has type == CUBE / PYRAMID
			// have to handle a PYRAMID following a CUBE AND VICEVERSA
			// Segfault at the end
			printf("[%d]\n",((t_obj *)s->objs->next)->type);
			if (s->objs->type != PYRAMID && s->objs->type != CUBE
					&& s->objs->type != CYLINDER)
			{
				s->objs = s->objs->next;
				ft_putstr_fd("Goes next normal\n", 1);
			}
			else
			{
				while (s->objs->next)
				{
					if (((t_obj *)s->objs->next)->type == DISK || ((t_obj *)s->objs->next)->cmp == CUBE
							|| ((t_obj *)s->objs->next)->cmp == PYRAMID)
						{
							s->objs = s->objs->next;
							printf("[type in while: %d]\n",s->objs->type);
							printf("[type of next in while: %d]\n",((t_obj *)s->objs->next)->type);
						}
					else if (s->objs->next)
					{
						s->objs = s->objs->next;
						ft_putstr_fd("Goes next cmp \n", 1);
						return (key);
					}
				}	
				if (!s->objs->next && (s->objs->type == CUBE
						|| s->objs->type == PYRAMID || s->objs->type == DISK))
					ft_putstr_fd("No next cmp\n", 1);
				else
					ft_putstr_fd("Goes next cmp\n", 1);
			}
		}
		else
			ft_putstr_fd("No next\n", 1);
	}
	return (key);
}

int				swicth_cam_or_obj_back(const int key, t_scene *s)
{
	if (key == XK_o)
	{
		if (s->objs->back)
		{
			// interaction cube cyl works bad
			// cube + pyramid fails too
			printf("[%d]\n",((t_obj *)s->objs->back)->cmp);
			if (((t_obj *)s->objs->back)->type != DISK
					&& ((t_obj *)s->objs->back)->cmp != CUBE
					&& ((t_obj *)s->objs->back)->cmp != PYRAMID)
			{
				s->objs = s->objs->back;
				ft_putstr_fd("Goes back normal\n", 1);
			}
			else
			{
				while (s->objs->back)
				{
					if (s->objs->type == CUBE
							&& ((t_obj *)s->objs->back)->type != CUBE)
					{
						ft_putstr_fd("Going cube cmp\n", 1);
						return (key);
					}
					if (s->objs->type == PYRAMID
							&& ((t_obj *)s->objs->back)->type != PYRAMID)
					{
						ft_putstr_fd("Going pyramid cmp\n", 1);
						return (key);
					}
					if (s->objs->type == CYLINDER)
					{
						ft_putstr_fd("Going back to cyl\n", 1);
						return (key);
					}
					// check this condition and read all well before start
					if (((t_obj *)s->objs->back)->type == DISK
						|| ((t_obj *)s->objs->back)->cmp == CUBE
						|| ((t_obj *)s->objs->back)->cmp == PYRAMID)
					s->objs = s->objs->back;
				}
				if (!s->objs->back)
					ft_putstr_fd("Can't go back cmp\n", 1);
			}
		}
		else
			ft_putstr_fd("Theres no back", 1);
	}
	return (key);
}

int				swicth_cam_or_obj_fill1_2(const int key, t_scene *s)
{
	if (key == XK_p)
	{
		if (s->objs->next && ((t_obj *)s->objs->next)->cmp == CUBE)
			((t_obj *)s->objs->next)->cmp = CUBE;
		swicth_cam_or_obj_fill2(key, s);
		if (s->objs->next && ((t_obj *)s->objs->next)->type == PYRAMID)
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
		else if (!s->objs->next)
			ft_putstr_fd("\033[35m THERE'S NO MORE NEXT \
					SHAPES\033[0m\n", 1);
	}
	swicth_cam_or_obj_fill5(key, s);
	return (key);
}
