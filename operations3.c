/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:36:43 by taomalbe          #+#    #+#             */
/*   Updated: 2025/01/04 14:05:46 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
