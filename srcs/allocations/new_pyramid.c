/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_pyramid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:27:20 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/07 20:12:58 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shape.h>
#include <stdlib.h>
#include <aux.h>

t_py			*rt_new_pyramid(const t_ray posdir, const double base_height,
		const double height, const t_color_precision color)
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
