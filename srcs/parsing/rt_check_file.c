/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 06:50:44 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/07 20:13:39 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <raytracer.h>
#include <ft_error.h>
#include <fcntl.h>
#include <aux.h>
#include <stdlib.h>

static bool			check_file_name(char *fn)
{
	int				i;

	i = 0;
	if (*fn == ' ')
		return (false);
	while (*++fn)
		*fn == '.' ? i++ : 0;
	if (i != 1)
		return (false);
	if (*(fn - 1) == 't' && *(fn - 2) == 'r' && *(fn - 3) == '.')
		return (true);
	return (false);
}

static char			*get_filename(char *namepath)
{
	char			*aux;
	int				i;

	i = 0;
	if (!(aux = ft_strdup(namepath)))
		return (NULL);
	while (aux[i] && aux[i] != '/')
		i++;
	free(aux);
	if (i >= ft_strlen(namepath) && check_file_name(namepath))
		return (namepath);
	return (get_filename(&namepath[i + 1]));
}

bool				check_file(int arc, char **argv, int *fd, t_scene *scene)
{
	if (arc >= 2 && check_file_name(argv[1]))
	{
		if (arc >= 2 && arc <= 3)
		{
			if ((*fd = open(argv[1], O_RDONLY)) < 0)
				return (ft_error(INV_INPUT));
		}
		else
			return (ft_error(INV_NB_ARGS));
		scene->filename = get_filename(argv[1]);
		ft_strlcpy(scene->filename, scene->filename, \
				ft_strlen(scene->filename) - 2);
		return (true);
	}
	return (ft_error(INV_FILENAME));
}
