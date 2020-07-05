/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_bmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 15:50:43 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/05 18:10:14 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <allocations.h>
#include <fcntl.h>
#include <aux.h>
#include <stdlib.h>

static void				init_bmp(unsigned char *header, unsigned char *data,
		unsigned char *padding)
{
	int					i;

	i = 1;
	header[0] = 'B';
	header[1] = 'M';
	while (++i < 10)
		header[i] = 0;
	header[i] = 54;
	while (++i < 14)
		header[i] = 0;
	i = 0;
	data[0] = 40;
	while (++i < 40)
		data[i] = 0;
	data[12] = 1;
	data[14] = 24;
	data[15] = 0;
	i = -1;
	while (++i < 3)
		padding[i] = 0;
}

static void				write_bmp_fill(t_scene *s, t_bmp b,
		const unsigned char *padding)
{
	while (++b.i < s->image->max_w * s->image->max_h)
	{
		b.data__[b.i * 3] = s->image->end_buff[b.i].chanel.b;
		b.data__[b.i * 3 + 1] = s->image->end_buff[b.i].chanel.g;
		b.data__[b.i * 3 + 2] = s->image->end_buff[b.i].chanel.r;
	}
	b.i = -1;
	while (++b.i < s->image->max_h)
	{
		(void)write(b.fd, &b.data__[0] + (s->image->max_w * \
				(s->image->max_h - b.i - 1) * 3), 3 * s->image->max_w);
		(void)write(b.fd, padding, (4 - (s->image->max_w * 3) % 4) % 4);
	}
	free(b.data__);
	free(b.extension[0]);
	free(b.extension[1]);
	free(b.extension[2]);
	free(b.extension[3]);
	(void)close(b.fd);
}

static void				write_bmp(t_scene *s, const unsigned char *header,
		const unsigned char *data, const unsigned char *padding)
{
	t_bmp b;

	b.i = -1;
	b.extension[0] = ft_strdup(".bmp");
	b.extension[2] = ft_strdup("images/");
	if ((b.fd = open(\
			(b.extension[3] = ft_strjoin(b.extension[2], \
			(b.extension[1] = ft_strjoin(s->filename, b.extension[0])))), \
				O_CREAT | O_RDWR, 0666)) < 0)
	{
		free(b.extension[0]);
		free(b.extension[1]);
		return ;
	}
	(void)write(b.fd, header, 14);
	(void)write(b.fd, data, 40);
	if (!(b.data__ = malloc(s->image->max_w * s->image->max_h * 3 * \
			sizeof(unsigned char))))
	{
		(void)close(b.fd);
		return ;
	}
	write_bmp_fill(s, b, padding);
}

void					export_bmp(t_scene *s)
{
	unsigned char		header[14];
	unsigned char		data[40];
	unsigned char		padding[3];
	int					total_bytes;

	init_bmp(header, data, padding);
	total_bytes = 54 + 3 * s->image->max_w * s->image->max_h;
	header[2] = (unsigned char)total_bytes;
	header[3] = (unsigned char)(total_bytes >> 8);
	header[4] = (unsigned char)(total_bytes >> 16);
	header[5] = (unsigned char)(total_bytes >> 24);
	data[4] = (unsigned char)s->image->max_w;
	data[5] = (unsigned char)(s->image->max_w >> 8);
	data[6] = (unsigned char)(s->image->max_w >> 16);
	data[7] = (unsigned char)(s->image->max_w >> 24);
	data[8] = (unsigned char)s->image->max_h;
	data[9] = (unsigned char)(s->image->max_h >> 8);
	data[10] = (unsigned char)(s->image->max_h >> 16);
	data[11] = (unsigned char)(s->image->max_h >> 24);
	write_bmp(s, header, data, padding);
	free_all(s);
}
