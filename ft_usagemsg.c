/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usagemsg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:06:43 by mkartit           #+#    #+#             */
/*   Updated: 2024/05/01 16:59:30 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	l;

	if (fd < 0 || !s)
		return ;
	l = 0;
	while (s[l])
		write(1, &s[l++], 1);
}

void	display_menu(void)
{
	ft_putstr_fd("\n███████╗██████╗  █████╗  ██████╗████████╗ ██████╗ ██╗     \n", 1);
	ft_putstr_fd("██╔════╝██╔══██╗██╔══██╗██╔════╝╚══██╔══╝██╔═══██╗██║     \n", 1);
	ft_putstr_fd("█████╗  ██████╔╝███████║██║        ██║   ██║   ██║██║     \n", 1);
	ft_putstr_fd("██╔══╝  ██╔══██╗██╔══██║██║        ██║   ██║   ██║██║     \n", 1);
	ft_putstr_fd("██║     ██║  ██║██║  ██║╚██████╗   ██║   ╚██████╔╝███████╗\n", 1);
	ft_putstr_fd("╚═╝     ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝   ╚═╝    ╚═════╝ ╚══════╝\n", 1);
	ft_putstr_fd("\n+=================== OPTIONS MENU =================+\n", 1);
	ft_putstr_fd("exit button or 'ESC': exit the program.\n", 1);
	ft_putstr_fd("WASD or arrow keys:   to move the fractal.\n", 1);
	ft_putstr_fd("J/K:                  increase/decrease iterations.\n", 1);
	ft_putstr_fd("up/down or +/- :      zoom in/out.\n", 1);
	ft_putstr_fd("press 1 - 2 - 3:      switch fractals.\n", 1);
	ft_putstr_fd("spacebare:            change color schemes.\n", 1);
	ft_putstr_fd("Left click:           shift Julia set [Julia only].\n", 1);
	ft_putstr_fd("+====================================================+\n", 1);
}

static void	ft_display_color(void)
{
	ft_putstr_fd("\n+========= COLOR USAGE =========+\n", 1);
	ft_putstr_fd("Pick a display color by providing a hexadecimal code.\n", 1);
	ft_putstr_fd("The hex color code must be formatted as RRGGBB:\n", 1);
	ft_putstr_fd("Usage example:\n", 1);
	ft_putstr_fd("\t./fractol B FFFFFF\n", 1);
	ft_putstr_fd("\t./fractol J 0.285 0.01 123456\n", 1);
}

static void	ft_initial_usage(void)
{
	ft_putstr_fd("Usage: ./fractol [type] [julia args] [color]\n", 1);
	ft_putstr_fd("\n+========= THE AVAILABLE TYEPES =========+\n", 1);
	ft_putstr_fd("\tJ/1: Julia\n", 1);
	ft_putstr_fd("\tM/2: Mandelbrot\n", 1);
	ft_putstr_fd("\tB/3: BurningShip\n", 1);
	ft_putstr_fd("\nFor Julia, you may specify starting values for the\n", 1);
	ft_putstr_fd("initial fractal shape. Values must be between\n", 1);
	ft_putstr_fd("-2.0 and 2.0\n", 1);
	ft_putstr_fd("Usage example:\n", 1);
	ft_putstr_fd("\t./fractol J\n", 1);
	ft_putstr_fd("\t./fractol J 0.4 0.4\n", 1);
}

void	ft_usagemsg(void)
{
	ft_initial_usage();
	ft_display_color();
	exit(1);
}
