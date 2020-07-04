/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:36:55 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/04 14:49:17 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <aux.h>
#include <stdlib.h>

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*temp;

	if (!dst && !src)
		return (0);
	temp = dst;
	while (n--)
		*temp++ = *(char *)src++;
	return (dst);
}

void			ft_putstr_fd(char *s, int fd)
{
	if (s != NULL)
		write(fd, s, ft_strlen(s));
}

void			ft_objadd_back(t_obj **alst, t_obj *nw)
{
	t_obj		*last;

	if (alst)
	{
		if (!*alst)
		{
			*alst = nw;
			(*alst)->start = nw;
		}
		else
		{
			nw->start = (*alst)->start;
			last = (*alst);
			while (last->next)
				last = last->next;
			last->next = nw;
			nw->back = last;
			nw->next = NULL;
		}
	}
}

void			ft_lightadd_back(t_light **alst, t_light *nw)
{
	t_light		*last;

	if (alst)
	{
		if (!*alst)
		{
			*alst = nw;
			(*alst)->start = nw;
		}
		else
		{
			nw->start = (*alst)->start;
			last = *alst;
			while (last->next)
				last = last->next;
			last->next = nw;
		}
	}
}

void			ft_camadd_back(t_cam **alst, t_cam *nw)
{
	t_cam		*last;

	if (alst)
	{
		if (!*alst)
		{
			*alst = nw;
			(*alst)->start = nw;
		}
		else
		{
			nw->start = (*alst)->start;
			last = *alst;
			while (last->next)
				last = last->next;
			last->next = nw;
			nw->back = *alst;
		}
	}
}
