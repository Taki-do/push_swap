/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_ctrl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 11:48:54 by taomalbe          #+#    #+#             */
/*   Updated: 2025/01/31 11:44:22 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_tab_is_numeric(char *av[])
{
	int	i;
	int	j;

	if (!av)
		return ;
	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) && av[i][j] != '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_double(t_stack *a)
{
	t_node	*i;
	t_node	*j;

	if (!a || a->size < 2)
		return (0);
	i = a->top;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value == j->value)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

int	ft_notflow(char *s)
{
	long	flow;

	flow = ft_atol(s);
	if ((flow > 2147483647) || (flow < -2147483648))
		return (0);
	return (1);
}

long	ft_atol(char *s)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((s[i] >= 9 && s[i] <= 13) || (s[i] == ' '))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -sign;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + s[i] - '0';
		i++;
	}
	return (res * sign);
}
