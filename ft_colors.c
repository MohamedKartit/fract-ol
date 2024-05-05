/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:06:14 by mkartit           #+#    #+#             */
/*   Updated: 2024/04/26 21:06:16 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fill_color(t_data *image, int color, int strip)
{
	int	i;

	i = 0;
	while (i < image->max_iter)
	{
		image->color_range[i] = color;
		i += strip;
	}
}

static void	more_colors(t_data *image)
{
	int	c;

	c = ft_lighter(image->color, 50);
	if (image->color_shift == 2)
	{
		if (image->color == 0x000000)
			c = 0xDCDCDC;
		fill_color(image, c, 1);
		fill_color(image, image->color, 2);
		image->color_range[image->max_iter - 1] = 0;
	}
	else
		color_2(image, (int [8]){0xFF0000, 0xFF7F00, 0xFFFF00,
			0x00FF00, 0x0000FF, 0x4B0082, 0x9400D3, 0xFFFFFF}, 8);
}

void	colors_changer(t_data *image)
{
	int	defaul_color;

	image->color_shift = (image->color_shift + 1) % 4;
	build_img(image);
	if (image->color == 0x000000)
		defaul_color = 0x444444;
	else
		defaul_color = image->color;
	if (image->color_shift == 0)
		color_1(image, defaul_color);
	else if (image->color_shift == 1)
		color_2(image, (int [4]){0x000000, defaul_color,
			ft_lighter(image->color, 50), 0xFFFFFF}, 4);
	else
		more_colors(image);
}
