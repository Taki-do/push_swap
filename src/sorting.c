/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:40:21 by taomalbe          #+#    #+#             */
/*   Updated: 2025/02/04 11:50:03 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_issort(t_stack *a, t_stack *b)
{
	t_node	*head;

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

int	elems_range(t_stack *a, int min, int max)
{
	t_node	*node;

	node = a->top;
	while (node)
	{
		if (node->value >= min && node->value < max)
			return (1);
		node = node->next;
	}
	return (0);
}

void	push_chunk_to_b(t_stack *a, t_stack *b, int min, int max)
{
	while (elems_range(a, min, max))
	{
		if (a->top->value >= min && a->top->value < max)
		{
			pb(a, b);
			if (b->top->value < (min + max) / 2)
				rb(b);
		}
		else
			ra(a);
	}
}

void	push_highest_to_a(t_stack *a, t_stack *b)
{
	int	highest;
	int	index;

	highest = find_highest(b);
	index = find_index(b, highest);
	if (index <= b->size / 2)
	{
		while (b->top->value != highest)
			rb(b);
	}
	else
	{
		while (b->top->value != highest)
			rrb(b);
	}
	pa(a, b);
}

void	chunksort(t_stack *a, t_stack *b, int i)
{
	int	min;
	int	max;
	int	chunks;
	int	chunks_size;
	int	mini;

	mini = ft_lowest(a);
	max = find_highest(a);
	chunks = calculate_chunks(a->size);
	chunks_size = (get_absolute(mini) + get_absolute(max))
		/ chunks + 1;
	while (i < chunks)
	{
		min = mini + (i * chunks_size);
		max = mini + ((i + 1) * chunks_size);
		push_chunk_to_b(a, b, min, max);
		i++;
	}
	while (b->size > 0)
		push_highest_to_a(a, b);
}
