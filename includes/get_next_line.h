/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 20:42:06 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/03 17:39:36 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

//typedef unsigned long		t_size;

# define TRUE				1
# define FALSE				0
# define BUFFER_SIZE		1
# define ERROR				(-1)
# define MAX_FD				1024 + 1

int							get_next_line(const int fd, char **lines);
int							f_strlen(const char *str);
char						*f_strdup(const char *src);
char						*f_strjoin(const char *s1, const char *s2);
void						f_bzero(void *str, size_t n);

#endif
