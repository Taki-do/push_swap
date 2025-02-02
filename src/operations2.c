/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:40:55 by taomalbe          #+#    #+#             */
/*   Updated: 2025/02/02 15:33:40 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_stack *a)
{
	t_node	*first;
	t_node	*last;

	ft_printf("ra\n");
	if (a->size < 2)
		return ;
	first = a->top;
	a->top = a->top->next;
	last = a->top;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	rb(t_stack *b)
{
	t_node	*first;
	t_node	*last;

	ft_printf("rb\n");
	if (b->size < 2)
		return ;
	first = b->top;
	b->top = b->top->next;
	last = b->top;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	rr(t_stack *a, t_stack *b)
{
	return (ft_printf("rr\n"), ra(a), rb(b));
}

void	rra(t_stack *a)
{
	t_node	*last;
	t_node	*second_last;

	ft_printf("rra\n");
	if (a->size < 2)
		return ;
	last = a->top;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	last->next = a->top;
	a->top = last;
	second_last->next = NULL;
}

void	rrb(t_stack *b)
{
	t_node	*last;
	t_node	*second_last;

	ft_printf("rrb\n");
	if (b->size < 2)
		return ;
	last = b->top;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	last->next = b->top;
	b->top = last;
	second_last->next = NULL;
}
