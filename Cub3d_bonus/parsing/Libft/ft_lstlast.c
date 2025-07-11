/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:11:02 by zjaddad           #+#    #+#             */
/*   Updated: 2023/09/13 23:47:56 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	last = NULL;
	if (lst)
	{
		last = lst;
		while (last->next)
			last = last->next;
	}
	return (last);
}
