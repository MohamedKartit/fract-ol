/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 11:14:52 by mkartit           #+#    #+#             */
/*   Updated: 2024/04/27 11:14:55 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
		*ptr++ = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

void	exit_fractol(t_data *image)
{
	if (!image)
		exit(0);
	if (image->color_range)
		free(image->color_range);
	if (image->img)
		mlx_destroy_image(image->mlx, image->img);
	if (image->win && image->mlx)
		mlx_destroy_window(image->mlx, image->win);
	if (image->mlx)
	{
		mlx_loop_end(image->mlx);
		mlx_destroy_display(image->mlx);
		free(image->mlx);
	}
	exit(0);
}

int	end_fractol(t_data *image)
{
	exit_fractol(image);
	return (0);
}

void	ft_init(t_data *image)
{
	image->mlx = mlx_init();
	if (!image->mlx)
		(ft_putstr_fd("MLX: error initializing.", 1), exit_fractol(image));
	image->win = mlx_new_window(image->mlx, WIDTH, HEIGHT, "Fractol");
	if (!image->win)
		(ft_putstr_fd("MLX: error creating window.", 1), exit_fractol(image));
	set_limits(image);
	colors_changer(image);
}
