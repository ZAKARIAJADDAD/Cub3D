/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:40:52 by zjaddad           #+#    #+#             */
/*   Updated: 2022/10/27 18:38:54 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *vp, int c, size_t lent)
{
	size_t	i;

	i = 0;
	while (i < lent)
	{
		((unsigned char *)vp)[i] = (unsigned char)c;
		i++;
	}
	return (vp);
}
