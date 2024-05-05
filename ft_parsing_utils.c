/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 10:34:53 by mkartit           #+#    #+#             */
/*   Updated: 2024/04/27 10:34:54 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_escape_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	return (i);
}

double	ft_atof(char *str)
{
	double	res;
	double	dec;
	int		i;
	int		sign;

	res = 0;
	dec = 0.1;
	sign = 1;
	i = ft_escape_spaces(str);
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (str[i] && str[i] != '.')
		res = res * 10 + str[i++] - '0';
	if (str[i] == '.')
		i++;
	while (str[i])
	{
		res = res + (str[i] - '0') * dec;
		dec *= 0.1;
		i++;
	}
	return (res * sign);
}

int	ft_ato_color(char *str)
{
	int	color;
	int	i;

	i = 0;
	color = 0;
	while (str[i] && ft_ishexadiigt(ft_tolower(str[i])))
	{
		if (str[i] >= '0' && str[i] <= '9')
			color = color * 16 + str[i] - '0';
		else
			color = color * 16 + ft_tolower(str[i]) - 'a' + 10;
		i++;
	}
	return (color);
}
