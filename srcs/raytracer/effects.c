/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 15:27:51 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/07 20:14:09 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <shape.h>
#include <stdlib.h>

t_color			filter(t_scene *s, t_color c)
{
	double		tmp;

	if (s->filter == RED || s->filter == GREEN)
		c.chanel.b = 0x0;
	if (s->filter == RED || s->filter == BLUE)
		c.chanel.g = 0x0;
	if (s->filter == GREEN || s->filter == BLUE)
		c.chanel.r = 0x0;
	if (s->filter == SEPIA)
	{
		tmp = c.chanel.r + c.chanel.g + c.chanel.b;
		c.chanel.r = fmax(0x0, fmin(0xFF, tmp / 3 * 1.40));
		c.chanel.g = tmp / 3;
		c.chanel.b = fmax(0x0, fmin(0xFF, tmp / 3 * 0.60));
	}
	return (c);
}

void			checkerboard(t_scene *s, t_obj *obj)
{
	int			i;

	i = 0;
	if (abs((int)((s->p.x + 123456789) / obj->ch)) % 2 == 0)
		++i;
	if (abs((int)((s->p.y + 123456789) / obj->ch)) % 2 == 0)
		++i;
	if (abs((int)((s->p.z + 123456789) / obj->ch)) % 2 == 0)
		++i;
	if (i == 1 || i == 3)
		obj->color = obj->color_damier;
}

void			rainbow(t_scene *s, t_obj *obj)
{
	if ((s->aa > 1 && ++s->aarainbow != 1) &&
			s->aa == s->aarainbow && !(s->aarainbow = 0))
		return ;
	if (obj->rb == -1 && !(obj->rb = 0))
		obj->color = set_color_precision(0xff, 0x0, 0x0);
	if (obj->rb == 0 && (obj->color.g += obj->rainbow) >= 0xff)
		obj->rb = 1;
	else if (obj->rb == 1 && (obj->color.b -= obj->rainbow) <= 0x0)
		obj->rb = 2;
	else if (obj->rb == 2 && (obj->color.r += obj->rainbow) >= 0xff)
		obj->rb = 3;
	else if (obj->rb == 3 && (obj->color.g -= obj->rainbow) <= 0x0)
		obj->rb = 4;
	else if (obj->rb == 4 && (obj->color.b += obj->rainbow) >= 0xff)
		obj->rb = 5;
	else if (obj->rb == 5 && (obj->color.r -= obj->rainbow) <= 0x0)
		obj->rb = -1;
}

void			effect(t_scene *s, t_obj *obj)
{
	if (obj->effect & DAMIER)
		checkerboard(s, obj);
	if (obj->effect & RAINBOW)
		rainbow(s, obj);
	if (obj->type == SPHERE && obj->effect & UVMAPPING)
		obj->color = uvmapping(s, obj);
}

void			pixelize(t_scene *s, const int x, const int y)
{
	if ((s->image->max_h - y) * s->image->max_w + x < s->image->max_w * \
			s->image->max_h)
		s->image->buff[(s->image->max_h - y) * s->image->max_w + x] = \
			s->image->buff[(s->image->max_h - y - 1) * s->image->max_w + x];
	if ((s->image->max_h - y + 1) * s->image->max_w + x < s->image->max_w * \
			s->image->max_h)
		s->image->buff[(s->image->max_h - y + 1) * s->image->max_w + x] = \
				s->image->buff[(s->image->max_h - y - 1) * s->image->max_w + x];
	if ((s->image->max_h - y + 2) * s->image->max_w + x < s->image->max_w * \
			s->image->max_h)
		s->image->buff[(s->image->max_h - y + 2) * s->image->max_w + x] = \
			s->image->buff[(s->image->max_h - y - 1) * s->image->max_w + x];
}
