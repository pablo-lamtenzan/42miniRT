/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 19:04:58 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/05 19:47:20 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# define A	"\033[31mError code [01]:\\n\033[0m > No valid input file\n"
# define B	"\033[31mError code [02]:\n\033[0m > Invalid file name or format\n"
# define C	"\033[31mError code [03]:\n\033[0m > Invalid argument\n"
# define D 	"\033[31mError code [04]:\n\033[0m > Dynamic allocation failed\n"
# define E	"\033[31mError code [05]:\n\033[0m > No camera, need almost one\n"
# define F	"\033[31mError code [06]:\n\033[0m > Can't handle more than 1 A\n"
# define G	"\033[31mError code [07]:\n\033[0m > Format of light corrupted\n"
# define H	"\033[31mError code [08]:\n\033[0m > Format of camera corrupted\n"
# define I	"\033[31mError code [09]:\n\033[0m > Double ambiental light\n"
# define J	"\033[31mError code [10]:\n\033[0m > Shape params are corrupted\n"
# define K	"\033[31mError code [11]:\n\033[0m > Can't handle more than 1 aa\n"
# define L	"\033[31mError code [12]:\n\033[0m > aa [int]\n"
# define M	"\033[31mError code [13]:\n\033[0m > f r/f g/f b/f s only\n"
# define N	"\033[31mError code [14]:\n\033[0m > Can't handle more than 1 R\n"

# define O	"TYPE = SPHERE\n"
# define P	"TYPE = SQUARE\n"
# define Q	"TYPE = CYLINDER\n"
# define R	"TYPE = TRIANGLE\n"
# define S	"TYPE = PLANE\n"
# define T	"TYPE = CUBE\n"
# define U	"TYPE = CONE\n"
# define V	"TYPE = PYRAMID\n"

#endif
