/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:54:34 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/04 14:56:26 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <stdlib.h>

t_color					precision_to_rgb(t_scene *s, t_color_precision c)
{
	t_color				col;

	col.chanel.r = fmax(0x0, fmin(0xff, c.r));
	col.chanel.g = fmax(0x0, fmin(0xff, c.g));
	col.chanel.b = fmax(0x0, fmin(0xff, c.b));
	col.chanel.a = 0x0;
	return (filter(s, col));
}

void					copy_buff(t_scene *s)
{
	int					i;

	i = -1;
	while (++i < s->image->max_w * s->image->max_h)
		s->image->end_buff[i] = precision_to_rgb(s, s->image->buff[i]);
	free(s->image->buff);
}

t_color_precision		minmax(t_vec3 v, double aa)
{
	t_color_precision	c;

	c.r = fmax(0x0, fmin(0xff, v.z)) / aa;
	c.g = fmax(0x0, fmin(0xff, v.y)) / aa;
	c.b = fmax(0x0, fmin(0xff, v.x)) / aa;
	return (c);
}

t_color_precision		minmax_simple(t_vec3 v)
{
	t_color_precision	c;

	c.r = fmax(0x0, fmin(0xff, v.z));
	c.g = fmax(0x0, fmin(0xff, v.y));
	c.b = fmax(0x0, fmin(0xff, v.x));
	return (c);
}

t_color					set_color(double b, double g, double r)
{
	t_color				c;

	c.chanel.r = r;
	c.chanel.g = g;
	c.chanel.b = b;
	c.chanel.a = 0x0;
	return (c);
}
