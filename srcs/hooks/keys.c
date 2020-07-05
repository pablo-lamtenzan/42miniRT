/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 19:13:39 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/05 16:14:39 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <allocations.h>
#include <stdio.h>
#include <hooks.h>
#include <aux.h>


char			*get_obj_type(const int id)
{
	char		*types[11] = {};

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
	int			keylist[18] = {};
	int			i;

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
	return (swicth_cam_or_obj_fill1(key, s));
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
	if (key == 32)
		s->threads = s->threads != 1 ? 1 : 8;
	if (key_normal(key, s) == -1)
		return (key);
	mlx_destroy_image(s->image->mlx, s->image->img);
	s->image->img = NULL;
	calc_image_hooks(s);
	return (key);
}
