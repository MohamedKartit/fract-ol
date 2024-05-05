/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:06:50 by mkartit           #+#    #+#             */
/*   Updated: 2024/04/26 21:06:51 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	create_img(t_data *image)
{
	int		bits;
	int		line;
	int		endian;
	char	*buff;

	image->color_range = ft_calloc((image->max_iter + 1), sizeof(int));
	if (!image->color_range)
		(ft_putstr_fd("Malloc error.", 1), exit_fractol(image));
	image->img = mlx_new_image(image->mlx, WIDTH, HEIGHT);
	if (!image->img)
		(ft_putstr_fd("MLX: error creating image.", 1), exit_fractol(image));
	buff = mlx_get_data_addr(image->img, &bits, &line, &endian);
	image->addr = buff;
}

void	build_img(t_data *image)
{
	if (image->mlx && image->img)
		mlx_destroy_image(image->mlx, image->img);
	if (image->color_range)
		free(image->color_range);
	if (image->addr)
		image->addr = NULL;
	create_img(image);
}

static void	set_pixel(t_data *image, int x, int y, int color)
{
	image->addr[x * 4 + y * WIDTH * 4] = color;
	image->addr[x * 4 + y * WIDTH * 4 + 1] = color >> 8;
	image->addr[x * 4 + y * WIDTH * 4 + 2] = color >> 16;
	image->addr[x * 4 + y * WIDTH * 4 + 3] = color >> 24;
}

static int	ft_calculate_fractal(double pr, double pi, t_data *image)
{
	int	nb_iter;

	nb_iter = 0;
	if (image->set_flag == JULIA)
		nb_iter = ft_julia(pr, pi, image);
	else if (image->set_flag == MANDELBROT)
		nb_iter = ft_mandelbrot(pr, pi, image);
	else if (image->set_flag == BURNINGSHIP)
		nb_iter = ft_burningship(pr, pi, image);
	return (nb_iter);
}

void	ft_render(t_data *image)
{
	int		x;
	int		y;
	int		nb_iter;
	double	pr;
	double	pi;

	mlx_clear_window(image->mlx, image->win);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			pr = image->set.min_re + (double)x * (image->set.max_re
					- image->set.min_re) / WIDTH;
			pi = image->set.max_im + (double)y * (image->set.min_im
					- image->set.max_im) / HEIGHT;
			nb_iter = ft_calculate_fractal(pr, pi, image);
			set_pixel(image, x, y, image->color_range[nb_iter]);
		}
	}
	mlx_put_image_to_window(image->mlx, image->win, image->img, 0, 0);
}
