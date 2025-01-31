/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:00:46 by taomalbe          #+#    #+#             */
/*   Updated: 2025/01/31 11:38:23 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_freenode(t_stack *a, t_stack *b)
{
	t_node	*head;
	t_node	*tmp;

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
	if (!split || !split[0])
		return ;
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

int	only_spaces(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ')
			return (0);
	}
	return (1);
}
