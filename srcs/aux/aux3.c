/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 12:34:00 by user42            #+#    #+#             */
/*   Updated: 2020/07/04 14:46:54 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <aux.h>
#include <stdlib.h>

int				ft_strlen(char *str)
{
	char		*addr;

	addr = str;
	while (*str)
		str++;
	return (str - addr);
}

char			*ft_strdup(const char *src)
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

char			*ft_strjoin(const char *s1, const char *s2)
{
	char		*res;
	int			i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(res = malloc(sizeof(char) * (ft_strlen((char *)s1) + \
		ft_strlen((char *)s2) + 1))))
		return (NULL);
	while (*s1)
		res[i++] = *s1++;
	while (*s2)
		res[i++] = *s2++;
	res[i++] = '\0';
	return (res);
}

size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		count;
	size_t		size;

	count = 0;
	size = 0;
	if (!dst)
		return (0);
	while (src[size])
		size++;
	if (!dstsize)
		return (size);
	while (src[count] && count < dstsize - 1)
	{
		dst[count] = src[count];
		count++;
	}
	dst[count] = '\0';
	return (size);
}
