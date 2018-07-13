/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_fractol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 13:03:54 by rsibiet           #+#    #+#             */
/*   Updated: 2016/02/19 13:22:35 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_fractol(char *c)
{
	ft_putstr_fd("fractol: ", 2);
	ft_putstr_fd(c, 2);
	perror(" ");
	exit(EXIT_FAILURE);
}
