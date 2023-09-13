/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_s.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:28:26 by zjaddad           #+#    #+#             */
/*   Updated: 2023/09/13 14:49:23 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_lstadd_back_s(t_2map **head, t_2map *new)
{
	t_2map	*tmp;

	if (!head || !*head)
	{
		(*head) = new;
		return ;
	}
	if (!new)
		return ;
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->next = NULL;
}
