/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uvmapping.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 16:05:42 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/04 16:06:42 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shape.h>

t_color_precision				calc_pixel(int x, int y, t_obj *obj)
{
	int							nb;
	t_color						c;

	if (x >= 0 && x <= obj->uvmap->x - 1 && y > 0 && y <= obj->uvmap->y - 1)
	{
		if ((nb = (obj->uvmap->x * obj->uvmap->y) - \
				(obj->uvmap->x * y - x)) < 0)
			nb = 0;
		c = obj->uvmap->img[nb];
		return (set_color_precision(c.chanel.b, c.chanel.g, c.chanel.r));
	}
	return (set_color_precision(0xff, 0xff, 0xff));
}

t_color_precision				uvmapping(t_scene *s, t_obj *obj)
{
	double						u;
	double						v;
	t_vec3						vec[3];

	vec[0] = normalise(vec_sub(s->p, ((t_sphere *)obj->target)->pos));
	vec[1] = normalise(vec3(0, 0, -(((t_sphere *)obj->target)->d / 2)));
	vec[2] = normalise(vec3(0, ((t_sphere *)obj->target)->d / 2, 0));
	v = acos(dot(vec[2], vec[0])) / M_PI;
	u = (acos(dot(vec[0], vec[1]) / sin(v * M_PI))) / (2 * M_PI);
	u = dot(cross_product(vec[2], vec[1]), vec[0]) <= 0 ? 1 - u : u;
	u *= obj->uvmap->x;
	v *= obj->uvmap->y;
	return (calc_pixel((int)u % obj->uvmap->x, (int)v % obj->uvmap->y, obj));
}
