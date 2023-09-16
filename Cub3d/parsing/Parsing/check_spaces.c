/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 01:34:01 by zjaddad           #+#    #+#             */
/*   Updated: 2023/09/16 21:54:53 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	check_spaces(char *s)
{
	int		i;
	int		count;
	char	*p;

	i = -1;
	count = 0;
	p = ft_strtrim(s, " \t");
	while (p[i] != ' ' && p[i] != '\t' && p[i] != '\n')
		i++;
	while (p[i] == ' ' || p[i] == '\t')
		i++;
	while (p[i] != '\n')
	{
		if (p[i] == ' ' || p[i] == '\t')
			exit(ft_error("Error: multiple spaces insertion!\n", 2));
		i++;
	}
	free(p);
}

int	ft_atoi_m(const char *s)
{
	t_2var	var;

	var.i = 0;
	var.result = 0;
	var.sign = 1;
	while ((s[var.i] == ' ' || (s[var.i] >= 9 && s[var.i] <= 13)))
		var.i++;
	if ((s[var.i] == '+' || s[var.i] == '-') && s[var.i + 1] != '\0')
	{
		if (s[var.i] == '-')
			var.sign = -1;
		var.i++;
	}
	while (s[var.i])
	{
		if (s[var.i] < '0' || s[var.i] > '9')
			exit(ft_error("Error: Number out of range!", 2));
		var.result = var.result * 10 + (s[var.i] - 48);
		var.i++;
	}
	if (var.result > INT_MAX && var.sign == 1)
		exit(ft_error("Error: Number out of range!", 2));
	if (var.result > 2147483648 && var.sign == -1)
		exit(ft_error("Error: Number out of range!", 2));
	return (var.result * var.sign);
}
