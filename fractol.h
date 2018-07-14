/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 13:46:21 by rsibiet           #+#    #+#             */
/*   Updated: 2016/02/24 16:02:11 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define HEIGHT	720
# define WIDTH	720
# define PTR_MOTION_MASK (1L<<6)
# define MOTION_NOTIFY 6

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "./MinilibX/mlx.h"

typedef struct		s_complexe
{
	double			r;
	double			i;
}					t_complexe;

typedef struct		s_param
{
	char			*name;
	char			*data;
	void			*mlx;
	void			*win;
	void			*img;
	int				iter;
	int				x;
	int				y;
	float			zoom;
	t_complexe		z;
	t_complexe		init;
	t_complexe		pos;
	unsigned int	color;
	int				bpp;
	int				size_line;
	int				endian;
	int				change_col;
	int				freeze_screen;
}					t_param;

/*
** Fonctions in ft_init_fractol file
*/

void				error_fractol(char *c);
void				ft_init_fractol(t_param *p);

/*
** Fonctions in ft_init_fractol_2 file
*/

void				fractale_7(t_param *p, t_complexe c, t_complexe z);
void				fractale_8(t_param *p, t_complexe c, t_complexe z);

/*
** Fonctions in draw_fractol file
*/

void				draw_fractol(t_param *p);

/*
** Fonctions in display_fractol file
*/

int					key_function(int keycode, t_param *p);
int					mouse_function(int keycode, int x, int y, t_param *p);
void				add_pixel_to_image(t_param *p, int h, float l, float x);

/*
** Fonctions in legend_fractol file
*/

int					ft_motion(int x, int y, t_param *p);
void				create_legend(t_param *p, int x, int i, int j);

#endif
