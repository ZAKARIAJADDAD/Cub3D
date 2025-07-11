/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:04:00 by zjaddad           #+#    #+#             */
/*   Updated: 2023/09/14 22:55:45 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

t_2map	*ft_lstnew_s(char *key, char *value)
{
	t_2map	*elt;

	elt = (t_2map *)malloc(sizeof(*elt));
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
