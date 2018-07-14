/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_fractol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 11:41:34 by rsibiet           #+#    #+#             */
/*   Updated: 2016/02/24 16:35:12 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			error_fractol(char *c)
{
	ft_putstr_fd("fractol: ", 2);
	ft_putstr_fd(c, 2);
	perror(" ");
	exit(EXIT_FAILURE);
}

static void		ft_init_julia_1(t_param *p)
{
	p->z.r = 0.3;
	p->z.i = 0.5;
	p->init.r = p->pos.r - HEIGHT / 2 * p->zoom;
	p->init.i = p->pos.i - WIDTH / 2 * p->zoom;
}

static void		ft_init_julia_2(t_param *p)
{
	p->z.r = 0.285;
	p->z.i = 0.01;
	p->init.r = p->pos.r - HEIGHT / 2 * p->zoom;
	p->init.i = p->pos.i - WIDTH / 2 * p->zoom;
}

static void		ft_init_mandelbrot(t_param *p)
{
	p->init.r = p->pos.r - HEIGHT / 2 * p->zoom;
	p->init.i = p->pos.i - WIDTH / 2 * p->zoom;
}

void			ft_init_fractol(t_param *p)
{
	if (p->name[0] == '1' || (p->name[0] >= '7' && p->name[0] <= '9'))
		ft_init_julia_1(p);
	else if (p->name[0] == '2' || p->name[0] == '3')
		ft_init_julia_2(p);
	else if (p->name[0] == '4' || p->name[0] == '5' || p->name[0] == '6')
		ft_init_mandelbrot(p);
}
