/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 20:33:00 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/05 19:43:55 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

# include <data.h>

# define INV_INPUT		1
# define INV_FILENAME	2
# define INV_NB_ARGS	3
# define HEAP_ALLOC		4
# define NO_CAM			5
# define MANY_AMB		6
# define LIGHT_PARAMS	7
# define CAM_PARAMS		8
# define AMB_PARAMS		9
# define OBJ_PARAMS		10
# define MANY_AA		11
# define AA_PARAMS		12
# define MANY_FILTERS	13
# define MANY_RES		14

bool					ft_error(const int error_code);
bool					ft_error_free(const int error_code, void *addr);
bool					ft_error_free2(const int error_code, void *addr1,
		void *addr2);

#endif
