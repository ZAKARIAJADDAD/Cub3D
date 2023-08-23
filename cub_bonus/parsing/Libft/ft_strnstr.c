/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 23:57:27 by zjaddad           #+#    #+#             */
/*   Updated: 2022/10/27 18:39:31 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hyst, const char *ndl, size_t lent)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	if (ndl[i] == '\0')
		return ((char *)hyst);
	while (i < lent && hyst[i])
	{
		while (ndl[j] == hyst[i + j] && (i + j) < lent)
		{
			if (ndl[j + 1] == '\0')
				return ((char *)(hyst + i));
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
