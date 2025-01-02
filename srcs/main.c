/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 11:42:01 by taomalbe          #+#    #+#             */
/*   Updated: 2025/01/02 17:24:05 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void start_sort(t_stack *a, t_stack *b)
{
	if (ft_issort(a, b))
		return ;
    else if (a->size == 2)
        sa(a);
    else if (a->size == 3)
        sort_three(a);
	else if (a->size <= 5)
		sort_five_or_less(a, b);
	else if (a->size <= 20)
		insertion_sort(a, b);
    else
        chunksort(a, b);
}

void	exitfree(int ac, char *av[], char **split)
{
	if (ac != countelem(av))
		ft_splitfree(split);
}

int main(int ac, char *av[])
{
	int		i;
	char	**tab;
	t_node	*lst_a;
	t_node	*current;
	t_stack	*a;
	t_stack	*b;

	lst_a = NULL;
	if (ac > 1)
	{
		a = (t_stack *)malloc(sizeof(t_stack));
		if (!a)
			return (1);
		b = (t_stack *)malloc(sizeof(t_stack));
		if (!b)
			return (free(a), 1);
		if (ac == 2)
		{
			tab = ft_split(av[1], ' ');
			ac = countelem(tab);
			i = 0;
		}
		else
		{
			tab = av;
			i = 1;
		}
		if (!ft_tab_is_numeric(tab))
			return (exitfree(ac, av, tab), ft_freenode(a, b), ft_putstr_fd("Error\n", 2), 0);
		while (i < ac)
		{
			if (ft_notflow(tab[i]))
				ft_addnode(&lst_a, tab[i]);
			else
				return (exitfree(ac, av, tab), ft_freenode(a, b), ft_putstr_fd("Error\n", 2), 0);
			i++;
		}
		current = lst_a;
		a->top = current;
		if (ac == countelem(av))
			a->size = i - 1;
		else
		{
			a->size = i;
			ft_splitfree(tab);
		}
		b->top = NULL;
		b->size = 0;
		if (ft_double(a))
			return (exitfree(ac, av, tab), ft_freenode(a, b), ft_putstr_fd("Error\n", 2), 0);
		start_sort(a, b);
		ft_freenode(a, b);
	}
	return (0);
}
