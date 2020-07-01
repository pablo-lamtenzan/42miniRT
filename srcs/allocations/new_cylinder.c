/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 14:25:25 by plamtenz          #+#    #+#             */
/*   Updated: 2020/06/26 18:19:04 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shape.h>
#include <stdlib.h>
#include <aux.h>

t_cyl			*rt_new_cyl(t_ray posdir, double height, double d,
		t_color_precision color)
{
	t_cyl	*cyl;

	if (!(cyl = ft_calloc(sizeof(t_cyl), 1)))
		return (NULL);
	cyl->pos = posdir.pos;
	cyl->dir = posdir.dir;
	cyl->height = height;
	cyl->d = d;
	cyl->color = color;
	return (cyl);
}

void			rt_cyl_obj(t_obj *obj, t_cyl *cy)
{
	obj->type = CYLINDER;
	obj->collision = collisions_cylinder;
	obj->get_normal = normal_cylinder;
	obj->target = cy;
	obj->color = cy->color;
}
