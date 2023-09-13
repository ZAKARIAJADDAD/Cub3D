/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:24:28 by zjaddad           #+#    #+#             */
/*   Updated: 2022/10/27 18:34:01 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	number_size(int nb, int lent)
{
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 10;
		lent++;
	}
	return (lent);
}

static char	*to_string(char *s, int nbr, int size)
{
	int	md;

	s[size] = '\0';
	size--;
	while (size > 0)
	{
		md = nbr % 10;
		s[size] = md + 48;
		nbr /= 10;
		size--;
	}
	return (s);
}

static char	*to_string_positif(char *s, int nbr, int size)
{
	int	md;

	s[size] = '\0';
	size--;
	while (size >= 0)
	{
		md = nbr % 10;
		s[size] = md + 48;
		nbr /= 10;
		size--;
	}
	return (s);
}

static char	*min_int(char *s, int nbr, int size)
{
	int	md;

	s[0] = '-';
	nbr = nbr * (-1);
	s[size] = '\0';
	s[--size] = '8';
	size--;
	nbr = 214748364;
	while (size > 0)
	{
		md = nbr % 10;
		s[size] = md + 48;
		nbr /= 10;
		size--;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*p;
	int		nb_size;
	int		sign;

	nb_size = number_size(n, 0);
	sign = 0;
	if (n < 0)
		sign = 1;
	p = malloc(nb_size + 1 + sign);
	if (!p)
		return (NULL);
	if (n == -2147483648)
		min_int(p, n, nb_size + sign);
	else if (n < 0)
	{
		p[0] = '-';
		n = n * (-1);
		to_string(p, n, nb_size + sign);
	}
	else
		to_string_positif(p, n, nb_size + sign);
	return (p);
}
