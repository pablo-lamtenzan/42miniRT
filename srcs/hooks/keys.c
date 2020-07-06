/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 19:13:39 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/06 22:51:48 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <allocations.h>
#include <stdio.h>
#include <hooks.h>
#include <aux.h>
#include <data.h>

char			*get_obj_type(const int id)
{
	if (id == SPHERE)
		return (O);
	else if (id == SQUARE)
		return (P);
	else if (id == CYLINDER)
		return (Q);
	else if (id == TRIANGLE)
		return (R);
	else if (id == PLANE)
		return (S);
	else if (id == CUBE)
		return (T);
	else if (id == CONE)
		return (U);
	else if (id == PYRAMID)
		return (V);
	return (NULL);
}

static int		key_normal(const int key, void *fill)
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
		(void)mlx_put_image_to_window(s->image->mlx, s->image->win,
				s->image->img, 0, 0);
		return (-1);
	}
	return (key);
}

static bool		is_usseful_key(const int key)
{
	return (key == XK_Escape || key == XK_space || key == XK_plus ||
			key == XK_dead_grave || key == XK_p || key == XK_o ||
			key == XK_a || key == XK_s || key == XK_w ||
			key == XK_d || key == XK_Up || key == XK_Down ||
			key == XK_Right || key == XK_Left || key == XK_m ||
			key == XK_n || key == XK_x || key == XK_z);
}

static int		switch_cam_or_obj(const int key, t_scene *s)
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
	swicth_cam_or_obj_next(key, s);
	swicth_cam_or_obj_back(key, s);
	return (key);
}

int				key_hook(const int key, void *fill)
{
	t_scene *s;

	s = (t_scene *)fill;
	if (is_usseful_key(key) == false)
		return (key);
	if (key == XK_Escape)
		free_all(s);
	switch_cam_or_obj(key, s);
	key_rotation(key, s->objs);
	key_translation(key, s->objs);
	if (key == XK_space)
		s->threads = 8;
	if (key_normal(key, s) == -1)
		return (key);
	mlx_destroy_image(s->image->mlx, s->image->img);
	s->image->img = NULL;
	calc_image_hooks(s);
	return (key);
}
