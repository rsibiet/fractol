/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legend_fractol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 15:18:35 by rsibiet           #+#    #+#             */
/*   Updated: 2016/02/20 15:20:30 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		create_legend_2(t_param *p, int i, int j)
{
	j += 20;
	i -= 105;
	mlx_string_put(p->mlx, p->win, i, j, 0x0033C1B1,
		"z up : 'w'.");
	j += 20;
	mlx_string_put(p->mlx, p->win, i, j, 0x0033C1B1,
		"z down : 's'.");
	j += 20;
	mlx_string_put(p->mlx, p->win, i, j, 0x0033C1B1,
		"Zoom : '+' & '-'.");
	j += 20;
	mlx_string_put(p->mlx, p->win, i, j, 0x0033C1B1,
		"Move : 2, 4, 6, 8.");
	j += 20;
	mlx_string_put(p->mlx, p->win, i, j, 0x0033C1B1,
		"Rotation : d, g, r, f.");
	j += 20;
	mlx_string_put(p->mlx, p->win, i, j, 0x0033C1B1,
		"color off / on : 0.");
}

void			create_legend(t_param *p, int x, int y, int i)
{
	int		j;

	x = 720;
	y = 720;
	i = x - 280;
	j = 160;
	while (i++ < (x - 11))
		mlx_pixel_put(p->mlx, p->win, i, j, 0x0033C1B1);
	while (j-- > 11)
		mlx_pixel_put(p->mlx, p->win, i, j, 0x0033C1B1);
	while (i-- > (x - 280))
		mlx_pixel_put(p->mlx, p->win, i, j, 0x0033C1B1);
	while (j++ < 160)
		mlx_pixel_put(p->mlx, p->win, i, j, 0x0033C1B1);
	i += 5;
	j = 15;
	mlx_string_put(p->mlx, p->win, i, j, 0x0033C1B1, "Map name :");
	i += 110;
	mlx_string_put(p->mlx, p->win, i, j, 0x0033C1B1, p->name);
	create_legend_2(p, i, j);
}
