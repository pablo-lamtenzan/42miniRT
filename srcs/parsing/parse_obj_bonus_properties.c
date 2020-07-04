/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj_bonus_properties.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 16:55:52 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/04 22:39:50 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parsing.h>
#include <stdlib.h>
#include <ft_error.h>

bool			parse_damier(t_obj *obj, char **values)
{
	if (!frmt(&values[1], 4) || values[5])
		return (false);
	if ((obj->color_damier.r = (double)ft_atoi(values[1])) < 0x0
			|| obj->color_damier.r > 0xff)
		return (false);
	if ((obj->color_damier.g = (double)ft_atoi(values[2])) < 0x0
			|| obj->color_damier.r > 0xff)
		return (false);
	if ((obj->color_damier.b = (double)ft_atoi(values[3])) < 0x0
			|| obj->color_damier.r > 0xff)
		return (false);
	if ((obj->ch = ft_atoi(values[4]) > 40))
		obj->ch = 40;
	else if (ft_atod(values[4]) < 0)
		return (false);
	obj->effect |= DAMIER;
	return (true);
}

bool			parse_rainbow(t_obj *obj, char **values)
{
	if (!frmt(&values[1], 1) || values[2])
		return (false);
	if ((obj->rainbow = ft_atod(values[1])) < 0.000 || obj->rainbow > 1.000)
		return (false);
	obj->effect |= RAINBOW;
	return (true);
}

static bool		parse_textures_fill(t_obj *obj, t_uvmap *map,
		char **values, int i)
{
	int			aux;
	char		s[255];

	ft_strlcpy(s, values[1] + 1, i + 4);
	if (!(map->addr = mlx_xpm_file_to_image(obj->mlx_ptr, \
					s, &map->x, &map->y))
				|| !(map->img = (t_color *)mlx_get_data_addr(map->addr, \
						&aux, &aux, &aux)))
		return (false);
	// nb of thread = 1 ? 
	obj->uvmap = map;
	obj->effect |= UVMAPPING;
	return (true);
}

bool			parse_textures(t_obj *obj, char **values)
{
	int			i;
	t_uvmap		*map;

	i = 0;
	if (values[2])
		return (false);
	if (values[1][i] == '"')
		i++;
	else
		return (false);
	while (((values[1][i] >= 'a' && values[1][i] <= 'z') ||
			values[1][i] == '/' || (values[1][i] >= '0' &&
				values[1][i] <= '9')) && values[1][i] != '.')
		i++;
	if (!(values[1][i + 4] && values[1][i] == '.' && values[1][i + 1] == 'x'
			&& values[1][i + 2] == 'p' && values[1][i + 3] == 'm' &&
			values[1][i + 4] == '"' && !values[1][i + 5]) || values[2])
		return (false);
	if (i + 3 > 256)
		return (false);
	if ((map = malloc(sizeof(t_uvmap))))
		return (parse_textures_fill(obj, map, values, i));
	return (false);
}

bool			parse_obj_bonus_properties(t_obj *obj, char **values, int id)
{
	if (!values || !values[0])
		return (true);
	else if ((!ft_strncmp(values[0], "d", 2) || !ft_strncmp(values[0], "D", 2))
			&& id != SPHERE && id != CYLINDER)
		return (parse_damier(obj, values));
	else if (!ft_strncmp(values[0], "r", 2) || !ft_strncmp(values[0], "R", 2))
		return (parse_rainbow(obj, values));
	else if ((!ft_strncmp(values[0], "tx", 3) ||
			!ft_strncmp(values[0], "TX", 3)) && id == SPHERE)
		return (parse_textures(obj, values));
	else if (!ft_strncmp(values[0], "m", 1) || !ft_strncmp(values[0], "M", 1))
	{
		obj->effect |= MIRROR;
		if (values[1] || values[0][1])
			return (false);
	}
	else if (values[0][0] >= 'A' && values[0][0] <= 'Z')
	{
		obj->effect |= NORMAL_DIST;
		if (values[1] || values[0][1])
			return (false);
	}
	else
		return (false);
	return (true);
}
