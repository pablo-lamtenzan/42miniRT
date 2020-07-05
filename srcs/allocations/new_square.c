/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 13:44:01 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/05 15:56:47 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shape.h>
#include <stdlib.h>
#include <aux.h>

t_square			*rt_new_square(const t_vec3 pos, const t_vec3 dir,
		const double height, const t_color_precision color)
{
	t_square		*sq;

	if (!(sq = ft_calloc(sizeof(t_square), 1)))
		return (NULL);
	sq->pos = pos;
	sq->dir = dir;
	sq->height = height;
	sq->color = color;
	map_square(sq);
	return (sq);
}

void				rt_square_obj(t_obj *obj, t_square *sq)
{
	obj->type = SQUARE;
	obj->collision = collisions_square;
	obj->get_normal = normal_square;
	obj->target = sq;
	obj->color = sq->color;
}
