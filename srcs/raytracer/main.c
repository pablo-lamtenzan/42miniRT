/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 16:03:15 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/04 16:03:50 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <allocations.h>
#include <ft_error.h>
#include <stdlib.h>
#include <aux.h>

int			main(int ac, char **argv)
{
	t_scene	*scene;

	if (!(scene = rt_new_scene()) && !ft_error(HEAP_ALLOC))
		exit(EXIT_FAILURE);
	if (parser(ac, argv, scene) == true)
	{
		ft_putstr_fd("\n\n\033[35m==================\n\033[0m", 1);
		ft_putstr_fd("\033[1m\033[32m Input parsed succesfully \033[0m\n", 1);
		load_image(scene);
	}
	else
		free_all(scene);
	return (0);
}
