/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_error2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 07:18:15 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/07 20:13:44 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parsing.h>
#include <ft_error.h>
#include <stdlib.h>

bool				rt_parse_error_plane(t_obj *obj, char *line)
{
	t_plane			p;
	char			**values;

	if (!(values = split_multicharset(line, " ,")) || !frmt(&values[1], 9))
		return (values ? ft_error_free(OBJ_PARAMS, values) : ft_error(4));
	if (!values[9] || !parse_obj_bonus_properties(obj, &values[10], PLANE))
		return (ft_error_free(OBJ_PARAMS, values));
	p.pos = vec3(ft_atod(values[1]), ft_atod(values[2]), ft_atod(values[3]));
	if ((p.dir.x = ft_atod(values[4])) < -1 || p.dir.x > 1)
		return (ft_error_free(OBJ_PARAMS, values));
	if ((p.dir.y = ft_atod(values[5])) < -1 || p.dir.y > 1)
		return (ft_error_free(OBJ_PARAMS, values));
	if ((p.dir.z = ft_atod(values[6])) < -1 || p.dir.z > 1)
		return (ft_error_free(OBJ_PARAMS, values));
	p.dir = normalise(p.dir);
	if ((p.color.r = (double)ft_atoi(values[7])) < 0 || p.color.r > 0xff)
		return (ft_error_free(OBJ_PARAMS, values));
	if ((p.color.g = (double)ft_atoi(values[8])) < 0 || p.color.g > 0xff)
		return (ft_error_free(OBJ_PARAMS, values));
	if ((p.color.b = (double)ft_atoi(values[9])) < 0 || p.color.b > 0xff)
		return (ft_error_free(OBJ_PARAMS, values));
	p.color.a = 0;
	rt_plane_obj(obj, rt_new_plane(p.pos, p.dir, p.color));
	free_values(values);
	return (true);
}

bool				rt_parse_error_sphere(t_obj *obj, char *line)
{
	t_sphere		sp;
	char			**values;

	if (!(values = split_multicharset(line, " ,")) || !frmt(&values[1], 7))
		return (values ? ft_error_free(OBJ_PARAMS, values) : ft_error(4));
	if (!values[7] || !parse_obj_bonus_properties(obj, &values[8], SPHERE))
		return (ft_error_free(OBJ_PARAMS, values));
	sp.pos = vec3(ft_atod(values[1]), ft_atod(values[2]), ft_atod(values[3]));
	if ((sp.d = ft_atod(values[4])) < 0 || sp.d == INFINITY)
		return (ft_error_free(OBJ_PARAMS, values));
	if ((sp.color.r = (double)ft_atoi(values[5])) < 0x0
			|| sp.color.r > 0xFF)
		return (ft_error_free(OBJ_PARAMS, values));
	if ((sp.color.g = (double)ft_atoi(values[6])) < 0x0
			|| sp.color.g > 0xFF)
		return (ft_error_free(OBJ_PARAMS, values));
	if ((sp.color.b = (double)ft_atoi(values[7])) < 0x0
			|| sp.color.b > 0xFF)
		return (ft_error_free(OBJ_PARAMS, values));
	sp.color.a = 0;
	rt_sphere_obj(obj, rt_new_sphere(sp.pos, sp.d, sp.color));
	free_values(values);
	return (true);
}

static bool			rt_parse_cylinder_fill(t_scene *s, t_obj *obj,
		t_cyl cy, char **values)
{
	if ((cy.color.r = (double)ft_atoi(values[9])) < 0x0
			|| cy.color.r > 0xFF)
		return (ft_error_free(OBJ_PARAMS, values));
	if ((cy.color.g = (double)ft_atoi(values[10])) < 0x0
			|| cy.color.g > 0xFF)
		return (ft_error_free(OBJ_PARAMS, values));
	if ((cy.color.b = (double)ft_atoi(values[11])) < 0x0
			|| cy.color.b > 0xFF)
		return (ft_error_free(OBJ_PARAMS, values));
	rt_cyl_obj(obj, rt_new_cyl(ray2(cy.pos, cy.dir), cy.height, cy.d,
				cy.color));
	cy.color.a = 0;
	(void)s;
	if (!create_disks(s, cy, obj))
		return (ft_error_free(HEAP_ALLOC, values));
	free_values(values);
	return (true);
}

bool				rt_parse_error_cylinder(t_scene *s, t_obj *obj, char *line)
{
	t_cyl			cy;
	char			**values;

	if (!(values = split_multicharset(line, " ,")) || !frmt(&values[1], 11))
		return (values ? ft_error_free(OBJ_PARAMS, values) : ft_error(4));
	if (!values[11] || !parse_obj_bonus_properties(obj, &values[12], CYLINDER))
		return (ft_error_free(OBJ_PARAMS, values));
	cy.pos = vec3(ft_atod(values[1]), ft_atod(values[2]), ft_atod(values[3]));
	if ((cy.dir.x = ft_atod(values[4])) < -1 || cy.dir.x > 1)
		return (ft_error_free(OBJ_PARAMS, values));
	if ((cy.dir.y = ft_atod(values[5])) < -1 || cy.dir.y > 1)
		return (ft_error_free(OBJ_PARAMS, values));
	if ((cy.dir.z = ft_atod(values[6])) < -1 || cy.dir.z > 1)
		return (ft_error_free(OBJ_PARAMS, values));
	cy.dir = normalise(cy.dir);
	if ((cy.d = ft_atod(values[7])) < 0 || cy.d == INFINITY)
		return (ft_error_free(OBJ_PARAMS, values));
	if ((cy.height = ft_atod(values[8])) < 0 || cy.height == INFINITY)
		return (ft_error_free(OBJ_PARAMS, values));
	return (rt_parse_cylinder_fill(s, obj, cy, values));
}
