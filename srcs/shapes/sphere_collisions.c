/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_collisions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:38:06 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/01 14:38:23 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shape.h>

bool         collisions_sphere(t_ray r, void *sp, double *t)
{
    t_vec3  abc;
    double  delta;
    t_vec2  tt;

    abc.x = dot(r.dir, r.dir);
    abc.y = 2 * dot(r.dir, vec_sub(r.pos, ((t_sphere *)sp)->pos));
    abc.z = norm_vec3(vec_sub(r.pos, ((t_sphere *)sp)->pos)) - \
			(((t_sphere *)sp)->d * ((t_sphere *)sp)->d);
    if ((delta = abc.y * abc.y - 4 * abc.x * abc.z) < 0)
        return (false);
    tt.x = (- abc.y - sqrt(delta)) / (2 * abc.x);
    tt.y = (- abc.y + sqrt(delta)) / (2 * abc.x);
    if (tt.y <= 0)
        return (false);
    if (tt.x > 0)
        *t = tt.x;
    else
        *t = tt.y;
    return (true);
}