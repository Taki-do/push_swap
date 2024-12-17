/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:14:30 by taomalbe          #+#    #+#             */
/*   Updated: 2024/12/17 16:40:47 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack *a)
{
	t_node *first;
	t_node *second;
	
	if (a->size < 2)
		return ;
	first = a->top;
	second = a->top->next;

	first->next = second->next;
	second->next = first;
	a->top = second;
}

void	sb(t_stack *b)
{
	t_node *first;
	t_node *second;

	if (b->size < 2)
		return ;
	first = b->top;
	second = b->top->next;

	first->next = second->next;
	second->next = first;
	b->top = second;
}

void	ss(t_stack *a, t_stack *b)
{
	return (sa(a), sb(b));
}

void	pa(t_stack *a, t_stack *b)
{
	if (!b->size)
		return ;
	t_node *tmp;

	tmp = b->top;
	b->top = b->top->next;
	b->size--;
	tmp->next = a->top;
	a->top = tmp;
	a->size++;
}

void	pb(t_stack *a, t_stack *b)
{
	if (!a->size)
		return ;
	t_node *tmp;

	tmp = a->top;
	a->top = a->top->next;
	a->size--;
	tmp->next = b->top;
	b->top = tmp;
	b->size++;
}
