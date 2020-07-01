/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_pyramid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 18:25:26 by user42            #+#    #+#             */
/*   Updated: 2020/07/01 14:50:39 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shape.h>
#include <stdlib.h>
#include <aux.h>

t_py            *rt_new_pyramid(t_ray posdir, double base_height, double height,
        t_color_precision color)
{
    t_py        *py;

    if (!(py = ft_calloc(sizeof(t_py), 1)))
        return (NULL);
    py->color = color;
    py->pos = posdir.pos;
    py->dir = posdir.dir;
    py->base_height = base_height;
    py->height = height;
    return (py);
}
