/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 14:54:26 by user42            #+#    #+#             */
/*   Updated: 2020/07/01 15:03:57 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <stdlib.h>
#include <pthread.h>

t_vec3                  pixel_add_hooks(t_scene *s, double t, t_obj near, t_light l)
{
    t_vec3              x;
    t_vec3              y;
    t_vec3              z;

    x = scale_color_vec3(l.color, color_preci_to_vec3(near.color));
    y = vec_scale(x, l.intensity);
    z = normalise(vec_sub(l.pos, s->p));
    x = vec_scale(y, dot(z, s->n));
    return (vec_div(x, t));
}

t_color_precision       calc_light_hooks(t_scene *s, t_obj *near, t_ray r)
{
    t_vec3              pixel;
    t_light             *light[2];
    double              t2;
    
	light[1] = s->lights->start;
    pixel = vec_scale(vec_div(vec_add(color_preci_to_vec3(near->color), \
			color_preci_to_vec3(s->amb_color)), 2), s->amb_intensity);
    while (s->lights)
    {
        r.dir = normalise(vec_sub(s->lights->pos, s->p));
        r.pos = vec_add(s->p, vec_scale(r.dir, 0.0001));
        t2 = norm_vec3(vec_sub(s->lights->pos, s->p));
        light[0] = s->lights;
        pixel = vec_add(pixel, pixel_add_hooks(s, t2, *near, *light[0]));
        s->lights = s->lights->next;
    }
    s->lights = light[1];
    return (minmax_simple(pixel));
}

t_color_precision       get_color_hooks(t_scene *s, t_ray r)
{
    t_obj               *near;

    if (check_obj_collision(s, &near, r) == true)
        return (calc_light_hooks(s, near, r));
    return (set_color_precision(0x0, 0x0, 0x0));
}

t_color_precision   set_ray_hooks(t_scene *s, t_color_precision c, int x, int y)
{
    t_ray           r;
    
    r.dir.x = (double)x - s->image->max_w / 2;
    r.dir.y = (double)y - s->image->max_h / 2;
    r.dir.z = -s->image->max_w / (2 * tan(s->cams->fov / 2));
    r.dir = normalise(rotv(r.dir, s->cams->dir));
    c = add_colors(c, get_color_hooks(s, r));
    return (c);
}

void		pixelize(t_scene *s, int x, int y)
{
	if ((s->image->max_h - y) * s->image->max_w + x < s->image->max_w * s->image->max_h)
		s->image->buff[(s->image->max_h - y) * s->image->max_w + x] = s->image->buff[(s->image->max_h - y - 1) * s->image->max_w + x];
	if ((s->image->max_h - y + 1) * s->image->max_w + x < s->image->max_w * s->image->max_h)
		s->image->buff[(s->image->max_h - y + 1) * s->image->max_w + x] = s->image->buff[(s->image->max_h - y - 1) * s->image->max_w + x];
	if ((s->image->max_h - y + 2) * s->image->max_w + x < s->image->max_w * s->image->max_h)
		s->image->buff[(s->image->max_h - y + 2) * s->image->max_w + x] = s->image->buff[(s->image->max_h - y - 1) * s->image->max_w + x];
}

void                *engine_hooks(void *fill)
{
    register int        x;
    register int        y;
    t_color_precision   color;
    t_scene             *s;

    s = (t_scene *)fill;
    y = 0;
    while (y < s->image->max_h)
    {
        x = s->index;
        while (x < s->image->max_w)
        {
            color = set_color_precision(0x0, 0x0, 0x0);
            s->image->buff[(s->image->max_h - y - 1) * s->image->max_w + x] = set_ray_hooks(s, color, x, y);
            pixelize(s, x, y);
            x += NB_PTHREADS;
        }
        y += 4;
    }
    pthread_exit(NULL);
    return (s);
}