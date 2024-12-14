/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 11:42:01 by taomalbe          #+#    #+#             */
/*   Updated: 2024/12/14 15:29:59 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char *av[])
{
	int		i;
	t_stack	*lst;
	t_stack	*cursor;

	if (ac > 1)
	{
		if (!ft_tab_is_numeric(ac, av))
			return (ft_putstr_fd("Error\n", 2), 0);
		i = 1;
		while (i < ac)
		{
			if (ft_notflow(av[i]))
			{
				lst = ft_stacknew(ft_atoi(av[i]));
				cursor = lst;
				lst = lst->next;
				lst->before = cursor;
			}
			else
				return (ft_putstr_fd("Error\n", 2), 0);
			i++;
		}
	}
}
// Recuperer la liste A, regarder si elle contient uniquement ce qui est demande, sinon afficher
// Error sur la sortie error (pas des nombres, overflow, clone).
