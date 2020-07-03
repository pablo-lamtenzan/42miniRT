/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 18:33:45 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/03 21:23:13 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <parsing.h>
#include <ft_error.h>

bool        parser(int ac, char **argv, t_scene *s)
{
    int fd;
    
    if (!check_file(ac, argv, &fd, s))
        return (false);
    rt_parse(fd, s);
	if (!(s->flags & RT_CAM))
		return(ft_error(NO_CAM));
	if (!(s->flags & RT_LIGHT))
		return (ft_error(INV_INPUT));
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