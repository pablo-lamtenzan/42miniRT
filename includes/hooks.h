/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 20:38:10 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/05 19:43:30 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include <shape.h>
# include <X11/keysym.h>

void			resize_dir(double *point, double resize);
int				motion_hook(int x, int y, void *fill);
int				motion_end(void *fill);
int				mouse_hook(const int key, int x, int y, void *fill);
int				key_hook(const int key, void *fill);
void			key_translation(const int key, t_obj *obj);
void			key_rotation(const int key, t_obj *obj);
int				swicth_cam_or_obj_fill5(const int key, t_scene *s);
int				swicth_cam_or_obj_fill1(const int key, t_scene *s);

void			change_dir_sq(const int key, t_square *w, int dir);
void			change_dir_cy(const int key, t_obj *obj);
void			change_dir_pl(const int key, t_plane *w);
void			change_dir_co(const int key, t_co *w);

void			change_pos_sq(const int key, t_square *w, int dir);
void			change_pos_cy(const int key, t_obj *s);
void			change_pos_pl(const int key, t_plane *w);
void			change_pos_sp(const int key, t_sphere *w);
void			change_pos_co(const int key, t_co *w);
void			change_pos_tr(const int key, t_tri *w);

void			change_pos_py(const int key, t_obj *py);
void			change_pos_cu(const int key, t_obj *cu);
void			change_dir_cu(const int key, t_obj *cu);

char			*get_obj_type(const int id);

#endif
