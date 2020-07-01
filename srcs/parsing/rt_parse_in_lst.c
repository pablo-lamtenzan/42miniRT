/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_in_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 06:02:13 by plamtenz          #+#    #+#             */
/*   Updated: 2020/06/30 14:16:38 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parsing.h>

bool				rt_parse_light(t_scene *scene, char *line)
{
	t_light			*light;
	bool			res;

	if (!ft_strncmp(line, "A ", 2) || !ft_strncmp(line, "l ", 2))
	{
		!ft_strncmp(line, "A ", 2) ? scene->flags |= RT_AMB : 0;
		if (!ft_strncmp(line, "A ", 2))
			res = rt_parse_error_amb(scene, line);
		else
		{
			light = rt_new_light();
			ft_lightadd_back(&scene->lights, light);
			res = rt_parse_error_point(light, line);
		}
		if (res)
			return (true);
	}
	return (false);
}

bool				rt_parse_obj(t_scene *scene, char *line)
{
	t_obj			*obj;
	int				id;

	id = -1;
	!ft_strncmp(line, "pl ", 3) ? id = PLANE : 0;
	!ft_strncmp(line, "sq ", 3) ? id = SQUARE : 0;
	!ft_strncmp(line, "sp ", 3) ? id = SPHERE : 0;
	!ft_strncmp(line, "cy ", 3) ? id = CYLINDER : 0;
	!ft_strncmp(line, "tr ", 3) ? id = TRIANGLE : 0;
	if (id < 0 || !(obj = rt_new_obj(id)))
		return (false);
	obj->mlx_ptr = scene->image->mlx;
	ft_objadd_back(&scene->objs, obj);
	id == PLANE ? id = rt_parse_error_plane(obj, line) : 0;
	id == SQUARE ? id = rt_parse_error_square(obj, line) : 0;
	id == SPHERE ? id = rt_parse_error_sphere(obj, line) : 0;
	id == CYLINDER ? id = rt_parse_error_cylinder(scene, obj, line) : 0;
	id == TRIANGLE ? id = rt_parse_error_triangle(obj, line) : 0;
	if (!id)
		return(false);
	return (true);
}

bool				rt_parse_obj_bonus(t_scene *s, char *line)
{
	t_obj			*obj;
	int				id;

	id = -1;
	!ft_strncmp(line, "cu ", 3) ? id = CUBE : 0;
	!ft_strncmp(line, "co ", 3) ? id = CONE : 0;
	!ft_strncmp(line, "py ", 3) ? id = PYRAMID : 0;
	if (id < 0 || !(obj = rt_new_obj(id)))
		return (false);
	obj->mlx_ptr = s->image->mlx;
	if (id != CUBE && id != PYRAMID)
		ft_objadd_back(&s->objs, obj);
	id == CUBE ? id = rt_parse_error_cube(s, obj, line) : 0;
	id == CONE ? id = rt_parse_error_cone(obj, line) : 0;
	id == PYRAMID ? id = rt_parse_error_pyramid(s, obj, line) : 0;
	if (!id)
		return (false);
	return (true);
}

bool			rt_parse_cam(t_scene *scene, char *line)
{
	t_cam			*cam;
	//int				res;

	//res = scene->cams ? scene->cams->num + 1 : 1;
	cam = rt_new_cam();
	ft_camadd_back(&scene->cams, cam);
	if ((rt_parse_error_cam(cam, line)) > 0)
		return (true);
	return (false);
}
