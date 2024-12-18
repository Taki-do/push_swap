/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:17:10 by taomalbe          #+#    #+#             */
/*   Updated: 2024/12/18 22:05:09 by taomalbe         ###   ########.fr       */
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

void sort_five_or_less(t_stack *a, t_stack *b)
{
    int min_val;
    int min_pos;
    int current_pos;
    int elements_to_push;
    t_node *current;
    
    elements_to_push = a->size - 3;
    if (a->size <= 3)
        return (sort_three(a));
    while (elements_to_push > 0)
    {
        current = a->top;
        min_val = current->value;
        min_pos = 0;
        current_pos = 0;
        while (current)
        {
            if (current->value < min_val)
            {
                min_val = current->value;
                min_pos = current_pos;
            }
            current = current->next;
            current_pos++;
        }
        while (min_pos > 0)
        {
            if (min_pos <= a->size / 2)
                ra(a);
            else
                rra(a);
            min_pos = (min_pos <= a->size / 2) ? min_pos - 1 : min_pos + 1;
            if (min_pos == a->size)
                min_pos = 0;
        }
        pb(a, b);
        elements_to_push--;
    }
    sort_three(a);
    while (b->size > 0)
        pa(a, b);
}

void insertion_sort(t_stack *a, t_stack *b)
{
    while (a->size > 3)
    {
        // Trouve le plus petit élément
        t_node *current = a->top;
        int min_val = current->value;
        int min_pos = 0;
        int current_pos = 0;
        
        while (current)
        {
            if (current->value < min_val)
            {
                min_val = current->value;
                min_pos = current_pos;
            }
            current = current->next;
            current_pos++;
        }
        
        // Amène le plus petit élément en haut
        while (min_pos > 0)
        {
            if (min_pos <= a->size / 2)
                ra(a);
            else
                rra(a);
            min_pos = (min_pos <= a->size / 2) ? min_pos - 1 : min_pos + 1;
            if (min_pos == a->size)
                min_pos = 0;
        }
        
        pb(a, b);
    }
    
    // Trie les 3 derniers éléments
    sort_three(a);
    
    // Remet tout dans l'ordre dans a
    while (b->size > 0)
        pa(a, b);
}