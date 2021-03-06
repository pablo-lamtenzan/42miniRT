/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 21:19:42 by user42            #+#    #+#             */
/*   Updated: 2020/07/05 16:02:24 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <aux.h>
#include <stdlib.h>

int					ft_isdigit(const int c)
{
	if (c <= '9' && c >= '0')
		return (1);
	else
		return (0);
}

static unsigned int	ft_getlen(unsigned int n)
{
	unsigned int len;

	len = 1;
	while (n /= 10)
		len++;
	return (len);
}

char				*ft_itoa(int n)
{
	char			*res;
	int				i;
	char			sing;
	unsigned int	unb;

	sing = n < 0;
	unb = (sing ? -n : n);
	i = ft_getlen(unb) + sing;
	if (!(res = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	res[i] = 0;
	res[0] = '-';
	if (unb == 0)
		res[0] = '0';
	while (unb)
	{
		res[--i] = unb % 10 + '0';
		unb /= 10;
	}
	return (res);
}

char				*ft_dtoa(double n, int precision)
{
	char			*s;
	long			tmp;
	long			t;
	int				length;

	if (!precision)
		return (ft_itoa((int)n));
	tmp = (n * pow(10, precision));
	t = (tmp < 0) ? -tmp : tmp;
	length = (n <= 0 ? 3 : 2);
	while (tmp && ++length)
		tmp /= 10;
	if (!(s = (char *)malloc(sizeof(char) * length)))
		return (NULL);
	s[--length] = '\0';
	if (tmp <= 0)
		s[0] = (tmp < 0 ? '-' : '0');
	while (t)
	{
		s[--length] = (!precision--) ? '.' : t % 10 + '0';
		t /= (precision + 1) ? 10 : 1;
	}
	return (s);
}
