/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_ctrl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 11:48:54 by taomalbe          #+#    #+#             */
/*   Updated: 2025/02/04 10:15:45 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_tab_is_numeric(char *av[], int i)
{
	int	j;

	while (av[i])
	{
		j = 0;
		if (av[i][0] == '\0')
			return (0);
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
			{
				if ((j != 0 && av[i][j] == '-')
					|| (av[i][j] == '-' && !ft_isdigit(av[i][j + 1])))
					return (0);
			}
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

int	is_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (-1);
		i++;
	}
	return (1);
}
