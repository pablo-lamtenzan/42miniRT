/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 19:48:42 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/04 20:55:43 by plamtenz         ###   ########.fr       */
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

t_vec3						vec3(double x, double y, double z);
t_ray						ray2(t_vec3 pos, t_vec3 dir);

double						quad_equ_d(double a, double b, double c);
int							v_quad_equ(double a, double b,
		double c, t_vec2 *res);

t_vec3						vec_sub(t_vec3 v1, t_vec3 v2);
t_vec3						vec_add(t_vec3 v1, t_vec3 v2);
t_vec3						vec_scale(t_vec3 v, double c);
t_vec3						vec_div(t_vec3 v, double c);
double						vec_len(t_vec3 a);
double						dot(t_vec3 v1, t_vec3 v2);
t_vec3						normalise(t_vec3 v);
t_vec3						cross_product(t_vec3 v1, t_vec3 v2);

t_vec3						vec_rotation(t_vec3 dir, t_vec3 rad);
t_vec3						get_rad(t_vec3 ang);
t_vec3						rotv(t_vec3 v, t_vec3 r);

double						norm_vec3(t_vec3 v);

#endif
