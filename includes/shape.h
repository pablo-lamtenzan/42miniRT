/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 20:49:14 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/05 19:47:49 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H

# include <raytracer.h>

# define SPHERE				2
# define SQUARE				3
# define CYLINDER			4
# define TRIANGLE			5
# define PLANE				6
# define CUBE				7
# define CONE				8
# define PYRAMID			9
# define DISK				10

typedef struct				s_sphere
{
	t_vec3					pos;
	double					d;
	t_color_precision		color;
}							t_sphere;

typedef struct				s_plane
{
	t_vec3					pos;
	t_vec3					dir;
	t_color_precision		color;
}							t_plane;

typedef struct				s_square
{
	t_vec3					pos;
	t_vec3					dir;
	double					height;
	t_vec3					map[4];
	t_color_precision		color;
}							t_square;

typedef struct				s_cyl
{
	t_vec3					pos;
	t_vec3					dir;
	double					d;
	double					height;
	t_color_precision		color;
}							t_cyl;

typedef struct				s_tri
{
	t_vec3					v0;
	t_vec3					v1;
	t_vec3					v2;
	t_color_precision		color;
}							t_tri;

typedef struct				s_disk
{
	t_vec3					pos;
	t_vec3					dir;
	double					d;
	t_color_precision		color;
}							t_disk;

typedef struct				s_co
{
	t_vec3					pos;
	t_vec3					dir;
	double					curve;
	double					height;
	t_color_precision		color;
}							t_co;

typedef struct				s_cu
{
	t_vec3					pos;
	t_vec3					dir;
	double					height;
	t_color_precision		color;
}							t_cu;

typedef struct				s_py
{
	t_vec3					pos;
	t_vec3					dir;
	double					base_height;
	double					height;
	t_color_precision		color;
}							t_py;

bool						collisions_cylinder(const t_ray r,
		void *cy, double *t);
bool						collisions_plane(const t_ray r, void *pl,
		double *t);
bool						collisions_sphere(const t_ray r, void *sp,
		double *t);
bool						collisions_square(const t_ray r, void *sq,
		double *t);
bool						collisions_triangle(const t_ray r, void *tr,
		double *t);
bool						collisions_cone(const t_ray r, void *co,
		double *t);

bool						collisions_disk(const t_ray r, void *d,
		double *t);

t_vec3						normal_triangle(void *s, const t_ray r);
t_vec3						normal_cylinder(void *s, const t_ray r);
t_vec3						normal_square(void *s, const t_ray r);
t_vec3						normal_sphere(void *s, const t_ray r);
t_vec3						normal_plane(void *s, const t_ray r);
t_vec3						normal_cone(void *s, const t_ray r);

bool						create_disks(t_scene *s, const t_cyl cyl,
		t_obj *obj);
t_vec3						normal_disk(void *s, const t_ray r);
bool						create_pyramid(t_scene *s, t_obj *obj,
		const t_py py);
bool						create_cube(t_scene *s, t_obj *obj, const t_cu cu);
void						map_square(t_square *sq);
void						map_square_lr(t_square *sq);
void						map_square_fb(t_square *sq);

#endif
