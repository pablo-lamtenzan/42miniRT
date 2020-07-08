/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_collisions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 15:09:41 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/07 20:14:48 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shape.h>

bool		collisions_sphere(const t_ray r, void *sp, double *t)
{
	t_vec3	abc;
	double	delta;
	t_vec2	tt;

	abc.x = dot(r.dir, r.dir);
	abc.y = 2 * dot(r.dir, vec_sub(r.pos, ((t_sphere *)sp)->pos));
	abc.z = norm_vec3(vec_sub(r.pos, ((t_sphere *)sp)->pos)) - \
			(((t_sphere *)sp)->d * ((t_sphere *)sp)->d);
	if ((delta = abc.y * abc.y - 4 * abc.x * abc.z) < 0)
		return (false);
	tt.x = (-abc.y - sqrt(delta)) / (2 * abc.x);
	tt.y = (-abc.y + sqrt(delta)) / (2 * abc.x);
	if (tt.y <= 0)
		return (false);
	if (tt.x > 0)
		*t = tt.x;
	else
		*t = tt.y;
	return (true);
}
