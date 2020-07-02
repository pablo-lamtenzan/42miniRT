/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 20:10:51 by user42            #+#    #+#             */
/*   Updated: 2020/07/02 20:34:48 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H

#include <raytracer.h>

#define SPHERE              2
#define SQUARE              3
#define CYLINDER            4
#define TRIANGLE            5
#define PLANE               6
#define CUBE                7
#define CONE                8
#define PYRAMID             9
#define DISK                10

typedef struct				s_sphere
{
	t_vec3				    pos;
	double					d;
    t_color_precision       color;
}							t_sphere;

typedef struct				s_plane
{
	t_vec3				    pos;
	t_vec3				    dir;
    t_color_precision       color;
}							t_plane;

typedef struct				s_square
{
	t_vec3				    pos;
	t_vec3				    dir;
	double					height;
    t_vec3                  map[4];
    t_color_precision       color;
}							t_square;

typedef struct				s_cyl
{
	t_vec3				    pos;
	t_vec3				    dir;
	double					d;
	double					height;
    t_color_precision       color;
}							t_cyl;

typedef struct				s_tri
{
	t_vec3				    v0;
	t_vec3				    v1;
	t_vec3				    v2;
    t_color_precision       color;
}							t_tri;

typedef struct              s_disk
{
    t_vec3                  pos;
    t_vec3                  dir;
    double                  d;
    t_color_precision       color;
}                           t_disk;

typedef struct              s_co
{
    t_vec3                  pos;
    t_vec3                  dir;
    double                  curve;
    double                  height;
    t_color_precision       color;
}                           t_co;

typedef struct              s_cu
{
    t_vec3                  pos;
    t_vec3                  dir;
    double                  height;
    t_color_precision       color;
}                           t_cu;

typedef struct              s_py
{
    t_vec3                  pos;
    t_vec3                  dir;
    double                  base_height;
    double                  height;
    t_color_precision       color;
}                           t_py;

/*
** ---------------------------- MANDATORY PART ------------------------------ **
*/
bool                        collisions_cylinder(t_ray r, void *cy, double *t);
bool                        collisions_plane(t_ray r, void *pl, double *t);
bool                        collisions_sphere(t_ray r, void *sp, double *t);
bool                        collisions_square(t_ray r, void *sq, double *t);
bool                        collisions_triangle(t_ray r, void *tr, double *t);
bool                        collisions_cone(t_ray r, void *co, double *t);

/*
** ------------------------------ BONUS PART -------------------------------- **
*/
bool                        collisions_disk(t_ray r, void *d, double *t);
/*
** ---------------------------- MANDATORY PART ------------------------------ **
*/
t_vec3                      normal_triangle(void *s, t_ray r);
t_vec3                      normal_cylinder(void *s, t_ray r);
t_vec3                      normal_square(void *s, t_ray r);
t_vec3                      normal_sphere(void *s, t_ray r);
t_vec3                      normal_plane(void *s, t_ray r);
t_vec3                      normal_cone(void *s, t_ray r);
/*
** ------------------------------ BONUS PART -------------------------------- **
*/
bool                        create_disks(t_scene *s, t_cyl cyl, t_obj *obj);
t_vec3                      normal_disk(void *s, t_ray r);
bool                        create_pyramid(t_scene *s, t_obj *obj, t_py py);
bool                        create_cube(t_scene *s, t_obj *obj, t_cu cu);
void                        map_square(t_square *sq);
void            			map_square_lr(t_square *sq);
void            			map_square_fb(t_square *sq);

#endif