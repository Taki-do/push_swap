/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_ctrl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 11:48:54 by taomalbe          #+#    #+#             */
/*   Updated: 2024/12/14 15:27:28 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_tab_is_numeric(int ac, char *av[])
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
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

int	ft_notflow(char *s)
{
	long flow;

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
