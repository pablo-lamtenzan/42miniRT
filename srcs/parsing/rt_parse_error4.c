/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_error4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 17:33:37 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/07 20:13:50 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parsing.h>
#include <ft_error.h>
#include <stdlib.h>

static	bool	rt_parse_error_cube_fill(t_scene *s, t_obj *obj,
		char **values, t_cu cu)
{
	if (!create_cube(s, obj, cu))
		return (ft_error_free2(HEAP_ALLOC, values, obj));
	free_values(values);
	free(obj);
	return (true);
}

bool			rt_parse_error_cube(t_scene *s, t_obj *obj, char *line)
{
	t_cu	cu;
	char	**values;

	if (!(values = split_multicharset(line, " ,")) || !frmt(&values[1], 10))
		return (values ? ft_error_free(OBJ_PARAMS, values) : ft_error(4));
	if (!values[10] || !parse_obj_bonus_properties(obj, &values[11], CUBE))
		return (ft_error_free(OBJ_PARAMS, values));
	cu.pos = vec3(ft_atod(values[1]), ft_atod(values[2]), ft_atod(values[3]));
	if ((cu.dir.x = ft_atod(values[4])) < -1 || cu.dir.x > 1)
		return (ft_error_free(OBJ_PARAMS, values));
	if ((cu.dir.y = ft_atod(values[5])) < -1 || cu.dir.y > 1)
		return (ft_error_free(OBJ_PARAMS, values));
	if ((cu.dir.z = ft_atod(values[6])) < -1 || cu.dir.z > 1)
		return (ft_error_free(OBJ_PARAMS, values));
	if ((cu.height = ft_atod(values[7])) < 0 || cu.height == INFINITY)
		return (ft_error_free(OBJ_PARAMS, values));
	if ((cu.color.r = ft_atoi(values[8])) < 0x0 || cu.color.r > 0xFF)
		return (ft_error_free(OBJ_PARAMS, values));
	if ((cu.color.g = ft_atoi(values[9])) < 0x0 || cu.color.g > 0xFF)
		return (ft_error_free(OBJ_PARAMS, values));
	if ((cu.color.b = ft_atoi(values[10])) < 0x0 || cu.color.b > 0xFF)
		return (ft_error_free(OBJ_PARAMS, values));
	cu.color.a = 0;
	return (rt_parse_error_cube_fill(s, obj, values, cu));
}

static bool		rt_parse_error_cone_fill(t_obj *obj, char **values, t_co co)
{
	if ((co.color.r = ft_atoi(values[9])) < 0x0 || co.color.r > 0xFF)
		return (ft_error_free(OBJ_PARAMS, values));
	if ((co.color.g = ft_atoi(values[10])) < 0x0 || co.color.g > 0xFF)
		return (ft_error_free(OBJ_PARAMS, values));
	if ((co.color.b = ft_atoi(values[11])) < 0x0 || co.color.b > 0xFF)
		return (ft_error_free(OBJ_PARAMS, values));
	rt_cone_obj(obj, rt_new_cone(ray2(co.pos, co.dir),
			co.curve, co.height, co.color));
	free_values(values);
	return (true);
}

bool			rt_parse_error_cone(t_obj *obj, char *line)
{
	t_co		co;
	char		**values;

	if (!(values = split_multicharset(line, " ,")) || !frmt(&values[1], 11))
		return (values ? ft_error_free(OBJ_PARAMS, values) : ft_error(4));
	if (!values[11] || !parse_obj_bonus_properties(obj, &values[12], CONE))
		return (ft_error_free(OBJ_PARAMS, values));
	co.pos = vec3(ft_atod(values[1]), ft_atod(values[2]), ft_atod(values[3]));
	if ((co.dir.x = ft_atod(values[4])) < -1 || co.dir.x > 1)
		return (ft_error_free(OBJ_PARAMS, values));
	if ((co.dir.y = ft_atod(values[5])) < -1 || co.dir.y > 1)
		return (ft_error_free(OBJ_PARAMS, values));
	if ((co.dir.z = ft_atod(values[6])) < -1 || co.dir.z > 1)
		return (ft_error_free(OBJ_PARAMS, values));
	co.dir = normalise(co.dir);
	if ((co.curve = ft_atod(values[7])) < 0)
		return (ft_error_free(OBJ_PARAMS, values));
	if ((co.height = ft_atod(values[8])) < 0)
		return (ft_error_free(OBJ_PARAMS, values));
	return (rt_parse_error_cone_fill(obj, values, co));
}
