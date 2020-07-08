/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 20:30:45 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/08 14:24:04 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUX_H
# define AUX_H

# include <raytracer.h>
# include <unistd.h>

typedef unsigned int	t_size;

void					*ft_calloc(t_size nitems, t_size n);
int						ft_strncmp(const char *s1, const char *s2, t_size n);
int						ft_atoi(const char *str);
double					ft_atod(const char *str);
int						ft_isdigit(const int c);
void					ft_objadd_back(t_obj **alst, t_obj *nw);
void					ft_lightadd_back(t_light **alst, t_light *nw);
void					ft_camadd_back(t_cam **alst, t_cam *nw);
char					*ft_itoa(int n);
char					*ft_dtoa(double n, int precision);
char					**split_multicharset(char *str, char *charset,
		int *it_tab);
int						ft_strlen(char *str);
char					*ft_strdup(const char *src);
char					*ft_strjoin(const char *s1, const char *s2);
size_t					ft_strlcpy(char *dst, const char *src, size_t dstsize);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					ft_putstr_fd(char *s, int fd);

#endif
