/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 09:52:23 by zjaddad           #+#    #+#             */
/*   Updated: 2022/10/28 18:00:18 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char const	*start_begin(char const *str, char const *rs)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && rs[j])
	{
		if (str[i] == rs[j])
		{
			i++;
			j = 0;
			continue ;
		}
		j++;
	}
	return (str + i);
}

static int	end_begin(char const *str, char const *rs)
{
	int	j;
	int	lent;

	j = 0;
	lent = ft_strlen(str) - 1;
	while (lent > 0 && rs[j])
	{
		if (str[lent] == rs[j])
		{
			lent--;
			j = 0;
			continue ;
		}
		j++;
	}
	return (lent);
}

char	*ft_strtrim(char const *s1, char const *setr)
{
	char const	*start_str;
	char		*res;
	int			end_index;
	int			i;

	i = 0;
	if (!s1 || !setr)
		return (NULL);
	start_str = start_begin(s1, setr);
	end_index = end_begin(start_str, setr);
	res = malloc(end_index + 2);
	if (!res)
		return (NULL);
	while (i <= end_index)
	{
		res[i] = start_str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
