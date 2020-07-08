/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 19:02:50 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/07 20:13:31 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <allocations.h>
#include <hooks.h>
#include <aux.h>

void			resize_dir(double *point, double resize)
{
	if (*point + resize > 1)
		*point = -1;
	else if (*point + resize < -1)
		*point = 1;
	else
		*point += resize;
}

int				motion_hook(const int x, const int y, void *fill)
{
	t_scene		*s;
	bool		update;

	s = (t_scene *)fill;
	update = false;
	if (s->mouse < 0)
		return (-1);
	if (x > s->image->max_w / 3 && x < s->image->max_w / 2 && (update = true))
		resize_dir(&s->cams->dir.y, -0.01 * s->mouse);
	else if (x < s->image->max_w / 2 / 3 && (update = true))
		resize_dir(&s->cams->dir.y, 0.01 * s->mouse);
	if (y > s->image->max_h / 3 && y < s->image->max_h / 2 && (update = true))
		resize_dir(&s->cams->dir.x, -0.01 * s->mouse);
	else if (y < s->image->max_h / 2 / 3 && (update = true))
		resize_dir(&s->cams->dir.x, 0.01 * s->mouse);
	if (update == true)
	{
		mlx_destroy_image(s->image->mlx, s->image->img);
		s->image->img = NULL;
		ft_putstr_fd("ROTATING CAM\n", 1);
		calc_image_hooks(s);
	}
	return (0);
}

int				motion_end(void *fill)
{
	t_scene		*s;

	s = (t_scene *)fill;
	free_all(s);
	return (0);
}

static int		mouse_hook_fill(const int key, t_scene *s, bool update)
{
	if (key == 2 && (update = true))
	{
		s->mouse = -s->mouse;
		if (s->mouse > 0)
			ft_putstr_fd("\033[35m CAM ROTATION UP\033[0m\n", 1);
		else
			ft_putstr_fd("\033[35m CAM ROTATION DOWN\033[0m\n", 1);
	}
	else if (key == 3 && s->mouse > 0 && (update = true))
	{
		s->mouse++;
		ft_putstr_fd("\033[35m INCREASING ROT CAM FACTOR\033[0m\n", 1);
	}
	else if (key == 1 && s->mouse > 1 && (update = true))
	{
		s->mouse--;
		ft_putstr_fd("\033[35m DECREASING ROT CAM FACTOR\033[0m\n", 1);
	}
	if (update)
	{
		mlx_destroy_image(s->image->mlx, s->image->img);
		s->image->img = NULL;
		calc_image_hooks(s);
	}
	return (key);
}

int				mouse_hook(const int key, int x, int y, void *fill)
{
	t_scene		*s;
	bool		update;

	s = (t_scene *)fill;
	update = false;
	x += x - x;
	y += y - y;
	if (key == 4 && (update = true))
	{
		s->cams->pos.z += 20;
		ft_putstr_fd("\033[35m ZOOMING IN\033[0m\n", 1);
	}
	else if (key == 5 && (update = true))
	{
		s->cams->pos.z -= 20;
		ft_putstr_fd("\033[35m ZOOMING OUT\033[0m\n", 1);
	}
	return (mouse_hook_fill(key, s, update));
}
