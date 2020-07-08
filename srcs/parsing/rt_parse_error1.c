/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_error1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 03:02:03 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/07 20:13:42 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parsing.h>
#include <ft_error.h>
#include <stdlib.h>
#include <aux.h>

bool			rt_parse_error_res(t_scene *scene, char *line)
{
	char		**values;
	int			w;
	int			h;

	if (scene->flags & RT_RES)
		return (ft_error(MANY_RES));
	if (!(values = split_multicharset(line, " ,")) || !frmt(&values[1], 2))
		return (values ? ft_error_free(CAM_PARAMS, values) : ft_error(4));
	if (!values[2] || values[3])
		return (ft_error_free(CAM_PARAMS, values));
	mlx_get_screen_size(scene->image->mlx, &w, &h);
	if ((scene->image->max_w = ft_atoi(values[1])) <= 0)
		return (ft_error_free(CAM_PARAMS, values));
	if ((scene->image->max_h = ft_atoi(values[2])) <= 0)
		return (ft_error_free(CAM_PARAMS, values));
	scene->image->max_h = scene->image->max_h > h ? h : scene->image->max_h;
	scene->image->max_w = scene->image->max_w > w ? w : scene->image->max_w;
	scene->flags |= RT_RES;
	free_values(values);
	return (true);
}

bool			rt_parse_error_amb(t_scene *scene, char *line)
{
	char		**values;

	if (scene->flags & RT_AMB)
		return (ft_error(AMB_PARAMS));
	if (!(values = split_multicharset(line, " ,")) || !frmt(&values[1], 4))
		return (values ? ft_error_free(LIGHT_PARAMS, values) : ft_error(4));
	if (!values[4] || values[5])
		return (ft_error_free(LIGHT_PARAMS, values));
	if ((scene->amb_intensity = ft_atod(values[1])) < 0 ||
			scene->amb_intensity > 1)
		return (ft_error_free(LIGHT_PARAMS, values));
	if ((scene->amb_color.r = (double)ft_atoi(values[2])) < 0x0 ||
			scene->amb_color.r > 0xff)
		return (ft_error_free(LIGHT_PARAMS, values));
	if ((scene->amb_color.g = (double)ft_atoi(values[3])) < 0x0 ||
			scene->amb_color.g > 0xff)
		return (ft_error_free(LIGHT_PARAMS, values));
	if ((scene->amb_color.b = (double)ft_atoi(values[4])) < 0x0 ||
			scene->amb_color.b > 0xff)
		return (ft_error_free(LIGHT_PARAMS, values));
	scene->amb_color.a = 0;
	scene->flags |= RT_AMB;
	free_values(values);
	return (true);
}

bool			rt_parse_error_point(t_light *light, char *line)
{
	char	**values;

	if (!(values = split_multicharset(line, " ,")) || !frmt(&values[1], 7))
		return (values ? ft_error_free(LIGHT_PARAMS, values) : ft_error(4));
	if (!values[7] || values[8])
		return (ft_error_free(LIGHT_PARAMS, values));
	light->pos = vec3(ft_atod(values[1]), ft_atod(values[2]),
			ft_atod(values[3]));
	if ((light->intensity = ft_atod(values[4])) < 0 ||
			light->intensity > 1)
		return (ft_error_free(LIGHT_PARAMS, values));
	light->intensity *= 100;
	if ((light->color.r = (double)ft_atoi(values[5])) < 0x0 ||
			light->color.r > 0xff)
		return (ft_error_free(LIGHT_PARAMS, values));
	if ((light->color.g = (double)ft_atoi(values[6])) < 0x0 ||
			light->color.g > 0xff)
		return (ft_error_free(LIGHT_PARAMS, values));
	if ((light->color.b = (double)ft_atoi(values[7])) < 0x0 ||
			light->color.b > 0xff)
		return (ft_error_free(LIGHT_PARAMS, values));
	free_values(values);
	return (true);
}

bool			rt_parse_error_cam(t_cam *cam, char *line)
{
	char	**values;

	if (!(values = split_multicharset(line, " ,")) || !frmt(&values[1], 7))
		return (values ? ft_error_free(CAM_PARAMS, values) : ft_error(4));
	if (!values[7] || values[8])
		return (ft_error_free(CAM_PARAMS, values));
	cam->pos = vec3(ft_atod(values[1]), ft_atod(values[2]),
			ft_atod(values[3]));
	if ((cam->dir.x = ft_atod(values[4])) < -1.0 || cam->dir.x > 1.0)
		return (ft_error_free(CAM_PARAMS, values));
	if ((cam->dir.y = ft_atod(values[5])) < -1.0 || cam->dir.y > 1.0)
		return (ft_error_free(CAM_PARAMS, values));
	if ((cam->dir.z = ft_atod(values[6])) < -1.0 || cam->dir.z > 1.0)
		return (ft_error_free(CAM_PARAMS, values));
	if ((cam->fov = ft_atod(values[7])) <= 0 || cam->fov > 180)
		return (ft_error_free(CAM_PARAMS, values));
	cam->fov = cam->fov * M_PI / 180;
	free_values(values);
	return (true);
}
