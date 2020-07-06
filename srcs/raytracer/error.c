/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 15:50:09 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/06 22:54:12 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <parsing.h>
#include <data.h>
#include <ft_error.h>

static char		*error_mesages_fill(const int error_code)
{
	if (error_code == OBJ_PARAMS)
		return (J);
	else if (error_code == MANY_AA)
		return (K);
	else if (error_code == AA_PARAMS)
		return (L);
	else if (error_code == MANY_FILTERS)
		return (M);
	else if (error_code == MANY_RES)
		return (N);
	return (NULL);
}

static char		*error_mesages(const int error_code)
{
	if (error_code == -1)
		return (" ");
	else if (error_code == INV_INPUT)
		return (A);
	else if (error_code == INV_FILENAME)
		return (B);
	else if (error_code == INV_NB_ARGS)
		return (C);
	else if (error_code == HEAP_ALLOC)
		return (D);
	else if (error_code == NO_CAM)
		return (E);
	else if (error_code == MANY_AMB)
		return (F);
	else if (error_code == LIGHT_PARAMS)
		return (G);
	else if (error_code == CAM_PARAMS)
		return (H);
	else if (error_code == AMB_PARAMS)
		return (I);
	else
		return (error_mesages_fill(error_code));
}

bool			ft_error(const int error_code)
{
	ft_putstr_fd(error_mesages(error_code), 1);
	return (false);
}

bool			ft_error_free(const int error_code, void *addr)
{
	if (addr)
		free_values(addr);
	ft_putstr_fd(error_mesages(error_code), 1);
	return (false);
}

bool			ft_error_free2(const int error_code, void *addr1, void *addr2)
{
	if (addr1)
		free_values(addr1);
	if (addr2)
		free(addr1);
	ft_putstr_fd(error_mesages(error_code), 1);
	return (false);
}
