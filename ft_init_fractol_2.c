/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_fractol_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 11:48:48 by rsibiet           #+#    #+#             */
/*   Updated: 2016/02/24 15:49:34 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractale_8(t_param *p, t_complexe c, t_complexe z)
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
		if (p->name[0] == '9')
			tp_c.i *= -1;
		tp_c.r = tp_c.r * tp_c.r - tp_c.i * tp_c.i + z.r;
		tp_c.i = 2 * tp_c.i * fabs(tp) + z.i;
		i++;
	}
	add_pixel_to_image(p, i, i < p->iter, 0);
}

void	fractale_7(t_param *p, t_complexe c, t_complexe z)
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
		tp_c.r = tp_c.r * tp_c.r - tp_c.i * tp_c.i + z.r;
		tp_c.i = 2 * fabs(tp_c.i) * tp + z.i;
		i++;
	}
	add_pixel_to_image(p, i, i < p->iter, 0);
}
