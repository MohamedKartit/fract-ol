/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 09:55:52 by mkartit           #+#    #+#             */
/*   Updated: 2024/04/28 09:55:53 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_data *image, double zoom)
{
	double	point_x;
	double	point_y;

	point_x = image->set.min_re - image->set.max_re;
	point_y = image->set.max_im - image->set.min_im;
	image->set.max_re = image->set.max_re + (point_x - zoom * point_x) / 2;
	image->set.min_re = image->set.max_re + zoom * point_x;
	image->set.min_im = image->set.min_im + (point_y - zoom * point_y) / 2;
	image->set.max_im = image->set.min_im + zoom * point_y;
}

void	move(t_data *image, double distance, char direction)
{
	double	center_r;
	double	center_i;

	center_r = image->set.max_re - image->set.min_re;
	center_i = image->set.max_im - image->set.min_im;
	if (direction == 'R')
	{
		image->set.min_re += center_r * distance;
		image->set.max_re += center_r * distance;
	}
	else if (direction == 'L')
	{
		image->set.min_re -= center_r * distance;
		image->set.max_re -= center_r * distance;
	}
	else if (direction == 'D')
	{
		image->set.min_im -= center_i * distance;
		image->set.max_im -= center_i * distance;
	}
	else if (direction == 'U')
	{
		image->set.min_im += center_i * distance;
		image->set.max_im += center_i * distance;
	}
}
