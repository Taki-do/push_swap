/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:20:38 by taomalbe          #+#    #+#             */
/*   Updated: 2024/12/17 17:09:12 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"

typedef struct s_node
{
	int				value;
	struct s_node 	*next;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node *top;
}	t_stack;

int		ft_tab_is_numeric(int ac, char *av[]);
int		ft_notflow(char *s);

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	ft_addnode(t_node **lst_a, char *av);

long	ft_atol(char *s);

t_node	*ft_newnode(int value);

#endif