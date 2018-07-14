/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legend_fractol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 15:18:35 by rsibiet           #+#    #+#             */
/*   Updated: 2016/02/24 15:43:59 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				ft_motion(int x, int y, t_param *p)
{
	if (p->freeze_screen == 1 && x >= 0 && y >= 0 && x <= WIDTH && y <= HEIGHT)
	{
		p->z.r = ((double)x / (double)WIDTH * 4 - 2) / 2;
		p->z.i = ((double)y / (double)HEIGHT * 4 - 2) / 2;
		draw_fractol(p);
		mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
		create_legend(p, 0, 0, 0);
	}
	return (0);
}

static void		create_legend_2(t_param *p, int i, int j)
{
	if (p->name[0] == '5')
		mlx_string_put(p->mlx, p->win, i, j, 0x0033C1B1, "Mandelbrot rev.");
	else if (p->name[0] == '6')
		mlx_string_put(p->mlx, p->win, i, j, 0x0033C1B1, "Burning ship");
	else if (p->name[0] == '7')
		mlx_string_put(p->mlx, p->win, i, j, 0x0033C1B1, "Fractale 7");
	else if (p->name[0] == '8')
		mlx_string_put(p->mlx, p->win, i, j, 0x0033C1B1, "Fractale 8");
	else if (p->name[0] == '9')
		mlx_string_put(p->mlx, p->win, i, j, 0x0033C1B1, "Fractale 9");
	mlx_string_put(p->mlx, p->win, i -= 90, j += 20, 0x0033C1B1,
			"Zoom : mouse");
	mlx_string_put(p->mlx, p->win, i, j += 20, 0x0033C1B1,
			"Iteration nb : '+' & '-'");
	mlx_string_put(p->mlx, p->win, i, j += 20, 0x0033C1B1,
			"Move : 2, 4, 6, 8");
	mlx_string_put(p->mlx, p->win, i, j += 20, 0x0033C1B1,
			"change color : 0");
	mlx_string_put(p->mlx, p->win, i, j += 20, 0x0033C1B1,
			"freeze screen : 1");
}

void			create_legend(t_param *p, int x, int i, int j)
{
	x = WIDTH;
	i = x - 280;
	j = 145;
	while (i++ < (x - 11))
		mlx_pixel_put(p->mlx, p->win, i, j, 0x0033C1B1);
	while (j-- > 11)
		mlx_pixel_put(p->mlx, p->win, i, j, 0x0033C1B1);
	while (i-- > (x - 280))
		mlx_pixel_put(p->mlx, p->win, i, j, 0x0033C1B1);
	while (j++ < 145)
		mlx_pixel_put(p->mlx, p->win, i, j, 0x0033C1B1);
	mlx_string_put(p->mlx, p->win, i += 10, j = 15, 0x0033C1B1, "Fractal:");
	i += 90;
	if (p->name[0] == '1' || p->name[0] == '2')
		mlx_string_put(p->mlx, p->win, i, j, 0x0033C1B1, "Julia");
	else if (p->name[0] == '3')
		mlx_string_put(p->mlx, p->win, i, j, 0x0033C1B1, "Julia reverse");
	else if (p->name[0] == '4')
		mlx_string_put(p->mlx, p->win, i, j, 0x0033C1B1, "Mandelbrot");
	create_legend_2(p, i, j);
}
