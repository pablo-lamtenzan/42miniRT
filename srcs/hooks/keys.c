/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 21:07:30 by user42            #+#    #+#             */
/*   Updated: 2020/07/02 23:03:02 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <allocations.h>
#include <stdio.h>
#include <hooks.h>
#include <aux.h>

char		*get_obj_type(int id)
{
	char	*types[11] = {};

	types[0] = "";
	types[1] = "";
	types[2] = "TYPE = SPHERE\n";
	types[3] = "TYPE = SQUARE\n";
	types[4] = "TYPE = CYLINDER\n";
	types[5] = "TYPE = TRIANGLE\n";
	types[6] = "TYPE = PLANE\n";
	types[7] = "TYPE = CUBE\n";
	types[8] = "TYPE = CONE\n";
	types[9] = "TYPE = PYRAMID\n";
	types[10] = "";
	return (types[id]);
}

int         switch_cam_or_obj(int key, t_scene *s) // good
{
    if (key == XK_plus)
	{
		s->cams = s->cams->next;
		ft_putstr_fd("\033[35m SWICHING TO NEXT CAM\033[0m\n", 1);
	}
    else if (key == XK_dead_grave)
	{
		s->cams = s->cams->back;
		ft_putstr_fd("\033[35m SWICHING TO BACK CAM\033[0m\n", 1);
	}
    else if (key == XK_p)
	{
		
		if (s->objs->next && ((t_obj *)s->objs->next)->cmp == CUBE)
			((t_obj *)s->objs->next)->type = CUBE;
		if (s->objs->type == CUBE)
		{
			if (s->objs->next && ((t_obj *)s->objs->next)->next &&
					((t_obj *)((t_obj *)s->objs->next)->next)->next &&
					((t_obj *)((t_obj *)((t_obj *)s->objs->next)->next)->next)->next &&
					((t_obj *)((t_obj *)((t_obj *)((t_obj *)s->objs->next)->next)->next)->next)->next &&
					((t_obj *)((t_obj *)((t_obj *)((t_obj *)((t_obj *)s->objs->next)->next)->next)->next)->next)->next)
			{
				s->objs = ((t_obj *)((t_obj *)((t_obj *)((t_obj *)((t_obj *)s->objs->next)->next)->next)->next)->next)->next;
				ft_putstr_fd("\033[35m SWICHING TO NEXT SHAPE\033[0m\n", 1);
				ft_putstr_fd(get_obj_type(s->objs->type), 1);
			}
			else
				ft_putstr_fd("\033[35m THERE'S NO MORE NEXT SHAPES\033[0m\n", 1);
		}
		if (s->objs->next && ((t_obj *)s->objs->next)->cmp == PYRAMID)
			((t_obj *)s->objs->next)->type = PYRAMID;
		else if (s->objs->cmp == PYRAMID)
		{
			s->objs->type = PYRAMID;
			if (s->objs->next && ((t_obj *)s->objs->next)->next &&
					((t_obj *)((t_obj *)s->objs->next)->next)->next &&
					((t_obj *)((t_obj *)((t_obj *)s->objs->next)->next)->next)->next &&
					((t_obj *)((t_obj *)((t_obj *)((t_obj *)s->objs->next)->next)->next)->next)->next)
			{
				s->objs = ((t_obj *)((t_obj *)((t_obj *)((t_obj *)s->objs->next)->next)->next)->next)->next;
				ft_putstr_fd("\033[35m SWICHING TO NEXT SHAPE\033[0m\n", 1);
				ft_putstr_fd(get_obj_type(s->objs->type), 1);
			}
			else
				ft_putstr_fd("\033[35m THERE'S NO MORE NEXT SHAPES\033[0m\n", 1);
		}
		else if (s->objs->type == CYLINDER)
		{
			if ((t_obj *)s->objs->next && (t_obj *)((t_obj *)s->objs->next)->next 
					&& (t_obj *)((t_obj *)((t_obj *)s->objs->next)->next)->next)
			{
				s->objs = (t_obj *)((t_obj *)((t_obj *)s->objs->next)->next)->next;
				ft_putstr_fd("\033[35m SWICHING TO NEXT SHAPE\033[0m\n", 1);
				ft_putstr_fd(get_obj_type(s->objs->type), 1);
			}
			else
				ft_putstr_fd("\033[35m THERE'S NO MORE NEXT SHAPES\033[0m\n", 1);
		}
		else if (s->objs->next)
		{
        	s->objs = s->objs->next;
			
			ft_putstr_fd("\033[35m SWICHING TO NEXT SHAPE\033[0m\n", 1);
			ft_putstr_fd(get_obj_type(s->objs->type), 1);
		}
		else
			ft_putstr_fd("\033[35m THERE'S NO MORE NEXT SHAPES\033[0m\n", 1);
	}
    else if (key == XK_o)
	{
		if (s->objs->back && ((t_obj *)s->objs->back)->cmp == CUBE)
		{
			if (s->objs->back && ((t_obj *)s->objs->back)->back &&
					((t_obj *)((t_obj *)s->objs->back)->back)->back &&
					((t_obj *)((t_obj *)((t_obj *)s->objs->back)->back)->back)->back &&
					((t_obj *)((t_obj *)((t_obj *)((t_obj *)s->objs->back)->back)->back)->back)->back &&
					((t_obj *)((t_obj *)((t_obj *)((t_obj *)((t_obj *)s->objs->back)->back)->back)->back)->back)->back)
			{
				s->objs = ((t_obj *)((t_obj *)((t_obj *)((t_obj *)((t_obj *)s->objs->back)->back)->back)->back)->back)->back;
				ft_putstr_fd("\033[35m SWICHING TO BACK SHAPE\033[0m\n", 1);
				ft_putstr_fd(get_obj_type(s->objs->type), 1);
			}
			else if (key == XK_p)
				ft_putstr_fd("\033[35m THERE'S NO MORE NEXT SHAPES\033[0m\n", 1);
		}
		else if (s->objs->back && ((t_obj *)s->objs->back)->cmp == PYRAMID)
		{
			if (s->objs->back && ((t_obj *)s->objs->back)->back &&
					((t_obj *)((t_obj *)s->objs->back)->back)->back &&
					((t_obj *)((t_obj *)((t_obj *)s->objs->back)->back)->back)->back &&
					((t_obj *)((t_obj *)((t_obj *)((t_obj *)s->objs->back)->back)->back)->back)->back)
			{
				s->objs = ((t_obj *)((t_obj *)((t_obj *)((t_obj *)s->objs->back)->back)->back)->back)->back;
				ft_putstr_fd("\033[35m SWICHING TO NEXT SHAPE\033[0m\n", 1);
				ft_putstr_fd(get_obj_type(s->objs->type), 1);
			}
			else if (key == XK_o)
				ft_putstr_fd("\033[35m THERE'S NO MORE NEXT SHAPES\033[0m\n", 1);
		}
		else if (s->objs->type == CYLINDER)
		{
			if ((t_obj *)s->objs->back && (t_obj *)((t_obj *)s->objs->back)->back 
					&& (t_obj *)((t_obj *)((t_obj *)s->objs->back)->back)->back)
			{
				s->objs = (t_obj *)((t_obj *)((t_obj *)s->objs->back)->back)->back;
				ft_putstr_fd("\033[35m SWICHING TO NEXT SHAPE\033[0m\n", 1);
				ft_putstr_fd(get_obj_type(s->objs->type), 1);
			}
			else
				ft_putstr_fd("\033[35m THERE'S NO MORE NEXT SHAPES\033[0m\n", 1);
		}
		else if (s->objs->back)
		{
        	s->objs = s->objs->back;
			ft_putstr_fd("\033[35m SWICHING TO BACK SHAPE\033[0m\n", 1);
			ft_putstr_fd(get_obj_type(s->objs->type), 1);
		}
		else if (key == XK_o)
			ft_putstr_fd("\033[35m CAN'T GO BACK MORE THIS IS THE FIRST SHAPE\033[0m\n", 1);
	}
    return (key);
}

int         key_normal(int key, void *fill)
{
    t_scene *s;

    s = (t_scene *)fill;
    if (key == XK_space)
    {
		ft_putstr_fd("\033[35m UPGRADING QUALITY...\033[0m\n", 1);
        mlx_destroy_image(s->image->mlx, s->image->img);
        s->image->img = NULL;
        mlx_clear_window(s->image->mlx, s->image->win);
		calc_image(s);
		printf("%p\n", s->image->img);
        (void)mlx_put_image_to_window(s->image->mlx, s->image->win, s->image->img, 0, 0);
        return (-1);
    }
    return (key);
}

bool		is_usseful_key(int key)
{
	int		keylist[18] = {};
	int		i;

	keylist[0] = XK_Escape;
	keylist[1] = XK_space;
	keylist[2] = XK_plus;
	keylist[3] = XK_dead_grave;
	keylist[4] = XK_p;
	keylist[5] = XK_o;
	keylist[6] = XK_a;
	keylist[7] = XK_s;
	keylist[8] = XK_w;
	keylist[9] = XK_d;
	keylist[10] = XK_Up;
	keylist[11] = XK_Down;
	keylist[12] = XK_Right;
	keylist[13] = XK_Left;
	keylist[14] = XK_m;
	keylist[15] = XK_n;
	keylist[16] = XK_x;
	keylist[17] = XK_z;
	i = -1;
	while(++i < 18)
		if (key == keylist[i])
			return (true);
	return (false);
}

int         key_hook(int key, void *fill)
{
    t_scene *s;

	printf("[keyhook: %d]\n", key);
    s = (t_scene *)fill;
	if (is_usseful_key(key) == false)
		return (key);
    if (key == XK_Escape) // ESC
        free_all(s);
    switch_cam_or_obj(key, s);
    key_rotation(key, s->objs);
    // key_rotaion_bis(key, s->objs);
    // key atribute (no need i think)
    key_translation(key, s->objs);
    // key effect (no needed)
	if (key == 32)
	{
		s->threads = s->threads != 1 ? 1 : 8;
	}
    if (key_normal(key, s) == -1)
        return (key);
    mlx_destroy_image(s->image->mlx, s->image->img);
    s->image->img = NULL;
    calc_image_hooks(s);
    return (key);
}