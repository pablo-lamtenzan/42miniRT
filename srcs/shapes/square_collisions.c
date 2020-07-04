/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_collisions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 15:11:14 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/04 15:12:52 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shape.h>

bool			collisions_square_bis(t_ray r, void *sq, double *t)
{
	t_vec3		d;
	t_vec3		v[5];

	v[0] = vec_sub(((t_square *)sq)->map[2], ((t_square *)sq)->map[0]);
	v[1] = vec_sub(((t_square *)sq)->map[3], ((t_square *)sq)->map[0]);
	v[2] = cross_product(r.dir, v[1]);
	if (!(d.x = dot(v[0], v[2])))
		return (false);
	d.x = 1 / d.x;
	v[3] = vec_sub(r.pos, ((t_square *)sq)->map[0]);
	d.y = d.x * dot(v[3], v[2]);
	if (d.y < 0 || d.y > 1)
		return (false);
	v[4] = cross_product(v[3], v[0]);
	d.z = d.x * dot(r.dir, v[4]);
	if (d.z < 0.0 || d.y + d.z > 1.0)
		return (false);
	d.y = d.x * dot(v[1], v[4]);
	if (d.y > 0.001)
	{
		*t = d.y;
		return (true);
	}
	return (false);
}

bool			collisions_square_bis_bis(t_ray r, void *sq, double *t)
{
	t_vec3		d;
	t_vec3		v[5];

	v[0] = vec_sub(((t_square *)sq)->map[2], ((t_square *)sq)->map[1]);
	v[1] = vec_sub(((t_square *)sq)->map[3], ((t_square *)sq)->map[1]);
	v[2] = cross_product(r.dir, v[1]);
	if (!(d.x = dot(v[0], v[2])))
		return (false);
	d.x = 1 / d.x;
	v[3] = vec_sub(r.pos, ((t_square *)sq)->map[1]);
	d.y = d.x * dot(v[3], v[2]);
	if (d.y < 0 || d.y > 1)
		return (false);
	v[4] = cross_product(v[3], v[0]);
	d.z = d.x * dot(r.dir, v[4]);
	if (d.z < 0.0 || d.y + d.z > 1.0)
		return (false);
	if ((d.y = d.x * dot(v[1], v[4])) > 0.001)
	{
		*t = d.y;
		return (true);
	}
	return (false);
}

void			map_square(t_square *sq)
{
	sq->map[0] = vec_add(sq->pos, rotv(vec3(-sq->height / 2, 0, \
			sq->height / 2), sq->dir));
	sq->map[1] = vec_add(sq->pos, rotv(vec3(sq->height / 2, 0, \
			-sq->height / 2), sq->dir));
	sq->map[2] = vec_add(sq->pos, rotv(vec3(sq->height / 2, 0, \
			sq->height / 2), sq->dir));
	sq->map[3] = vec_add(sq->pos, rotv(vec3(-sq->height / 2, 0, \
			-sq->height / 2), sq->dir));
}

bool			collisions_square(t_ray r, void *sq, double *t)
{
	double		t_;

	if (collisions_square_bis(r, sq, &t_)
			|| collisions_square_bis_bis(r, sq, &t_))
	{
		*t = t_;
		return (true);
	}
	return (false);
}
