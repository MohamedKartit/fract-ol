/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:06:22 by mkartit           #+#    #+#             */
/*   Updated: 2024/04/26 21:06:23 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	key_change_fractal(int keycode, t_data *image)
{
	if (keycode == KEY_ONE && image->set_flag != JULIA)
		image->set_flag = JULIA;
	else if (keycode == KEY_TWO && image->set_flag != MANDELBROT)
		image->set_flag = MANDELBROT;
	else if (keycode == KEY_THREE && image->set_flag != BURNINGSHIP)
		image->set_flag = BURNINGSHIP;
	else
		return (1);
	set_limits(image);
	ft_render(image);
	return (0);
}

static int	key_press(int keycode, t_data *image)
{
	if (keycode == KEY_UP || keycode == KEY_W)
		move(image, 0.1, 'U');
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		move(image, 0.1, 'D');
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		move(image, 0.1, 'L');
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		move(image, 0.1, 'R');
	else if (keycode == KEY_J)
		image->max_iter += 5;
	else if (keycode == KEY_K)
		image->max_iter -= 5;
	else
		return (1);
	ft_render(image);
	return (0);
}

int	key_event(int keycode, t_data *image)
{
	if (keycode == KEY_ESC)
	{
		end_fractol(image);
		return (0);
	}
	else if (keycode == KEY_PLUS)
		zoom(image, 0.5);
	else if (keycode == KEY_MINUS)
		zoom(image, 2);
	else if (keycode == KEY_SPACE)
		colors_changer(image);
	else if (!key_press(keycode, image))
		return (1);
	else if (!key_change_fractal(keycode, image))
		return (1);
	else
		return (1);
	ft_render(image);
	return (0);
}

int	mouse_event(int keycode, int x, int y, t_data *image)
{
	if (keycode == MOUSE_WHEEL_UP)
	{
		zoom(image, 0.5);
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
		if (x < 0)
			move(image, (double)x * -1 / WIDTH, 'L');
		else if (x > 0)
			move(image, (double)x / WIDTH, 'R');
		if (y < 0)
			move(image, (double)y * -1 / HEIGHT, 'U');
		else if (y > 0)
			move(image, (double)y / HEIGHT, 'D');
	}
	else if (keycode == MOUSE_WHEEL_DOWN)
		zoom(image, 2);
	else if (keycode == MOUSE_BTN)
	{
		if (image->set_flag == JULIA)
			julia_shift(x, y, image);
	}
	else
		return (0);
	ft_render(image);
	return (0);
}
