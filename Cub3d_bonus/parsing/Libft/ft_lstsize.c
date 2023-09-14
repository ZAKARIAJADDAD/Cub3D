/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:44:41 by zjaddad           #+#    #+#             */
/*   Updated: 2023/09/13 23:46:31 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*lent;
	int		i;

	i = 0;
	if (lst)
	{
		lent = malloc(sizeof(t_list));
		if (!lent)
			return (0);
		lent = lst;
		while (lent)
		{
			lent = lent->next;
			i++;
		}
	}
	return (i);
}
