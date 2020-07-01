/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 21:22:04 by user42            #+#    #+#             */
/*   Updated: 2020/06/28 13:52:53 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUX_H
#define AUX_H

typedef unsigned int t_size;
#include <raytracer.h>
#include <unistd.h>

void			    *ft_calloc(t_size nitems, t_size n);
int				    ft_strncmp(const char *s1, const char *s2, t_size n);
int				    ft_atoi(const char *str);
double			    ft_atod(char *str);
int				    ft_isdigit(int c);
void			    ft_objadd_back(t_obj **alst, t_obj *nw);
void			    ft_lightadd_back(t_light **alst, t_light *nw);
void			    ft_camadd_back(t_cam **alst, t_cam *nw);
char				*ft_itoa(int n);
char                *ft_dtoa(double n, int precision);
char	            **split_multicharset(char *str, char *charset);
int                 ft_strlen(char *str);
char	            *ft_strdup(const char *src);
char	            *ft_strjoin(const char *s1, const char *s2);
size_t	            ft_strlcpy(char *dst, const char *src, size_t dstsize);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_putstr_fd(char *s, int fd);

#endif