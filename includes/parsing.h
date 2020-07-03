/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 18:40:34 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/03 14:18:03 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

#include <allocations.h>
#include <stdbool.h>
#include <aux.h>

//#include "get_next_line.h"

void			rt_parse(int fd, t_scene *scene);
bool			rt_parse_line(t_scene *scene, char *line);
bool			rt_parse_light(t_scene *scene, char *line);
bool			rt_parse_obj(t_scene *scene, char *line);
bool		    rt_parse_obj_bonus(t_scene *s, char *line);
bool			rt_parse_cam(t_scene *scene, char *line);
bool			rt_parse_error_square(t_obj *obj, char *line);
bool			rt_parse_error_triangle(t_obj *obj, char *line);
bool			rt_parse_error_plane(t_obj *obj, char *line);
bool			rt_parse_error_sphere(t_obj *obj, char *line);
bool			rt_parse_error_cylinder(t_scene *s, t_obj *obj, char *line);
bool			rt_parse_error_res(t_scene *scene, char *line);
bool			rt_parse_error_amb(t_scene *scene, char *line);
bool			rt_parse_error_point(t_light *light, char *line);
bool			rt_parse_error_cam(t_cam *cam, char *line);
bool            rt_parse_error_cube(t_scene *s, t_obj *obj, char *line);
bool            rt_parse_error_cone(t_obj *obj, char *line);
bool            rt_parse_error_pyramid(t_scene *s, t_obj *obj, char *line);
bool            rt_parse_error_aa(t_scene *s, char *line);
bool            rt_parse_error_filter(t_scene *s, char *line);
bool            parse_obj_bonus_properties(t_obj *obj, char **values, int id);
bool	        check_file(int arc, char **argv, int *fd, t_scene *scene);
void			free_values(char **values);

#endif