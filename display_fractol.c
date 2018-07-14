/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_fractol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 16:26:33 by rsibiet           #+#    #+#             */
/*   Updated: 2016/02/24 15:29:34 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		key_function_2(int key, t_param *p)
{
	if (key == 69 && p->iter <= 150)
		p->iter += 1;
	if (key == 78 && p->iter > 4)
		p->iter -= 1;
}

int				key_function(int key, t_param *p)
{
	if (key == 53)
		exit(EXIT_SUCCESS);
	if (key == 91)
		p->pos.r -= p->zoom * (WIDTH / 50);
	if (key == 84)
		p->pos.r += p->zoom * (WIDTH / 50);
	if (key == 86)
		p->pos.i -= p->zoom * (HEIGHT / 50);
	if (key == 88)
		p->pos.i += p->zoom * (HEIGHT / 50);
	if (key == 82)
	{
		if (p->change_col < 6)
			p->change_col += 1;
		else
			p->change_col = 1;
	}
	if (key == 83)
		p->freeze_screen *= -1;
	key_function_2(key, p);
	draw_fractol(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	create_legend(p, 0, 0, 0);
	return (0);
}

int				mouse_function(int button, int x, int y, t_param *p)
{
	if (x == 0)
		y++;
	if (button == 1 || button == 5)
	{
		p->zoom *= 9 / 9.5;
		p->pos.r += ((y / 4 - (WIDTH / 8 - 30)) * 0.0001) * p->zoom / 0.0002;
		p->pos.i += ((x / 4 - (HEIGHT / 8 - 30)) * 0.0001) * p->zoom / 0.0002;
	}
	if (button == 2 || button == 4)
	{
		p->zoom *= 10 / 9.5;
		p->pos.r += ((y / 4 - (WIDTH / 8 - 30)) * 0.0001) * p->zoom / 0.0002;
		p->pos.i += ((x / 4 - (HEIGHT / 8 - 30)) * 0.0001) * p->zoom / 0.0002;
	}
	draw_fractol(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	create_legend(p, 0, 0, 0);
	return (0);
}

static void		ft_define_color(char *pos, t_param *p, int a, int b)
{
	int		c;

	c = 2;
	if (p->change_col == 3 || p->change_col == 4)
		a = 1;
	else if (p->change_col == 5 || p->change_col == 6)
		a = 2;
	if (p->change_col == 2 || p->change_col == 4)
		b = 2;
	else if (p->change_col == 3 || p->change_col == 5)
		b = 0;
	if (p->change_col == 2 || p->change_col == 5)
		c = 1;
	else if (p->change_col == 4 || p->change_col == 6)
		c = 0;
	*(pos + a) = 0;
	*(pos + b) = p->color >> 8;
	*(pos + c) = p->color;
}

void			add_pixel_to_image(t_param *p, int h, float l, float x)
{
	char	*pos;
	void	*mlx_ptr;

	mlx_ptr = p->mlx;
	x = l * (1.0 - fabs(h / 60.00 - 1.0));
	p->color = mlx_get_color_value(mlx_ptr, l * 255 + x * 255 * 256);
	pos = p->data + p->size_line * p->y + p->x * (p->size_line / WIDTH);
	ft_define_color(pos, p, 0, 1);
}
