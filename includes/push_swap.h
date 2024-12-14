/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:20:38 by taomalbe          #+#    #+#             */
/*   Updated: 2024/12/14 15:28:11 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"

typedef struct s_stack
{
	int	content;
	struct s_stack *next;
	struct s_stack *before;
}	t_stack;

int	ft_tab_is_numeric(int ac, char *av[]);
int	ft_notflow(char *s);

long	ft_atol(char *s);

t_stack	*ft_stacknew(int content);

#endif