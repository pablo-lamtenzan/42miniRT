/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 15:50:09 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/05 19:20:35 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <parsing.h>
#include <data.h>

static char		*error_mesages_fill(const int error_code)
{
	if (error_code == 9)
		return (J);
	else if (error_code == 10)
		return (K);
	else if (error_code == 11)
		return (L);
	else if (error_code == 12)
		return (M);
	else if (error_code == 13)
		return (N);
	return (NULL);
}

static char		*error_mesages(const int error_code)
{
	if (error_code == -1)
		return (" ");
	else if (error_code == 0)
		return (A);
	else if (error_code == 1)
		return (B);
	else if (error_code == 2)
		return (C);
	else if (error_code == 3)
		return (D);
	else if (error_code == 4)
		return (E);
	else if (error_code == 5)
		return (F);
	else if (error_code == 6)
		return (G);
	else if (error_code == 7)
		return (H);
	else if (error_code == 8)
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
