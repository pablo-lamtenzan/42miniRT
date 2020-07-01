/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 18:33:45 by plamtenz          #+#    #+#             */
/*   Updated: 2020/06/30 21:18:00 by plamtenz         ###   ########.fr       */
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
    if (ac == 3 && !ft_strncmp(argv[2], "--save", 7))
        s->flags |= SAVE;
    return (true);
}