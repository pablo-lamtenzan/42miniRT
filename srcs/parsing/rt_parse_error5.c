/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_error5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 17:15:08 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/07 20:13:52 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parsing.h>
#include <ft_error.h>
#include <stdlib.h>
#include <aux.h>

static bool		frmt3(char c, int *bools)
{
	if (c == '.')
		bools[0]++;
	if (c == '-')
		bools[1]++;
	if (bools[0] > 1 || bools[1] > 1)
		return (false);
	return (true);
}

bool			frmt(char **start, int size)
{
	int			i;
	int			y;
	int			bools[2];

	i = -1;
	while (start[i] && ++i < size)
	{
		y = -1;
		bools[0] = 0;
		bools[1] = 0;
		while (start[i][++y])
		{
			if ((!ft_isdigit(start[i][y]) &&
					start[i][y] != '-' && start[i][y] != '.')
				|| (start[i][y] == '.'
					&& start[i][y + 1] && (start[i][y + 1] == '.' ||
					start[i][y + 1] == '-'))
				|| (start[i][y] == '-' && start[i][y + 1] &&
					(start[i][y + 1] == '-' || start[i][y + 1] == '.'))
				|| !frmt3(start[i][y], bools) || (start[i][y] == '-' && y != 0)
				|| (start[i][y] == '.' && y == 0))
				return (false);
		}
	}
	return (true);
}

bool			frmt2(char *line)
{
	bool		valid;
	int			i;

	i = -1;
	valid = true;
	while (line[++i])
	{
		if (line[i] == ',' && line[i + 1] &&
				(line[i + 1] == ',' || line[i + 1] == '.' ||
				(line[i + 1] == '-' && line[i + 2] &&
				line[i + 2] == ',')))
			valid = false;
	}
	if (valid == false)
		ft_error(INV_INPUT);
	return (valid);
}

bool			rt_parse_error_aa(t_scene *s, char *line)
{
	char	**values;

	if (s->flags & RT_AA)
		return (ft_error(MANY_AA));
	if (!(values = split_multicharset(line, " ,")) || !frmt(&values[1], 1))
		return (values ? ft_error_free(OBJ_PARAMS, values) : ft_error(4));
	if (!values[1] || values[2])
		return (ft_error_free(AA_PARAMS, values));
	s->aa = ft_atoi(values[1]);
	if (s->aa > 6 || s->aa < 1)
		return (ft_error_free(AA_PARAMS, values));
	s->flags |= RT_AA;
	free_values(values);
	return (true);
}

bool			rt_parse_error_filter(t_scene *s, char *line)
{
	char	**values;

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
	else
		return (ft_error_free(INV_INPUT, values));
	s->flags |= RT_FILTER;
	free_values(values);
	return (true);
}
