/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:40:21 by taomalbe          #+#    #+#             */
/*   Updated: 2024/12/18 16:35:05 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	simplesort(t_stack *a, t_stack *b)
{
	(void)b;
	if (ft_issort(a, b))
		return ;
	if ((a->top->value < a->top->next->value)
		&& (a->top->next->value > a->top->next->next->value))
		rra(a);
	else if ((a->top->value > a->top->next->value)
		&& (a->top->next->value > a->top->next->next->value))
		return (ra(a), sa(a));
	else
		ra(a);
}

int	ft_issort(t_stack *a, t_stack *b)
{
	t_node *head;
	
	if (b->size > 0)
		return (0);
	if (a->size <= 1)
		return (1);
	head = a->top;
	while (head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}
