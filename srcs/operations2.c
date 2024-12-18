/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:40:55 by taomalbe          #+#    #+#             */
/*   Updated: 2024/12/18 11:45:13 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack *a)
{
	t_node	*first;
	t_node	*last;

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
	return (ra(a), rb(b));
}

void	rra(t_stack *a)
{
	t_node	*first;
	t_node	*last;

	
}
//Stocker le premier elem
//

2
9
5
7 

5
7
2
9