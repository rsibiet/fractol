/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 13:55:54 by rsibiet           #+#    #+#             */
/*   Updated: 2016/02/20 15:14:50 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_init_fractol(t_param *p)
{
	if (c[0][0] == '1')
		ft_julia_1(p);
	else if (c[0][0] == '2')
		ft_julia_2(p);
	else if (c[0][0] == '3')
		ft_julia_3(p);
	else if (c[0][0] == '4')
		ft_julia_4(p);
	else if (c[0][0] == '5')
		ft_mandelbrot(p);
	else if (c[0][0] == '6')
		ft_lapin(p);
	else if (c[0][0] == '7')
		ft_dragon(p);
	else if (c[0][0] == '8')
		ft_aaa(p);
	else if (c[0][0] == '9')
		ft_bbb(p);
}

int			key_function(int keycode, t_param *p)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	mlx_clear_window(p->mlx, p->win);
	draw_fractol(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	create_legend(p, 0, :wq0, 0);
	mlx_destroy_image(p->mlx, p->img);
	//      move_in_out(p, keycode);
	//      move_fractol(p, keycode);
	return (0);
}

static void		add_pixel_to_image(t_param *p)
{
	void		*mlx_ptr;
	size_t		pixel_ptr;

	mlx_ptr = p->mlx;
	pixel_ptr = ((WIDTH * p->y) + p->x) * (p->bpp / 8);
	p->color = mlx_get_color_value(mlx_ptr, 0xFFFFFF);
	if (p->endian == 0)
	{
		(p->data + pixel_ptr)[2] = p->color >> 16;
		(p->data + pixel_ptr)[1] = (p->color & 0x00FF00) >> 8;
		(p->data + pixel_ptr)[0] = p->color & 0x0000FF;
	}
	else
	{
		(p->data + pixel_ptr)[0] = p->color >> 16;
		(p->data + pixel_ptr)[1] = (p->color & 0x00FF00) >> 8;
		(p->data + pixel_ptr)[2] = p->color & 0x0000FF;
	}
}

static void		julia_1(t_param *p, t_complexe t)
{
	t_complexe	c;
	int		i;
	double		tp;

	c.r = 0;
	c.i = 0;
	i = 0;
	while (i < p->iter && c.r * c.r + c.i * c.i < 4)
	{
		tp = c.r;
		c.r = c.r * c.r - c.i * c.i + t.r;
		c.i = (2 * x * c.i) + t.i;
		add_pixel_to_image(p);
		i++;
	}
}

void			draw_fractol(t_param *p)
{
	t_complexe	t;

	p->y = 0;
	t.r = 0;
	t.i = 0;
	while (p->y < HEIGHT)
	{
		p->x = 0;
		while (p->x < WIDTH)
		{
			julia_1(p, t);
			(p->x)++;
			t.i += 0.001;
		}
		(p->y)++;
		t.r += 0.001;
	}
}
