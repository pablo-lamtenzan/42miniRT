/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_error4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 21:17:41 by user42            #+#    #+#             */
/*   Updated: 2020/06/30 13:47:43 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parsing.h>
#include <ft_error.h>
#include <stdlib.h>

bool        rt_parse_error_aa(t_scene *s, char *line)
{
    char    **values;

    if (s->flags & RT_AA)
        return (ft_error(MANY_AA));
    if (!(values = split_multicharset(line, " ,")))
        return (ft_error(HEAP_ALLOC));
    if (!values[1] || values[2])
        return (ft_error_free(AA_PARAMS, values));
    s->aa = ft_atoi(values[1]);
    if (s->aa > 6 || s->aa < 1)
        return (ft_error_free(AA_PARAMS, values));
    s->flags |= RT_AA;
    free(values);
    return (true);
}

bool        rt_parse_error_filter(t_scene *s, char *line)
{
    char    **values;

    if (s->flags & RT_FILTER)
        return (ft_error(MANY_FILTERS));
    if (!(values = split_multicharset(line, " ,")))
        return (ft_error(HEAP_ALLOC));
    if (!values[1] || values[2])
        return (ft_error_free(INV_INPUT, values));
    if (*values[1] == 'r')
        s->filter = RED;
    else if (*values[1] == 'g')
        s->filter = GREEN;
    else if (*values[1] == 'b')
        s->filter = BLUE;
    else if (*values[1] == 's')
        s->filter = SEPIA;
    else if (*values[1] == 'w')
        s->filter = BLACK_AND_WHITE;
    else
        return (ft_error_free(INV_INPUT, values));
    s->flags |= RT_FILTER;
    free(values);
    return (true);
}

bool        rt_parse_error_cube(t_scene *s, t_obj *obj, char *line)
{
    t_cu    cu;
    char    **values;
    
    if (!(values = split_multicharset(line, " ,")))
        return (ft_error(HEAP_ALLOC));
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
    if (!create_cube(s, obj, cu))
        return (ft_error_free2(HEAP_ALLOC, values, obj));
    free(values);
    free(obj);
    return (true);
}

bool        rt_parse_error_cone(t_obj *obj, char *line)
{
    t_co    co;
    char    **values;

    if (!(values = split_multicharset(line, " ,")))
    	return (ft_error(HEAP_ALLOC));
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
	if ((co.color.r = ft_atoi(values[9])) < 0x0 || co.color.r > 0xFF)
		return (ft_error_free(OBJ_PARAMS, values));
	if ((co.color.g = ft_atoi(values[10])) < 0x0 || co.color.g > 0xFF)
		return (ft_error_free(OBJ_PARAMS, values));
	if ((co.color.b = ft_atoi(values[11])) < 0x0 || co.color.b > 0xFF)
		return (ft_error_free(OBJ_PARAMS, values));
    rt_cone_obj(obj, rt_new_cone(ray2(co.pos, co.dir), co.curve, co.height, co.color));
    free(values);
    return (true);
}

bool        rt_parse_error_pyramid(t_scene *s, t_obj *obj, char *line)
{
    t_py    py;
    char    **values;
    
    if (!(values = split_multicharset(line, " ,")))
        
		return (ft_error_free(HEAP_ALLOC, obj));
    if (!values[11] || !parse_obj_bonus_properties(obj ,&values[12] ,PYRAMID))
        return (ft_error_free2(OBJ_PARAMS, values, obj));
    py.pos = vec3(ft_atod(values[1]), ft_atod(values[2]), ft_atod(values[3]));
    if ((py.dir.x = ft_atod(values[4])) < -1 || py.dir.x > 1)
		return (ft_error_free2(OBJ_PARAMS, values, obj));
	if ((py.dir.y = ft_atod(values[5])) < -1 || py.dir.y > 1)
		return (ft_error_free2(OBJ_PARAMS, values, obj));
	if ((py.dir.z = ft_atod(values[6])) < -1 || py.dir.z > 1)
		return (ft_error_free2(OBJ_PARAMS, values, obj));
    if ((py.base_height = ft_atod(values[7])) < 0 || py.base_height == INFINITY)
		return (ft_error_free2(OBJ_PARAMS, values, obj));
    if ((py.height = ft_atod(values[8])) < 0 || py.height == INFINITY)
		return (ft_error_free2(OBJ_PARAMS, values, obj));
	if ((py.color.r = ft_atoi(values[9])) < 0x0 || py.color.r > 0xFF)
		return (ft_error_free2(OBJ_PARAMS, values, obj));
	if ((py.color.g = ft_atoi(values[10])) < 0x0 || py.color.g > 0xFF)
		return (ft_error_free2(OBJ_PARAMS, values, obj));
	if ((py.color.b = ft_atoi(values[11])) < 0x0 || py.color.b > 0xFF)
		return (ft_error_free2(OBJ_PARAMS, values, obj));
	py.color.a = 0;
    if (!create_pyramid(s, obj, py))
        return (ft_error_free2(HEAP_ALLOC, values, obj));
    free(obj);
    free(values);
	return (true);
}