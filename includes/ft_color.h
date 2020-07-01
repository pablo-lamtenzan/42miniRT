/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 19:53:52 by plamtenz          #+#    #+#             */
/*   Updated: 2020/06/28 21:52:15 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COLOR_H
# define FT_COLOR_H

#include "vec3.h"

typedef struct				s_color_chanels
{
	unsigned char			b;
	unsigned char			g;
	unsigned char			r;
	unsigned char			a;
}							t_color_chanels;

typedef union				u_color
{
	t_color_chanels			chanel;
	unsigned int			val;
}							t_color;

typedef struct 				s_color_precision
{
    double b;
    double g;
    double r;
    double a;
}               			t_color_precision;

t_color_precision           minmax(t_vec3 v, double aa);
t_color_precision           minmax_simple(t_vec3 v);
t_vec3                      color_preci_to_vec3(t_color_precision c);
t_color_precision           set_color_precision(double b, double g, double r);
t_vec3                      scale_color_vec3(t_color_precision c, t_vec3 v);
t_vec3                      set_color_vec3(double r, double g, double b);
t_color_precision           add_colors(t_color_precision c1, t_color_precision c2);
t_color                     set_color(double b, double g, double r);

#endif