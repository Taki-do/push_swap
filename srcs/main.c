/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 11:42:01 by taomalbe          #+#    #+#             */
/*   Updated: 2024/12/18 16:25:19 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void start_sort(t_stack *a, t_stack *b)
{
	if (ft_issort(a, b))
		return ;
    if (a->size == 2)
        sa(a);
    else if (a->size == 3)
        sort_three(a);
    else
        chunksort(a, b);
}


int main(int ac, char *av[])
{
	int		i;
	t_node	*lst_a;
	t_node	*current;
	t_stack	*a;
	t_stack	*b;

	lst_a = NULL;
	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	if (ac > 1)
	{
		if (!ft_tab_is_numeric(ac, av))
			return (ft_putstr_fd("Error\n", 2), 0);
		i = 1;
		while (i < ac)
		{
			if (ft_notflow(av[i]))
				ft_addnode(&lst_a, av[i]);
			else
				return (ft_putstr_fd("Error\n", 2), 0);
			i++;
		}
		current = lst_a;
		a->top = current;
		a->size = i - 1;
		b->top = NULL;
		b->size = 0;
		if (ft_double(a))
			return (ft_putstr_fd("Error\n", 2), 0);
		start_sort(a, b);
		ft_printf("stack a:\n");
		while (a->top)
		{
			ft_printf("%d\n", a->top->value);
			a->top = a->top->next;
		}
		ft_printf("stack b:\n");
		while (b->top)
		{
			ft_printf("%d\n", b->top->value);
			b->top = b->top->next;
		}
	}
	return (0);
}
