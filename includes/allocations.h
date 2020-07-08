/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocations.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 20:25:49 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/07 20:15:16 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOCATIONS_H
# define ALLOCATIONS_H

# include <shape.h>

void						free_all(t_scene *s);

void						rt_cyl_obj(t_obj *obj, t_cyl *cy);
void						rt_plane_obj(t_obj *obj, t_plane *p);
void						rt_sphere_obj(t_obj *obj, t_sphere *s);
void						rt_square_obj(t_obj *obj, t_square *sq);
void						rt_triangle_obj(t_obj *obj, t_tri *t);

void						rt_cone_obj(t_obj *obj, t_co *co);
void						rt_pymarid_obj(t_obj *obj, t_py *py);
void						rt_cube_obj(t_obj *obj, t_cu *cu);

t_scene						*rt_new_scene(void);
t_obj						*rt_new_obj(int type);
t_light						*rt_new_light(void);
t_cam						*rt_new_cam(void);
t_mlx						*rt_new_image(void);
t_plane						*rt_new_plane(const t_vec3 pos, const t_vec3 dir,
		const t_color_precision color);
t_sphere					*rt_new_sphere(const t_vec3 pos, const double d,
		const t_color_precision color);
t_square					*rt_new_square(const t_vec3 pos, const t_vec3 dir,
		const double height, const t_color_precision color);
t_tri						*rt_new_triangle(const t_vec3 v0, const t_vec3 v1,
		const t_vec3 v2, const t_color_precision color);
t_cyl						*rt_new_cyl(const t_ray posdir, const double height,
		const double d, const t_color_precision color);
t_co						*rt_new_cone(const t_ray posdir, const double curve,
		const double height, const t_color_precision color);
t_py						*rt_new_pyramid(const t_ray posdir,
		const double base_height, const double height,
		const t_color_precision color);
t_py						*rt_new_cube(const t_vec3 pos, const t_vec3 dir,
		const double height, const t_color_precision color);

#endif
