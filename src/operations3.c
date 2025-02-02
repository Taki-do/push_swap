/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:36:43 by taomalbe          #+#    #+#             */
/*   Updated: 2025/02/02 15:33:43 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rrr(t_stack *a, t_stack *b)
{
	return (ft_printf("rrr\n"), rra(a), rrb(b));
}

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	while (i * i < nb)
		i++;
	if (i * i != nb)
		i--;
	ft_printf("racine de %d = %d\n", nb, i);
	return (i);
}
