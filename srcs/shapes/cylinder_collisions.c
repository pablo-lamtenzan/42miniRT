/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_collisions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:27:12 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/01 14:28:32 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shape.h>
#include <stdlib.h>

bool            collisions_disk(t_ray r, void *d, double *t)
{
    t_vec3      p;
    double      dist;
    t_plane     *pl;

    if (!(pl = malloc(sizeof(t_plane))))
        return (false);
    pl->dir = ((t_disk *)d)->dir;
    pl->pos = ((t_disk *)d)->pos;
    if (collisions_plane(r, pl, t))
    {
        p = vec_add(r.pos, vec_scale(r.dir, *t));
        p = vec_sub(p, ((t_disk *)d)->pos);
        dist = dot(p, p);
        if (sqrt(dist) <= ((t_disk *)d)->d / 2)
        {
            free(pl);
            return (true);
        }
    }
    free(pl);
    return (false);
}

t_vec3          normal_disk(void *x, t_ray r)
{
    t_vec3      n;
	t_scene 	*s;

	s = (t_scene *)x;

    n = vec_sub(((t_disk *)s->objs->target)->dir, \
			((t_disk *)s->objs->target)->pos);
    if (dot(normalise(n), r.dir) > 0)
        n = vec_scale(n, -1);
    if (s->objs->effect & NORMAL_DIST)
        n = vec3(sin(50 * n.x + 100 * s->p.x), sin(50 * n.y + 100 * s->p.x), \
            sin(50 * n.z + 100 * s->p.z));
    return (normalise(n));
}

bool            cyl_cols_fill(t_ray r, void *cy, double *abcd, double *t)
{
    t_vec3      v;

    if (*t > 0)
    {
        v = vec_add(vec_scale(r.dir, *t), vec_sub(r.pos, ((t_cyl *)cy)->pos));
        abcd[2] = dot(v, ((t_cyl *)cy)->dir);
        if (abcd[2] < ((t_cyl *)cy)->height / 2 && abcd[2] > \
				-((t_cyl *)cy)->height / 2)
            return (true);
    }
    if ((*t = abcd[3]) > 0)
    {
        v = vec_add(vec_scale(r.dir, *t), vec_sub(r.pos, ((t_cyl *)cy)->pos));
        abcd[2] = dot(v, ((t_cyl *)cy)->dir);
        if (abcd[2] < ((t_cyl *)cy)->height / 2 && abcd[2] > \
				-((t_cyl *)cy)->height / 2)
            return (true);
    }
    return (false);
}

bool            collisions_cylinder(t_ray r, void *cy, double *t)
{
    double      abcd[4];
    t_vec3      v[3];
    double      delta;

    v[2] = vec_sub(r.pos, ((t_cyl *)cy)->pos);
    v[0] = vec_sub(r.dir, vec_scale(((t_cyl *)cy)->dir, \
			dot(r.dir,((t_cyl *)cy)->dir)));
    abcd[0] = dot(v[0], v[0]);
    v[1] = vec_sub(v[2], vec_scale(((t_cyl *)cy)->dir, \
			dot(v[2], ((t_cyl *)cy)->dir)));
    abcd[1] = 2 * dot(v[0], v[1]);
    abcd[2] = dot(v[1], v[1]) - pow(((t_cyl *)cy)->d / 2, 2);
    if ((delta = abcd[1] * abcd[1] - 4 * abcd[0] * abcd[2]) < 0)
        return (false);
    *t = (-abcd[1] - sqrt(delta)) / (2 * abcd[0]);
    abcd[3] = (-abcd[1] + sqrt(delta)) / (2 * abcd[0]);
    return (cyl_cols_fill(r, cy, abcd, t));
}