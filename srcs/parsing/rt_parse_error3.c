/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_error3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 09:39:18 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/07 18:55:52 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parsing.h>
#include <ft_error.h>
#include <stdlib.h>

bool				rt_parse_error_square(t_obj *obj, char *line)
{
	t_square		s;
	char			**values;

	if (!(values = split_multicharset(line, " ,")) || !frmt(&values[1], 10))
		return (values ? ft_error_free(OBJ_PARAMS, values) : ft_error(4));
	if (!values[10] || !parse_obj_bonus_properties(obj, &values[11], SQUARE))
		return (ft_error_free(OBJ_PARAMS, values));
	s.pos = vec3(ft_atod(values[1]), ft_atod(values[2]), ft_atod(values[3]));
	if ((s.dir.x = ft_atod(values[4])) < -1 || s.dir.x > 1)
		return (ft_error_free(OBJ_PARAMS, values));
	if ((s.dir.y = ft_atod(values[5])) < -1 || s.dir.y > 1)
		return (ft_error_free(OBJ_PARAMS, values));
	if ((s.dir.z = ft_atod(values[6])) < -1 || s.dir.z > 1)
		return (ft_error_free(OBJ_PARAMS, values));
	if ((s.height = ft_atod(values[7])) < 0 || s.height == INFINITY)
		return (ft_error_free(OBJ_PARAMS, values));
	if ((s.color.r = (double)ft_atoi(values[8])) < 0x0 || s.color.r > 0xFF)
		return (ft_error_free(OBJ_PARAMS, values));
	if ((s.color.g = (double)ft_atoi(values[9])) < 0x0 || s.color.g > 0xFF)
		return (ft_error_free(OBJ_PARAMS, values));
	if ((s.color.b = (double)ft_atoi(values[10])) < 0x0 || s.color.b > 0xFF)
		return (ft_error_free(OBJ_PARAMS, values));
	rt_square_obj(obj, rt_new_square(s.pos, s.dir, s.height, s.color));
	free_values(values);
	return (true);
}

bool				rt_parse_error_triangle(t_obj *obj, char *line)
{
	t_tri			t;
	char			**values;

	if (!(values = split_multicharset(line, " ,")) || !frmt(&values[1], 12))
		return (values ? ft_error_free(OBJ_PARAMS, values) : ft_error(4));
	if (!values[12] || !parse_obj_bonus_properties(obj, &values[13], TRIANGLE))
		return (ft_error_free(OBJ_PARAMS, values));
	t.v0 = vec3(ft_atod(values[1]), ft_atod(values[2]), ft_atod(values[3]));
	t.v1 = vec3(ft_atod(values[4]), ft_atod(values[5]), ft_atod(values[6]));
	t.v2 = vec3(ft_atod(values[7]), ft_atod(values[8]), ft_atod(values[9]));
	if ((t.color.r = (double)ft_atoi(values[10])) < 0 || t.color.r > 0xFF)
		return (ft_error_free(OBJ_PARAMS, values));
	if ((t.color.g = (double)ft_atoi(values[11])) < 0 || t.color.g > 0xFF)
		return (ft_error_free(OBJ_PARAMS, values));
	if ((t.color.b = (double)ft_atoi(values[12])) < 0 || t.color.b > 0xFF)
		return (ft_error_free(OBJ_PARAMS, values));
	t.color.a = 0;
	rt_triangle_obj(obj, rt_new_triangle(t.v0, t.v1, t.v2, t.color));
	free_values(values);
	return (true);
}

static bool			rt_parse_error_pyramid_fill(t_scene *s, t_obj *obj,
		char **values, t_py py)
{
	if ((py.color.r = ft_atoi(values[9])) < 0x0 || py.color.r > 0xFF)
		return (ft_error_free(OBJ_PARAMS, values));
	if ((py.color.g = ft_atoi(values[10])) < 0x0 || py.color.g > 0xFF)
		return (ft_error_free(OBJ_PARAMS, values));
	if ((py.color.b = ft_atoi(values[11])) < 0x0 || py.color.b > 0xFF)
		return (ft_error_free(OBJ_PARAMS, values));
	py.color.a = 0;
	if (!create_pyramid(s, obj, py))
		return (ft_error_free(OBJ_PARAMS, values));
	free(obj);
	free_values(values);
	return (true);
}

bool				rt_parse_error_pyramid(t_scene *s, t_obj *obj, char *line)
{
	t_py	py;
	char	**values;

	if (!(values = split_multicharset(line, " ,")) || !frmt(&values[1], 11))
		return (values ? ft_error_free(OBJ_PARAMS, values) : ft_error(4));
	if (!values[11] || !parse_obj_bonus_properties(obj, &values[12], PYRAMID))
		return (ft_error_free(OBJ_PARAMS, values));
	py.pos = vec3(ft_atod(values[1]), ft_atod(values[2]), ft_atod(values[3]));
	if ((py.dir.x = ft_atod(values[4])) < -1 || py.dir.x > 1)
		return (ft_error_free(OBJ_PARAMS, values));
	if ((py.dir.y = ft_atod(values[5])) < -1 || py.dir.y > 1)
		return (ft_error_free(OBJ_PARAMS, values));
	if ((py.dir.z = ft_atod(values[6])) < -1 || py.dir.z > 1)
		return (ft_error_free(OBJ_PARAMS, values));
	if ((py.base_height = ft_atod(values[7])) < 0 || py.base_height == INFINITY)
		return (ft_error_free(OBJ_PARAMS, values));
	if ((py.height = ft_atod(values[8])) < 0 || py.height == INFINITY)
		return (ft_error_free(OBJ_PARAMS, values));
	return (rt_parse_error_pyramid_fill(s, obj, values, py));
}
