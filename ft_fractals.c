/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:07:01 by mkartit           #+#    #+#             */
/*   Updated: 2024/04/26 21:07:03 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_shift(int x, int y, t_data *image)
{
	image->set.nr = image->set.min_re + (double)x * (image->set.max_re
			- image->set.min_re) / WIDTH;
	image->set.ni = image->set.max_im + (double)y * (image->set.min_im
			- image->set.max_im) / HEIGHT;
	ft_render(image);
	return (0);
}

int	ft_julia(double zr, double zi, t_data *image)
{
	int		n;
	double	tmp;

	n = 0;
	while (n < image->max_iter)
	{
		if ((zi * zi + zr * zr) > 4.0)
			break ;
		tmp = 2 * zr * zi + image->set.ni;
		zr = zr * zr - zi * zi + image->set.nr;
		zi = tmp;
		n++;
	}
	return (n);
}

int	ft_mandelbrot(double cr, double ci, t_data *image)
{
	int		n;
	double	zr;
	double	zi;
	double	tmp;

	zr = 0;
	zi = 0;
	n = 0;
	while (n < image->max_iter)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
		n++;
	}
	return (n);
}

int	ft_burningship(double cr, double ci, t_data *image)
{
	int		n;
	double	zr;
	double	zi;
	double	tmp;

	zr = 0;
	zi = 0;
	n = 0;
	while (n < image->max_iter)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		zr = fabs(zr);
		zi = fabs(zi);
		tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
		n++;
	}
	return (n);
}
