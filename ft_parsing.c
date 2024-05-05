/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:06:56 by mkartit           #+#    #+#             */
/*   Updated: 2024/04/26 21:06:57 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_bool	args_checker(char *av, char *str, char c, char n)
{
	int	i;

	i = -1;
	while (av[++i])
		av[i] = ft_tolower(av[i]);
	if (ft_strncmp(av, str, ft_strlen(str) - 1) == 0)
		return (TRUE);
	i = 0;
	if ((!av[1] && c == ft_tolower(av[i])) || (av[i] == n && !av[1]))
		return (TRUE);
	return (FALSE);
}

static void	check_color(int ac, char **av, t_data *image, int flg)
{
	int	i;

	i = 0;
	if (ac >= 3)
	{
		if (ft_strlen(av[ac - 1]) != 6)
		{
			if (flg)
				return ;
			ft_usagemsg();
		}
		while (av[ac - 1][i])
		{
			if (!ft_ishexadiigt(ft_tolower(av[ac - 1][i++])))
			{
				if (flg)
					return ;
				ft_usagemsg();
			}
		}
		image->color_flag = 1;
	}
}

static t_bool	check_julia_inputs(char **av)
{
	int	point_flag;
	int	i;
	int	j;

	point_flag = 1;
	i = 1;
	j = 0;
	while (++i < 3)
	{
		if (av[i][j] == '-' || av[i][j] == '+')
			j++;
		while (av[i][j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9') && !point_flag)
				return (FALSE);
			if (av[i][j] == '.')
				point_flag = 0;
			j++;
		}
		j = 0;
	}
	return (TRUE);
}

static void	ft_check_julia_ops(int ac, char **av, t_data *image)
{
	if ((ac == 3 && image->color_flag == 1) || ac == 2)
	{
		image->set.nr = -0.229000;
		image->set.ni = 0.702000;
	}
	else if (ac > 3 && ac < 6)
	{
		if (ac == 4)
		{
			if (image->color_flag == 1)
				ft_usagemsg();
		}
		if (!check_julia_inputs(av) || (ac == 5 && !(image->color_flag)))
			ft_usagemsg();
		image->set.nr = ft_atof(av[2]);
		image->set.ni = ft_atof(av[3]);
		if (image->set.nr < -2 || image->set.nr > 2 || image->set.ni < -2
			|| image->set.ni > 2)
			ft_usagemsg();
	}
	else
		ft_usagemsg();
}

void	ft_get_choice(int ac, char **av, t_data *image)
{
	image->color_flag = 0;
	if (args_checker(av[1], "mandelbrot", 'm', '2') && ac <= 3)
	{
		image->set_flag = MANDELBROT;
		check_color(ac, av, image, 0);
	}
	else if (args_checker(av[1], "burningship", 'b', '3') && ac <= 3)
	{
		image->set_flag = BURNINGSHIP;
		check_color(ac, av, image, 0);
	}
	else if (args_checker(av[1], "julia", 'j', '1') && ac <= 5)
	{
		image->set_flag = JULIA;
		check_color(ac, av, image, 1);
		ft_check_julia_ops(ac, av, image);
	}
	else
		ft_usagemsg();
	if (image->color_flag)
		image->color = ft_ato_color(av[ac - 1]);
	else
		image->color = 0x123456;
}
