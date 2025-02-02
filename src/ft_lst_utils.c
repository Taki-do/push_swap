/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:55:39 by taomalbe          #+#    #+#             */
/*   Updated: 2025/02/02 15:33:12 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

int	ft_fill2_lst(t_var *var, int tmp, int i)
{
	var->current = var->lst_a;
	var->a->top = var->current;
	if (var->ac == countelem(var->av) && tmp)
		var->a->size = i - 1;
	else
	{
		var->a->size = i;
		ft_splitfree(var->tab);
		var->tab = NULL;
	}
	var->b->top = NULL;
	var->b->size = 0;
	if (ft_double(var->a))
	{
		return (exitfree(var->tab, tmp),
			ft_freenode(var->a, var->b), ft_putstr_fd("Error\n", 2), 1);
	}
	return (0);
}
