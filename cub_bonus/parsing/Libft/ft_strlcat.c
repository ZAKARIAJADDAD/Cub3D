/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:02:43 by zjaddad           #+#    #+#             */
/*   Updated: 2022/10/30 14:31:33 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dt, const char *sc, size_t size_d)
{
	size_t	dst_lent;
	size_t	src_lent;
	size_t	i;

	if (!dt && size_d == 0)
		return (ft_strlen(sc));
	dst_lent = ft_strlen(dt);
	src_lent = ft_strlen(sc);
	i = 0;
	if (size_d == 0 || size_d <= dst_lent)
	{
		return (size_d + src_lent);
	}
	while (sc[i] != '\0' && i < size_d - dst_lent - 1)
	{
		dt[dst_lent + i] = sc[i];
		i++;
	}
	dt[dst_lent + i] = '\0';
	return (dst_lent + src_lent);
}
