/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:05:19 by mkartit           #+#    #+#             */
/*   Updated: 2024/04/26 21:05:25 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_reset_data(t_data *image)
{
	image->mlx = NULL;
	image->win = NULL;
	image->img = NULL;
	image->addr = NULL;
	image->color_range = NULL;
	image->max_iter = 100;
	image->set_flag = -1;
	image->color_flag = 0;
	image->color_shift = -1;
	image->color = 0;
	image->set.max_im = 0;
	image->set.min_im = 0;
	image->set.min_re = 0;
	image->set.max_re = 0;
	image->set.nr = -0.229000;
	image->set.ni = 0.702000;
}

void	set_limits(t_data *image)
{
	if (image->set_flag == JULIA)
	{
		image->set.min_re = -2.0;
		image->set.max_re = 2.0;
		image->set.min_im = -2.0;
		image->set.max_im = 2.0;
	}
	else
	{
		image->set.min_re = -2.0;
		image->set.max_re = 1.0;
		image->set.max_im = -1.5;
		image->set.min_im = 1.5;
	}
}

int	main(int ac, char **av)
{
	t_data	image;

	if (ac < 2)
		ft_usagemsg();
	ft_reset_data(&image);
	ft_get_choice(ac, av, &image);
	ft_init(&image);
	ft_render(&image);
	display_menu();
	mlx_hook(image.win, EVENT_CLOSE_BTN, 0, end_fractol, &image);
	mlx_key_hook(image.win, key_event, &image);
	mlx_mouse_hook(image.win, mouse_event, &image);
	mlx_loop(image.mlx);
	return (0);
}
