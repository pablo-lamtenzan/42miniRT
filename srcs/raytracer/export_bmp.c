/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_bmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 15:50:43 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/05 00:18:11 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <allocations.h>
#include <fcntl.h>
#include <aux.h>
#include <stdlib.h>

void					init_bmp(unsigned char *header, unsigned char *data,
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

void					write_bmp(t_scene *s, unsigned char *header,
		unsigned char *data, unsigned char *padding)
{
	int					fd;
	unsigned char		*data__;
	char				*extension[2];
	int					i;

	i = -1;
	extension[0] = ft_strdup(".bmp");
	if ((fd = open((extension[1] = ft_strjoin(s->filename, extension[0])), O_CREAT | \
			O_RDWR, 0666)) < 0)
	{
		free(extension[0]);
		free(extension[1]);
		return ;
	}
	(void)write(fd, header, 14);
	(void)write(fd, data, 40);
	if (!(data__ = malloc(s->image->max_w * s->image->max_h * 3 * \
			sizeof(unsigned char))))
	{
		(void)close(fd);
		return ;
	}
	while (++i < s->image->max_w * s->image->max_h)
	{
		data__[i * 3] = s->image->end_buff[i].chanel.b;
		data__[i * 3 + 1] = s->image->end_buff[i].chanel.g;
		data__[i * 3 + 2] = s->image->end_buff[i].chanel.r;
	}
	i = -1;
	while (++i < s->image->max_h)
	{
		(void)write(fd, &data__[0] + (s->image->max_w * \
				(s->image->max_h - i - 1) * 3), 3 * s->image->max_w);
		(void)write(fd, padding, (4 - (s->image->max_w * 3) % 4) % 4);
	}
	free(data__);
	free(extension[0]);
	free(extension[1]);
	(void)close(fd);
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
