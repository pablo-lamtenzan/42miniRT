/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 15:21:57 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/04 15:27:32 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>

bool				check_obj_collision(t_scene *s, t_obj **near, t_ray ray)
{
	double			t;
	double			min;
	bool			col;
	t_obj			*start;

	start = s->objs->start;
	s->objs = start;
	min = INFINITY;
	col = false;
	while (s->objs)
	{
		if (s->objs->collision(ray, s->objs->target, &t) && t <= min)
		{
			min = t;
			s->p = vec_add(ray.pos, vec_scale(ray.dir, t));
			s->objs->dist = t;
			s->n = s->objs->get_normal(s, ray);
			col = true;
			*near = s->objs;
		}
		s->objs = s->objs->next;
	}
	s->objs = start;
	return (col);
}

bool				check_light_collision(t_scene *s, double *min, t_ray ray)
{
	double			t;
	bool			col;
	t_obj			*start;

	*min = INFINITY;
	col = false;
	start = s->objs->start;
	while (s->objs)
	{
		if (s->objs->collision(ray, s->objs->target, &t) && t <= *min
				&& (col = true))
			*min = t;
		s->objs = s->objs->next;
	}
	s->objs = start;
	return (col);
}
