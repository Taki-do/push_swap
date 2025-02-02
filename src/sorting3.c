/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 09:56:52 by taomalbe          #+#    #+#             */
/*   Updated: 2025/02/02 15:33:49 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sub_sort_core(t_stack *a, int *min_val, int *min_pos, int current_pos)
{
	t_node	*current;

	current = a->top;
	while (current)
	{
		if (current->value < *min_val)
		{
			*min_val = current->value;
			*min_pos = current_pos;
		}
		current = current->next;
		current_pos++;
	}
}

void	little_sort_core(t_stack *a, int min_val, int min_pos, int current_pos)
{
	sub_sort_core(a, &min_val, &min_pos, current_pos);
	while (min_pos > 0)
	{
		if (min_pos <= a->size / 2)
			ra(a);
		else
			rra(a);
		if (min_pos <= a->size / 2)
			min_pos--;
		else
			min_pos++;
		if (min_pos == a->size)
			min_pos = 0;
	}
}

void	insertion_sort(t_stack *a, t_stack *b)
{
	int		min_val;
	int		min_pos;
	int		current_pos;

	while (a->size > 3)
	{
		min_val = a->top->value;
		min_pos = 0;
		current_pos = 0;
		little_sort_core(a, min_val, min_pos, current_pos);
		pb(a, b);
	}
	sort_three(a);
	while (b->size > 0)
		pa(a, b);
}
