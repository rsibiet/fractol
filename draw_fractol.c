/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 13:55:54 by rsibiet           #+#    #+#             */
/*   Updated: 2016/02/24 16:33:29 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		julia(t_param *p, t_complexe c, t_complexe z)
{
	t_complexe	tp_c;
	int			i;
	double		tp;

	tp_c.r = c.r;
	tp_c.i = c.i;
	i = 0;
	while (i < p->iter && tp_c.r * tp_c.r + tp_c.i * tp_c.i < 4)
	{
		tp = tp_c.r;
		if (p->name[0] == '3')
			tp_c.i *= -1;
		tp_c.r = tp_c.r * tp_c.r - tp_c.i * tp_c.i + z.r;
		tp_c.i = (2 * tp * tp_c.i) + z.i;
		i++;
	}
	add_pixel_to_image(p, i, i < p->iter, 0);
}

static void		mandelbrot(t_param *p, t_complexe c)
{
	t_complexe	tp_c;
	int			i;
	double		tp;

	tp_c.r = 0;
	tp_c.i = 0;
	i = 0;
	while (i < p->iter && tp_c.r * tp_c.r + tp_c.i * tp_c.i < 4)
	{
		tp = tp_c.r;
		if (p->name[0] == '5')
			tp_c.i *= -1;
		tp_c.r = tp_c.r * tp_c.r - tp_c.i * tp_c.i + c.r;
		tp_c.i = (2 * tp * tp_c.i) + c.i;
		i++;
	}
	add_pixel_to_image(p, i, i < p->iter, 0);
}

static void		burning_ship(t_param *p, t_complexe c)
{
	t_complexe	tp_c;
	int			i;
	double		tp;

	tp_c.r = 0;
	tp_c.i = 0;
	i = 0;
	while (i < p->iter && tp_c.r * tp_c.r + tp_c.i * tp_c.i < 4)
	{
		tp = tp_c.r;
		tp_c.r = tp_c.r * tp_c.r - tp_c.i * tp_c.i + c.r;
		tp_c.i = 2 * fabs(tp_c.i) * fabs(tp) + c.i;
		i++;
	}
	add_pixel_to_image(p, i, i < p->iter, 0);
}

static void		select_fractal(t_param *p, t_complexe c)
{
	if (p->name[0] == '1' || p->name[0] == '2' || p->name[0] == '3')
		julia(p, c, p->z);
	else if (p->name[0] == '4' || p->name[0] == '5')
		mandelbrot(p, c);
	else if (p->name[0] == '6')
		burning_ship(p, c);
	else if (p->name[0] == '7')
		fractale_7(p, c, p->z);
	else if (p->name[0] == '8' || p->name[0] == '9')
		fractale_8(p, c, p->z);
}

void			draw_fractol(t_param *p)
{
	t_complexe	c;

	p->y = 0;
	c.i = p->init.i + p->pos.i;
	c.r = p->init.r + p->pos.r;
	while (p->y < HEIGHT)
	{
		p->x = 0;
		c.i = p->init.i + p->pos.i;
		while (p->x < WIDTH)
		{
			select_fractal(p, c);
			(p->x)++;
			c.i += p->zoom;
		}
		(p->y)++;
		c.r += p->zoom;
	}
}
