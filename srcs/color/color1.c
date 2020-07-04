/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:52:21 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/04 14:54:19 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>

t_color_precision			set_color_precision(double b, double g, double r)
{
	t_color_precision		color;

	color.b = b;
	color.g = g;
	color.r = r;
	color.a = 0x0;
	return (color);
}

t_vec3						color_preci_to_vec3(t_color_precision c)
{
	t_vec3					v;

	v.x = c.r;
	v.y = c.g;
	v.z = c.b;
	return (v);
}

t_vec3						scale_color_vec3(t_color_precision c, t_vec3 v)
{
	v.x *= c.r;
	v.y *= c.g;
	v.z *= c.b;
	return (v);
}

t_vec3						set_color_vec3(double r, double g, double b)
{
	t_vec3					c;

	c.x = b;
	c.y = g;
	c.z = r;
	return (c);
}

t_color_precision			add_colors(t_color_precision c1,
		t_color_precision c2)
{
	c1.r += c2.b;
	c1.g += c2.g;
	c1.b += c2.r;
	return (c1);
}
