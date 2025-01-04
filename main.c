/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 11:42:01 by taomalbe          #+#    #+#             */
/*   Updated: 2025/01/04 14:05:22 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_sort(t_stack *a, t_stack *b)
{
	if (ft_issort(a, b))
		return ;
	else if (a->size == 2)
		sa(a);
	else if (a->size == 3)
		sort_three(a);
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

int	ft_fill_lst(t_var *var, int i)
{
	if (!ft_tab_is_numeric(var->tab))
		return (exitfree(var->ac, var->av, var->tab),
			ft_freenode(var->a, var->b), ft_putstr_fd("Error\n", 2), 1);
	while (i < var->ac)
	{
		if (ft_notflow(var->tab[i]))
			ft_addnode(&var->lst_a, var->tab[i]);
		else
			return (exitfree(var->ac, var->av, var->tab),
				ft_freenode(var->a, var->b), ft_putstr_fd("Error\n", 2), 1);
		i++;
	}
	var->current = var->lst_a;
	var->a->top = var->current;
	if (var->ac == countelem(var->av))
		var->a->size = i - 1;
	else
	{
		var->a->size = i;
		ft_splitfree(var->tab);
	}
	var->b->top = NULL;
	var->b->size = 0;
	return (0);
}

int	ft_init_tab(t_var *var)
{
	int	err;

	var->a = (t_stack *)malloc(sizeof(t_stack));
	if (!var->a)
		return (1);
	var->b = (t_stack *)malloc(sizeof(t_stack));
	if (!var->b)
		return (free(var->a), 1);
	if (var->ac == 2)
	{
		var->tab = ft_split(var->av[1], ' ');
		var->ac = countelem(var->tab);
		err = ft_fill_lst(var, 0);
	}
	else
	{
		var->tab = var->av;
		err = ft_fill_lst(var, 1);
	}
	return (err);
}

int	main(int ac, char *av[])
{
	t_var	var;

	var.av = av;
	var.ac = ac;
	var.lst_a = NULL;
	if (ac > 1)
	{
		if (ft_init_tab(&var) == 1)
			return (1);
		if (ft_double(var.a))
			return (exitfree(var.ac, var.av, var.tab),
				ft_freenode(var.a, var.b), ft_putstr_fd("Error\n", 2), 1);
		start_sort(var.a, var.b);
		ft_freenode(var.a, var.b);
	}
	return (0);
}
