/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 15:01:17 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/07 20:14:40 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shape.h>

static double		quadracone(const t_ray r, void *co, double *a)
{
	t_vec3			v;
	double			s;

	s = INFINITY;
	if (a[0] > 0)
	{
		v = vec_add(vec_scale(r.dir, a[0]), \
				vec_sub(r.pos, ((t_co *)co)->pos));
		a[3] = dot(v, ((t_co *)co)->dir);
		if (a[3] <= ((t_co *)co)->height / 2 && a[3] >= \
				-((t_co *)co)->height / 2)
			s = a[0];
	}
	if (a[1] > 0)
	{
		v = vec_add(vec_scale(r.dir, a[1]), \
			vec_sub(r.pos, ((t_co *)co)->pos));
		a[3] = dot(v, ((t_co *)co)->dir);
		if (a[3] <= ((t_co *)co)->height / 2 && a[3] >= \
				-((t_co *)co)->height / 2 && a[1] < s)
			s = a[1];
	}
	if (s < INFINITY)
		return (s);
	return (-1);
}

bool				collisions_cone(const t_ray r, void *co, double *t)
{
	double			a[4];
	double			abc[3];
	double			delta;
	t_vec3			v[2];

	v[0] = vec_sub(r.pos, ((t_co *)co)->pos);
	v[1] = vec_scale(r.dir, -1);
	a[0] = tan((((t_co *)co)->curve) * M_PI / 180);
	a[1] = 1 + a[0] * a[0];
	a[2] = dot(v[1], ((t_co *)co)->dir);
	a[3] = dot(v[0], ((t_co *)co)->dir);
	abc[0] = dot(v[1], v[1]) - (a[1] * a[2] * a[2]);
	abc[1] = 2 * (dot(v[1], v[0]) - (a[1] * a[2] * a[3]));
	abc[2] = dot(v[0], v[0]) - (a[1] * a[3] * a[3]);
	if ((delta = abc[1] * abc[1] - 4 * abc[0] * abc[2]) <= 0)
		return (false);
	a[0] = (abc[1] - sqrt(delta)) / (2 * abc[0]);
	a[1] = (abc[1] + sqrt(delta)) / (2 * abc[0]);
	if ((*t = quadracone(r, co, a)) == -1)
	{
		*t = INFINITY;
		return (false);
	}
	return (true);
}

t_vec3				normal_cone(void *x, const t_ray r)
{
	t_vec3			n;
	double			tmp;
	t_scene			*s;

	s = (t_scene *)x;
	tmp = dot(r.dir, ((t_co *)s->objs->target)->dir) * s->objs->dist + \
			dot(vec_sub(r.pos, ((t_co *)s->objs->target)->pos), \
			((t_co *)s->objs->target)->dir);
	n = vec_sub(vec_sub(s->p, ((t_co *)s->objs->target)->pos), \
		vec_scale(vec_scale(((t_co *)s->objs->target)->dir, (1 + \
		pow(tan(((t_co *)s->objs->target)->curve * M_PI / 180), 2))), tmp));
	if (s->objs->effect & NORMAL_DIST)
		n = vec3(sin(50 * n.x + 100 * s->p.x), sin(50 * n.y + 100 * s->p.x), \
			sin(50 * n.z + 100 * s->p.z));
	return (normalise(n));
}
