/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 21:11:03 by user42            #+#    #+#             */
/*   Updated: 2020/07/03 22:02:12 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shape.h>
#include <stdlib.h>
#include <aux.h>

void                free_objs(t_obj *start)
{
    t_obj           *tmp;

    while (start)
    {
        tmp = start;
        start = start->next;
        if (tmp->uvmap)
            mlx_destroy_image(tmp->mlx_ptr, tmp->uvmap->addr);
        if (tmp->target)
            free(tmp->target);
        free(tmp);
    }
}

void                free_lights(t_light *start)
{
    t_light         *tmp;

    while (start)
    {
        tmp = start;
        start = start->next;
        free(tmp);
    }
}

void                free_cams(t_cam *start)
{
    t_cam           *tmp;
    
	tmp = NULL;
    while (start && tmp != start)
    {
        tmp = start;
        start = start->next;
        free(tmp);
		tmp = NULL;
    }
}

void                free_mlx(t_mlx *i)
{
    if (i->img && i->mlx)
        mlx_destroy_image(i->mlx, i->img);
    if (i->win && i->mlx)
        mlx_destroy_window(i->mlx, i->win);
}

void                free_all(t_scene *s)
{
    if (s->objs)
        free_objs(s->objs->start);
    if (s->lights)
        free_lights(s->lights->start);
    //if (s->cams)
    //    free_cams(s->cams->start);
    if (s->image)
        free_mlx(s->image);
    free(s);
	ft_putstr_fd("\033[32m[MINIRT EXIT WITH SUCCESS]\033[0m\n", 1);
    exit(EXIT_SUCCESS);
}