/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_pyramid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:27:20 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/04 14:27:22 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shape.h>
#include <stdlib.h>
#include <aux.h>

t_py			*rt_new_pyramid(t_ray posdir, double base_height, double height,
		t_color_precision color)
{
	t_py		*py;

	if (!(py = ft_calloc(sizeof(t_py), 1)))
		return (NULL);
	py->color = color;
	py->pos = posdir.pos;
	py->dir = posdir.dir;
	py->base_height = base_height;
	py->height = height;
	return (py);
}
