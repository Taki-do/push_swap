/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 11:42:01 by taomalbe          #+#    #+#             */
/*   Updated: 2025/02/02 15:32:58 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

void	exitfree(char **split, int mode)
{
	if (!mode && split)
		ft_splitfree(split);
}

int	ft_fill_lst(t_var *var, int i)
{
	int	tmp;

	tmp = i;
	if (!ft_tab_is_numeric(var->tab, i))
		return (exitfree(var->tab, tmp),
			ft_freenode(var->a, var->b), ft_putstr_fd("Error\n", 2), 1);
	while (i < var->ac)
	{
		if (ft_notflow(var->tab[i]))
			ft_addnode(&var->lst_a, var->tab[i]);
		else
		{
			var->a->top = var->lst_a;
			return (exitfree(var->tab, tmp),
				ft_freenode(var->a, var->b), ft_putstr_fd("Error\n", 2), 1);
		}
		i++;
	}
	return (ft_fill2_lst(var, tmp, i));
}

int	ft_init_tab(t_var *var, int err)
{
	var->a = (t_stack *)malloc(sizeof(t_stack));
	if (!var->a)
		return (1);
	var->a->top = NULL;
	var->a->size = 0;
	var->b = (t_stack *)malloc(sizeof(t_stack));
	if (!var->b)
		return (free(var->a), 1);
	var->b->top = NULL;
	var->b->size = 0;
	if (var->ac == 2)
	{
		if (is_spaces(var->av[1]) == 1)
			return (ft_freenode(var->a, var->b), 1);
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
	int		err;
	t_var	var;

	var.av = av;
	var.ac = ac;
	var.lst_a = NULL;
	err = 0;
	if (ac > 1)
	{
		if (ft_init_tab(&var, err) == 1)
			return (1);
		start_sort(var.a, var.b);
		ft_freenode(var.a, var.b);
	}
	return (0);
}
