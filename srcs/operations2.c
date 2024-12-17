/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:40:55 by taomalbe          #+#    #+#             */
/*   Updated: 2024/12/17 16:47:31 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack *a)
{
	if (a->size < 2)
		return ;
	if (a->size == 2)
		sa(a);
	t_node *tmp;

	tmp = a->top;
	a->top = a->top->next;
	while (a->top->next)
		a->top = a->top->next;
	a->top->next = tmp;
	tmp->next = NULL;
}

