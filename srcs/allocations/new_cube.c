/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_cube.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:22:20 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/05 15:46:46 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shape.h>
#include <stdlib.h>
#include <aux.h>

t_cu			*rt_new_cube(const t_vec3 pos, const t_vec3 dir, const double height,
		const t_color_precision color)
{
	t_cu		*cu;

	if (!(cu = ft_calloc(sizeof(t_cu), 1)))
		return (NULL);
	cu->color = color;
	cu->pos = pos;
	cu->dir = dir;
	cu->height = height;
	return (cu);
}
