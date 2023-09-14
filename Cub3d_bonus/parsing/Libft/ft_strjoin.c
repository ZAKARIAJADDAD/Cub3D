/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 23:52:19 by zjaddad           #+#    #+#             */
/*   Updated: 2023/09/13 23:39:23 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*pr;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	pr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!pr)
		return (NULL);
	while (s1[i])
	{
		pr[i] = s1[i];
		i++;
	}
	while (s2[j])
		pr[i++] = s2[j++];
	pr[i] = '\0';
	return (pr);
}
