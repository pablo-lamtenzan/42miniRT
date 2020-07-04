/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 15:05:55 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/04 15:08:00 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shape.h>

t_vec3			normal_triangle(void *x, t_ray r)
{
	t_scene		*s;
	t_vec3		n;

	s = (t_scene *)x;
	n = cross_product(vec_sub(((t_tri *)(s->objs->target))->v1, \
			((t_tri *)(s->objs->target))->v0), \
			vec_sub(((t_tri *)(s->objs->target))->v2, \
			((t_tri *)(s->objs->target))->v0));
	if (dot(normalise(n), r.dir) > 0)
		n = cross_product(vec_sub(((t_tri *)(s->objs->target))->v2, \
			((t_tri *)(s->objs->target))->v0), \
			vec_sub(((t_tri *)(s->objs->target))->v1, \
			((t_tri *)(s->objs->target))->v0));
	if (s->objs->effect & NORMAL_DIST)
		n = vec3(sin(50 * n.x + 100 * s->p.x), \
		sin(50 * n.y + 100 * s->p.x), sin(50 * n.z + 100 * s->p.z));
	return (normalise(n));
}

t_vec3			normal_cylinder(void *x, t_ray r)
{
	t_vec3		n;
	double		tmp;
	t_vec3		dir;
	t_scene		*s;

	s = (t_scene *)x;
	dir = vec3(sin(((t_cyl *)s->objs->target)->dir.x), \
			sin(((t_cyl *)s->objs->target)->dir.y), \
			sin(((t_cyl *)s->objs->target)->dir.z));
	n = vec_sub(r.pos, ((t_cyl *)s->objs->target)->pos);
	tmp = dot(r.dir, vec_scale(dir, s->objs->dist)) + dot(n, dir);
	n = vec_add(((t_cyl *)s->objs->target)->pos, vec_scale(dir, tmp));
	n = vec_sub(s->p, n);
	if (s->objs->effect & NORMAL_DIST)
		n = vec3(sin(50 * n.x + 100 * s->p.x), \
			sin(50 * n.y + 100 * s->p.x), sin(50 * n.z + 100 * s->p.z));
	return (normalise(n));
}

t_vec3			normal_square(void *x, t_ray r)
{
	t_vec3		n;
	t_scene		*s;

	s = (t_scene *)x;
	n = cross_product(vec_sub(((t_square *)(s->objs->target))->map[2], \
			((t_square *)(s->objs->target))->map[0]), \
			vec_sub(((t_square *)(s->objs->target))->map[3], \
			((t_square *)(s->objs->target))->map[0]));
	if (dot(normalise(n), r.dir) > 0)
		n = cross_product(vec_sub(((t_square *)(s->objs->target))->map[3], \
				((t_square *)(s->objs->target))->map[0]), \
				vec_sub(((t_square *)(s->objs->target))->map[2], \
				((t_square *)(s->objs->target))->map[0]));
	if (s->objs->effect & NORMAL_DIST)
		n = vec3(sin(50 * n.x + 100 * s->p.x), sin(50 * n.y + 100 * s->p.x), \
				sin(50 * n.z + 100 * s->p.z));
	return (normalise(n));
}

t_vec3			normal_sphere(void *x, t_ray r)
{
	t_vec3		n;
	t_scene		*s;

	s = (t_scene *)x;
	n = vec_sub(s->p, ((t_sphere *)s->objs->target)->pos);
	if (s->objs->effect & NORMAL_DIST)
		n = vec3(sin(50 * n.x + 100 * s->p.x), sin(50 * n.y + 100 * s->p.x), \
			sin(50 * n.z + 100 * s->p.z));
	return (normalise(n));
}

t_vec3			normal_plane(void *x, t_ray r)
{
	t_vec3		n;
	t_scene		*s;

	s = (t_scene *)x;
	n = vec_sub(((t_plane *)s->objs->target)->dir, \
			((t_plane *)s->objs->target)->pos);
	if (s->objs->effect & NORMAL_DIST)
		n = vec3(sin(50 * n.x + 100 * s->p.x), sin(50 * n.y + 100 * s->p.x), \
			sin(50 * n.z + 100 * s->p.z));
	return (normalise(n));
}
