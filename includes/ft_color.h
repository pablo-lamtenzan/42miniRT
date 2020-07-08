/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 20:31:05 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/07 20:15:27 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COLOR_H
# define FT_COLOR_H

# include <vec3.h>

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

typedef struct				s_color_precision
{
	double b;
	double g;
	double r;
	double a;
}							t_color_precision;

t_color_precision			minmax(const t_vec3 v, const double aa);
t_color_precision			minmax_simple(const t_vec3 v);
t_vec3						color_preci_to_vec3(t_color_precision const c);
t_color_precision			set_color_precision(const double b, const double g,
		const double r);
t_vec3						scale_color_vec3(t_color_precision const c,
		t_vec3 v);
t_vec3						set_color_vec3(const double r, const double g,
		const double b);
t_color_precision			add_colors(t_color_precision c1,
		const t_color_precision c2);
t_color						set_color(const double b, const double g,
		const double r);

#endif
