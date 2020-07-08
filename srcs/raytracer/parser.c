/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 16:04:05 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/07 20:14:33 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <parsing.h>
#include <ft_error.h>

static void		no_light(t_scene *s)
{
	s->lights = rt_new_light();
	s->lights->color = set_color_precision(0x0, 0x0, 0x0);
	s->lights->intensity = 0;
	s->lights->pos = vec3(0, 0, 0);
	s->lights->next = NULL;
	s->lights->start = s->lights;
}

bool			parser(const int ac, char **argv, t_scene *s)
{
	int			fd;

	if (!check_file(ac, argv, &fd, s))
		return (false);
	rt_parse(fd, s);
	if (!(s->flags & RT_CAM))
		return (ft_error(NO_CAM));
	if (!(s->flags & RT_LIGHT))
		no_light(s);
	if (!(s->flags & RT_OBJ))
		return (ft_error(INV_INPUT));
	if (ac == 3)
	{
		if (!ft_strncmp(argv[2], "--save", 7))
			s->flags |= SAVE;
		else
			return (ft_error(INV_NB_ARGS));
	}
	return (true);
}
