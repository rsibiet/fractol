/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 13:46:21 by rsibiet           #+#    #+#             */
/*   Updated: 2016/02/20 15:21:23 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#define HEIGHT	720
#define WIDTH	720

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "./MinilibX/mlx.h"

/*
** struct content
*/

typedef struct	s_complexe
{
	double		r;
	double		i;
}				t_complexe;

typedef struct	s_param
{
	char		*name;
	char		*data;
	void		*mlx;
	void		*win;
	void		*img;
	int			iter;
	float		c;
	int			x;
	int			y;
	int			z;
	unsigned int		color;
	int			bpp;
	int			size_line;
	int			endian;
}				t_param;

/*
** Fonctions in error_fractol file
*/

void			error_fractol(char *c);

/*
** Fonctions in draw_fractol file
*/

void			ft_init_fractol(t_param *p);
int			key_function(int keycode, t_param *p);
void			draw_fractol(t_param *p);

/*
** Fonctions in legend_fractol file
*/

void			create_legend(t_param *p, int x, int y, int i);

#endif
