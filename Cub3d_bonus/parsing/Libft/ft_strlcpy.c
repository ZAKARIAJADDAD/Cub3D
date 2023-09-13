/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:39:53 by zjaddad           #+#    #+#             */
/*   Updated: 2022/10/12 01:43:53 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *d, const char *s, size_t d_size)
{
	size_t	src_l;
	size_t	i;

	src_l = ft_strlen(s);
	i = 0;
	if (d_size == 0)
	{
		return (src_l);
	}
	while (s[i] != '\0' && i < d_size - 1)
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (src_l);
}
