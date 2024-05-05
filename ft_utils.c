/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:06:35 by mkartit           #+#    #+#             */
/*   Updated: 2024/04/26 21:06:37 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}

t_bool	ft_ishexadiigt(char c)
{
	int		i;
	char	*s;

	i = 0;
	s = "0123456789abcdef";
	while (s[i])
	{
		if (s[i] == c)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	len;

	len = 0;
	while (len < n)
	{
		if ((unsigned char)s1[len] > (unsigned char)s2[len])
			return (1);
		else if ((unsigned char)s1[len] < (unsigned char)s2[len])
			return (-1);
		else if ((unsigned char)s1[len] == 0 || (unsigned char)s2[len] == 0)
			return ((unsigned char)s1[len] - (unsigned char)s2[len]);
		len++;
	}
	return (0);
}
