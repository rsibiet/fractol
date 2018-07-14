/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 13:48:19 by rsibiet           #+#    #+#             */
/*   Updated: 2016/02/24 15:44:18 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			display_options(void)
{
	ft_putendl_fd("\x1B[32musage: ./fractol [123456789]\n", 2);
	ft_putstr_fd("\x1B[33m1:  ", 2);
	ft_putstr_fd("\x1B[35mJulia		", 2);
	ft_putstr_fd("\x1B[33m2:  ", 2);
	ft_putendl_fd("\x1B[35mJulia 2", 2);
	ft_putstr_fd("\x1B[33m3:  ", 2);
	ft_putstr_fd("\x1B[35mJulia reverse	", 2);
	ft_putstr_fd("\x1B[33m4:  ", 2);
	ft_putendl_fd("\x1B[35mMandelbrot		", 2);
	ft_putstr_fd("\x1B[33m5:  ", 2);
	ft_putstr_fd("\x1B[35mMandelbrot reverse	", 2);
	ft_putstr_fd("\x1B[33m6:  ", 2);
	ft_putendl_fd("\x1B[35mBurning ship", 2);
	ft_putstr_fd("\x1B[33m7:  ", 2);
	ft_putstr_fd("\x1B[35mFractale 7		", 2);
	ft_putstr_fd("\x1B[33m8:  ", 2);
	ft_putendl_fd("\x1B[35mFractale 8", 2);
	ft_putstr_fd("\x1B[33m9:  ", 2);
	ft_putendl_fd("\x1B[35mFractale 9	", 2);
}

static int			control_av(int ac, char **av, int i)
{
	if (ac > 2)
		ft_putendl("\x1B[31mfractol: Too many arguments.");
	else if (ac == 1)
		ft_putendl_fd("\x1B[32mfractol:", 2);
	else if (ft_strcmp(av[1], "1") != 0 && ft_strcmp(av[1], "2") != 0 &&
		ft_strcmp(av[1], "3") != 0 && ft_strcmp(av[1], "4") != 0 &&
		ft_strcmp(av[1], "5") != 0 && ft_strcmp(av[1], "6") != 0 &&
		ft_strcmp(av[1], "7") != 0 && ft_strcmp(av[1], "8") != 0 &&
		ft_strcmp(av[1], "9") != 0)
	{
		ft_putendl("\x1B[31mfractol: illegal option -- ");
		i = 1;
	}
	if (ac > 2 || ac == 1 || i == 1)
	{
		display_options();
		return (1);
	}
	return (0);
}

static int			expose_hook(t_param *p)
{
	draw_fractol(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	create_legend(p, 0, 0, 0);
	return (0);
}

static t_param		init_param(void)
{
	t_param		p;

	p.name = NULL;
	p.mlx = NULL;
	p.win = NULL;
	p.img = NULL;
	p.bpp = 0;
	p.size_line = 0;
	p.endian = 0;
	p.data = NULL;
	p.x = 0;
	p.y = 0;
	p.change_col = 1;
	p.z.r = 0;
	p.z.i = 0;
	p.zoom = 0.0038;
	p.init.r = 0;
	p.init.i = 0;
	p.pos.r = -0.00006 * WIDTH;
	p.pos.i = -0.00003 * HEIGHT;
	p.color = 0;
	p.iter = 40;
	p.freeze_screen = 1;
	return (p);
}

int					main(int ac, char **av)
{
	t_param		p;

	p = init_param();
	if (control_av(ac, av, 0) == 1)
		return (0);
	p.name = ft_strdup(av[1]);
	ft_init_fractol(&p);
	p.mlx = mlx_init();
	p.win = mlx_new_window(p.mlx, WIDTH, HEIGHT, av[1]);
	p.img = mlx_new_image(p.mlx, WIDTH, HEIGHT);
	p.data = mlx_get_data_addr(p.img, &p.bpp, &p.size_line, &p.endian);
	mlx_expose_hook(p.win, expose_hook, &p);
	mlx_hook(p.win, 2, 1, key_function, &p);
	mlx_hook(p.win, MOTION_NOTIFY, PTR_MOTION_MASK, ft_motion, &p);
	mlx_mouse_hook(p.win, mouse_function, &p);
	mlx_loop(p.mlx);
	ft_strdel(&(p.name));
	ft_strdel_void(&(p.mlx));
	ft_strdel_void(&(p.win));
	return (0);
}
