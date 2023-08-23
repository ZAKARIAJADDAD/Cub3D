/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:04:00 by zjaddad           #+#    #+#             */
/*   Updated: 2023/08/20 12:46:33 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"


t_map	*ft_lstnew_s(char *key, char *value)
{
	t_map	*elt;

	elt = (t_map *)malloc(sizeof(*elt));
	if (elt == NULL)
		return (NULL);
	if (value != NULL)
		elt->value = ft_strdup(value);
	else
		elt->value = NULL;
	elt->key = ft_strdup(key);
	elt->next = NULL;
	return (elt);
}