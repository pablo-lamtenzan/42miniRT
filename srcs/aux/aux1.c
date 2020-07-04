/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 21:18:27 by user42            #+#    #+#             */
/*   Updated: 2020/07/04 14:40:46 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <aux.h>
#include <stdlib.h>

static void				ft_bzero(void *str, t_size n)
{
	unsigned char		*start;

	start = str;
	while (n-- > 0)
		*start++ = 0;
}

void					*ft_calloc(t_size nitems, t_size n)
{
	void				*p;

	if (!(p = malloc(nitems * n)))
		return (NULL);
	ft_bzero(p, nitems * n);
	return (p);
}

int						ft_strncmp(const char *s1, const char *s2, t_size n)
{
	t_size				i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int						ft_atoi(const char *str)
{
	int					i;
	unsigned long int	nb;
	int					sing;
	char				*s;

	sing = 1;
	nb = 0;
	i = 0;
	s = (char *)str;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sing = -sing;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
		nb = nb * 10 + s[i++] - '0';
	if ((sing > 0 && nb <= 9223372036854775807L) ||
			(sing < 0 && nb <= 9223372036854775808UL))
		return (sing * nb);
	return (sing < 0 ? 0 : -1);
}

double					ft_atod(char *str)
{
	int					i;
	int					sign;
	double				db;
	int					decimal;

	decimal = 0;
	sign = str[0] == '-' ? -1 : 1;
	db = 0;
	i = sign < 0 ? 1 : 0;
	if (str[0] == '0' && str[1] == '\0')
		return (0);
	while (ft_isdigit(str[i]))
		db = db * 10 + (str[i++] - '0');
	if (str[i] == '.')
		i++;
	while (ft_isdigit(str[i]))
	{
		db = db * 10 + (str[i++] - '0');
		decimal++;
	}
	while (decimal--)
		db /= 10;
	return (db * sign);
}
