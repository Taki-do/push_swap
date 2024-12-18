/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:17:10 by taomalbe          #+#    #+#             */
/*   Updated: 2024/12/18 19:22:16 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int calculate_chunks(int stack_size)
{
    if (stack_size <= 100)
        return (5);
    else
        return (10);
}

int calculate_chunk_size(int stack_size, int chunks)
{
    return (stack_size + chunks - 1) / chunks;
}


int find_highest(t_stack *stack)
{
    t_node *current = stack->top;
    int highest = current->value;

    while (current)
    {
        if (current->value > highest)
            highest = current->value;
        current = current->next;
    }
    return highest;
}


int find_index(t_stack *stack, int value)
{
    t_node *current = stack->top;
    int index = 0;

    while (current)
    {
        if (current->value == value)
            return index;
        current = current->next;
        index++;
    }
    return -1;
}
void sort_three(t_stack *a)
{
    int first;
    int second;
    int third;

	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;
    if (first > second && second > third)
		return (sa(a), rra(a));
    else if (first > third && third > second)
        ra(a);
    else if (second > third && third > first)
		return (sa(a), ra(a));
    else if (second > first && first > third)
        rra(a);
    else if (third > first && first > second)
        sa(a);
}

