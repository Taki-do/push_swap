/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:55:39 by taomalbe          #+#    #+#             */
/*   Updated: 2025/01/04 14:05:15 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_newnode(int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

void	ft_addnode(t_node **lst_a, char *av)
{
	t_node	*new_node;
	t_node	*current;

	new_node = ft_newnode(ft_atoi(av));
	if (!(*lst_a))
		*lst_a = new_node;
	else
	{
		current = *lst_a;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
}
