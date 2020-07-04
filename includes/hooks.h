/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 20:38:10 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/04 20:39:12 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include <shape.h>
# include <X11/keysym.h>

void			resize_dir(double *point, double resize);
int				motion_hook(int x, int y, void *fill);
int				motion_end(void *fill);
int				mouse_hook(int key, int x, int y, void *fill);
int				key_hook(int key, void *fill);
int				key_normal(int key, void *fill);
void			key_translation(int key, t_obj *obj);
void			key_rotation(int key, t_obj *obj);
int				swicth_cam_or_obj_fill5(int key, t_scene *s);
int				swicth_cam_or_obj_fill1(int key, t_scene *s);

void			change_dir_sq(int key, t_square *w, int dir);
void			change_dir_cy(int key, t_obj *obj);
void			change_dir_pl(int key, t_plane *w);
void			change_dir_co(int key, t_co *w);

void			change_pos_sq(int key, t_square *w, int dir);
void			change_pos_cy(int key, t_obj *s);
void			change_pos_pl(int key, t_plane *w);
void			change_pos_sp(int key, t_sphere *w);
void			change_pos_co(int key, t_co *w);
void			change_pos_tr(int key, t_tri *w);

void			change_pos_py(int key, t_obj *py);
void			change_pos_cu(int key, t_obj *cu);
void			change_dir_cu(int key, t_obj *cu);

char			*get_obj_type(int id);

#endif
