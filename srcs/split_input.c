/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:00:46 by taomalbe          #+#    #+#             */
/*   Updated: 2025/01/02 17:13:54 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_freenode(t_stack *a, t_stack *b)
{
	t_node *head;
	t_node *tmp;

	head = a->top;
	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	free(a);
	head = b->top;
	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	free(b);
}

void	ft_splitfree(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

int	countelem(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}
