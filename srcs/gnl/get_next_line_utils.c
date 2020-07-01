/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:24:44 by plamtenz          #+#    #+#             */
/*   Updated: 2020/06/26 20:57:14 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

int		f_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*f_strdup(const char *src)
{
	char		*s;
	int			src_size;
	int			i;
	char		*copy;
	char		*start;

	i = 0;
	src_size = 0;
	s = (char *)src;
	while (src[src_size])
		src_size++;
	copy = malloc(sizeof(char) * (src_size + 1));
	if (copy == NULL)
		return (NULL);
	start = copy;
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	start[i] = '\0';
	return (start);
}

char	*f_strjoin(const char *s1, const char *s2)
{
	char	*res;
	int		i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(res = malloc(sizeof(char) * (f_strlen(s1) + f_strlen(s2) + 1))))
		return (NULL);
	while (*s1)
		res[i++] = *s1++;
	while (*s2)
		res[i++] = *s2++;
	res[i++] = '\0';
	return (res);
}

void	f_bzero(void *str, size_t n)
{
	unsigned char *start;

	start = str;
	while (n--)
		*start++ = 0;
}
