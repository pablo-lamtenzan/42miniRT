/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 15:50:09 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/04 22:51:25 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <parsing.h>

char		*error_mesages(int error_code)
{
	char	*msg[14] = {};

	if (error_code == -1)
		return (" ");
	msg[0] = "\033[31mError code [01]:\n\033[0m > No valid input file\n";
	msg[1] = "\033[31mError code [02]:\n\033[0m > Invalid filename or \
		extension\n > Valid format : <filename>.rt\n";
	msg[2] = "\033[31mError code [03]:\n\033[0m > No valid number \
		of arguments\n";
	msg[3] = "\033[31mError code [04]:\n\033[0m > Something went \
		wrong during the dynamic memory allocation\n";
	msg[4] = "\033[31mError code [05]:\n\033[0m > Is not posible \
		to see anything without a cam\n";
	msg[5] = "\033[31mError code [06]:\n\033[0m > Only 1 ambient \
		light is supported\n";
	msg[6] = "\033[31mError code [07]:\n\033[0m > Light params \
		aren't supported\n";
	msg[7] = "\033[31mError code [08]:\n\033[0m > Camera params \
		aren't supported\n";
	msg[8] = "\033[31mError code [09]:\n\033[0m > Double ambiental \
		light definitions aren't allowed\n";
	msg[9] = "\033[31mError code [10]:\n\033[0m > Shape parameters \
		are bad formated\n";
	msg[10] = "\033[31mError code [11]:\n\033[0m > Antialiasing \
		just can be defined 1 time\n";
	msg[11] = "\033[31mError code [12]:\n\033[0m > Antialiasing \
		param must be only 1 and an integer\n";
	msg[12] = "\033[31mError code [13]:\n\033[0m > Only 1 filter \
		is suported choose (r/g/b/s)\n";
	msg[13] = "\033[31mError code [14]:\n\033[0m > Resolution can \
		be defined only 1 time\n";
	return (msg[error_code - 1]);
}

bool		ft_error(int error_code)
{
	ft_putstr_fd(error_mesages(error_code), 1);
	return (false);
}

bool		ft_error_free(int error_code, void *addr)
{
	if (addr)
		free_values(addr);
	ft_putstr_fd(error_mesages(error_code), 1);
	return (false);
}

bool		ft_error_free2(int error_code, void *addr1, void *addr2)
{
	if (addr1)
		free_values(addr1);
	if (addr2)
		free(addr1);
	ft_putstr_fd(error_mesages(error_code), 1);
	return (false);
}
