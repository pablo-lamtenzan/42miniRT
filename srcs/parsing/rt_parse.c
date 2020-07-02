/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 02:04:19 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/02 14:15:38 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parsing.h>
#include <stdlib.h>
#include <get_next_line.h>

bool			rt_parse_line_bonus(t_scene *s, char *line)
{
	if (!ft_strncmp(line, "\n", 2)) // usefull ?? have to lldb not line jump parse
		return (true);
	if (!ft_strncmp(line, "cu ", 3) || !ft_strncmp(line, "co ", 3) || !ft_strncmp(line, "py ", 3))
		return (rt_parse_obj_bonus(s, line));
	else if (!ft_strncmp(line, "aa ", 3))
		return (rt_parse_error_aa(s, line));
	else if (!ft_strncmp(line, "f ", 2))
		return (rt_parse_error_filter(s, line));
	else
		return (false);
}

bool			rt_parse_line(t_scene *scene, char *line)
{
	while (*line == ' ')
		line++;
	if (!ft_strncmp(line, "R ", 2))
		return (rt_parse_error_res(scene, line));
	else if (!ft_strncmp(line, "A ", 2) || !ft_strncmp(line, "l ", 2))
		return (rt_parse_light(scene, line));
	else if (!ft_strncmp(line, "pl ", 3) || !ft_strncmp(line, "sq ", 3) ||
			!ft_strncmp(line, "cy ", 3) || !ft_strncmp(line ,"tr ", 3) ||
			!ft_strncmp(line, "sp ", 3))
		return (rt_parse_obj(scene, line));
	else if (!ft_strncmp(line, "c ", 2))
		return (rt_parse_cam(scene, line));
	else
		return (rt_parse_line_bonus(scene, line));
}

void			rt_parse(int fd, t_scene *scene)
{
	char		*line;
	void		*aux;

	while (get_next_line(fd, &line) > 0)
	{
		if (!rt_parse_line(scene, line))
		{
			free(line);
			free_all(scene);
			exit(EXIT_FAILURE);
		}
		free(line);
	}
	if (close(fd) < 0)
	{
		free_all(scene);
		return ;
	}
	if (scene->cams)
	{
		while (scene->cams->next)
			scene->cams = scene->cams->next;
		aux = scene->cams;
		scene->cams->next = scene->cams->start;
		((t_cam *)scene->cams->next)->back = aux;
		scene->cams = scene->cams->start;
	}
	/*
	if (scene->objs)
	{
		while (scene->objs->next)
			scene->objs = scene->objs->next;
	scene->objs->next = scene->objs->start;
	}
	*/
	/* light don t have to be circular
	if (scene->lights)
	{
		while (scene->lights->next)
			scene->lights = scene->lights->next;
	scene->lights->next = scene->lights->start;
	}
	*/
}
