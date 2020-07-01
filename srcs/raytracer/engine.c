/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 19:31:58 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/01 22:02:40 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <stdlib.h>
#include <pthread.h>
#include <aux.h>

t_vec3                      pixel_add(t_scene *s, double t, t_obj near, t_light l)
{
    t_vec3                  x;
    t_vec3                  y;
    t_vec3                  z;

    if (near.effect & DAMIER)
        damier(s, &near);
    x = scale_color_vec3(l.color, color_preci_to_vec3(near.color));
    y = vec_scale(x, l.intensity);
    z = normalise(vec_sub(l.pos, s->p));
    x = vec_scale(y, dot(z, s->n));
    return (vec_div(x, t));
}

t_color_precision           calc_light(t_scene *s, t_obj *near, t_ray ray)
{
    t_vec3                  pixel;
    t_light                 *light[2];
    bool                    illuminated;
    double                  t1;
    double                  t2;

	light[1] = s->lights->start;
    if (near->effect && !(near->effect & DAMIER))
        effect(s, near);
    pixel = vec_scale(vec_div(vec_add(color_preci_to_vec3(near->color), \
			color_preci_to_vec3(s->amb_color)), 2), s->amb_intensity);
    while (s->lights)
    {
        ray.dir = normalise(vec_sub(s->lights->pos, s->p));
        ray.pos = vec_add(s->p, vec_scale(ray.dir, 0.0001));
        illuminated = check_light_collision(s, &t1, ray);
        t2 = norm_vec3(vec_sub(s->lights->pos, s->p));
        t1 *= t1;
        light[0] = s->lights;
        if (!(illuminated && t1 < t2))
            pixel = vec_add(pixel, pixel_add(s, t2, *near, *light[0]));
        s->lights = s->lights->next;
    }
    s->lights = light[1];
    return (minmax(pixel, s->aa));
}

t_color_precision           get_color(t_scene *s, t_ray ray, int total_rebound)
{
    t_color_precision       color;
    t_obj                   *near;
    t_ray                   m;

    color = set_color_precision(0x0, 0x0, 0x0);
    if (total_rebound > 0 && check_obj_collision(s, &near, ray) == true)
    {
        if (!(near->effect & MIRROR))
            return (calc_light(s, near, ray));
        else
        {
            m.dir = vec_sub(ray.dir, vec_scale(s->n, dot(s->n, ray.dir) * 2));
            m.pos = vec_add(s->p, vec_scale(s->n, 0.0001));
            color = get_color(s, m, --total_rebound);
        }
    }
    return (color);
}

t_color_precision           set_ray(t_scene *s, t_color_precision c, int x, int y)
{
    t_ray                   r;
    double                  k;
    double                  kk;

    r.pos = s->cams->pos;
    kk = 0;
    while (kk < 1)
    {
        k = 0;
        while (k < 1)
        {
            r.dir.x = (double)(x + k) - s->image->max_w / 2;
            r.dir.y = (double)(y + kk) - s->image->max_h / 2;
            r.dir.z = -s->image->max_w / (2 * tan(s->cams->fov / 2));
            r.dir = normalise(rotv(r.dir, s->cams->dir));
			c = add_colors(c, get_color(s, r, REBOUNDS_MIRROR));
            k += sqrt(s->aa) * (1 / s->aa);
        }
        kk += sqrt(s->aa) * (1 / s->aa);
    }
    return (c);
}

void                        *engine(void *fill)
{
    register int            x;
    register int            y;
    t_color_precision       color;
    t_scene                 *s;
	int						it;
    
	it = 1;
    s = (t_scene *)fill;
    y = -1;
    while (++y < s->image->max_h)
    {
		x = s->index;
		if (x == 0 && y > (s->image->max_h / 10) * it && (it++))
			ft_putstr_fd("\033[45m  \033[0m", 1);
        while (x < s->image->max_w)
        {
            color = set_color_precision(0x0, 0x0, 0x0);
            s->image->buff[(s->image->max_h - y - 1) * s->image->max_w + x] = set_ray(s, color, x, y);
            x += s->threads;
        }
    }
    pthread_exit(NULL);
    return (s);
}
