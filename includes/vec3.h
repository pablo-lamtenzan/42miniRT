/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 19:48:42 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/07 20:15:42 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

# include <math.h>
# ifndef M_PI
#  define M_PI 				3.14159265358979323846
# endif

typedef struct				s_vec2
{
	double					x;
	double					y;
}							t_vec2;

typedef struct				s_vec3
{
	double					x;
	double					y;
	double					z;
}							t_vec3;

typedef struct				s_ray
{
	t_vec3					pos;
	t_vec3					dir;
}							t_ray;

t_vec3						vec3(const double x, const double y,
		const double z);
t_ray						ray2(const t_vec3 pos, const t_vec3 dir);

t_vec3						vec_sub(const t_vec3 v1, const t_vec3 v2);
t_vec3						vec_add(const t_vec3 v1, const t_vec3 v2);
t_vec3						vec_scale(const t_vec3 v, const double c);
t_vec3						vec_div(const t_vec3 v, const double c);
double						vec_len(const t_vec3 a);
double						dot(const t_vec3 v1, const t_vec3 v2);
t_vec3						normalise(const t_vec3 v);
t_vec3						cross_product(const t_vec3 v1, const t_vec3 v2);

t_vec3						vec_rotation(t_vec3 dir, t_vec3 rad);
t_vec3						get_rad(const t_vec3 ang);
t_vec3						rotv(const t_vec3 v, const t_vec3 r);

double						norm_vec3(const t_vec3 v);

#endif
