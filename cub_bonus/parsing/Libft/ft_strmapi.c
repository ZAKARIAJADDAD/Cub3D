/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:18:06 by zjaddad           #+#    #+#             */
/*   Updated: 2022/10/27 20:42:09 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*nw_s;

	i = 0;
	if (!s || !f)
		return (NULL);
	nw_s = malloc(ft_strlen(s) + 1);
	if (!nw_s)
		return (NULL);
	while (s[i])
	{
		nw_s[i] = f(i, s[i]);
		i++;
	}
	nw_s[i] = '\0';
	return (nw_s);
}
