/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 17:40:23 by user42            #+#    #+#             */
/*   Updated: 2020/06/30 15:16:07 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <stdlib.h>
#include <aux.h>

t_obj           *rt_new_obj(int type)
{
    t_obj       *new;
    
    if (!(new = malloc(sizeof(t_obj))))
        return (NULL);
    new->back = NULL;
    new->ch = 0;
    new->collision = NULL;
    new->color = set_color_precision(0x0, 0x0, 0x0);
    new->color_damier = set_color_precision(0x0, 0x0, 0x0);
    new->effect = 0;
    new->get_normal = NULL;
    new->mlx_ptr = NULL;
    new->next = NULL;
    new->rainbow = 0;
    new->rb = -1;
    new->start = NULL;
    new->target = NULL;
    new->texture = set_color_precision(0x0, 0x0, 0x0);
    new->type = type;
    new->uvmap = NULL;
    return (new);
}

t_light        	*rt_new_light(void)
{
    t_light     *new;
    
    if (!(new = malloc(sizeof(t_light))))
        return (NULL);
    new->color = set_color_precision(0x0, 0x0, 0x0);
    new->intensity = 0;
    new->next = NULL;
    new->pos = vec3(0, 0, 0);
    new->start = NULL;
    return (new);
}

t_cam           *rt_new_cam(void)
{
    t_cam       *new;

    if (!(new = malloc(sizeof(t_cam))))
        return (NULL);
    new->back = NULL;
    new->dir = vec3(0, 0, 0);
    new->fov = -1;
    new->next = NULL;
    new->pos = vec3(0, 0, 0);
    new->start = NULL;
    return (new);
}