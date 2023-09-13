/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 01:12:59 by zjaddad           #+#    #+#             */
/*   Updated: 2022/10/28 17:55:56 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t lent)
{
	char	*sc;
	char	*dt;

	sc = (char *)src;
	dt = (char *)dest;
	if (dt < sc)
	{
		ft_memcpy(dt, sc, lent);
	}
	else if (dt > sc)
	{
		while (lent--)
		{
			dt[lent] = sc[lent];
		}
	}
	return (dt);
}
