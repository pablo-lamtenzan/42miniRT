/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_cube.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 18:34:25 by user42            #+#    #+#             */
/*   Updated: 2020/07/01 14:49:53 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shape.h>
#include <stdlib.h>
#include <aux.h>

t_cu            *rt_new_cube(t_vec3 pos, t_vec3 dir, double height, 
        t_color_precision color)
{
    t_cu        *cu;

    if (!(cu = ft_calloc(sizeof(t_cu), 1)))
        return (NULL);
    cu->color = color;
    cu->pos = pos;
    cu->dir = dir;
    cu->height = height;
    return (cu);
}
