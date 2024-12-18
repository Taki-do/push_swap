/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:20:38 by taomalbe          #+#    #+#             */
/*   Updated: 2024/12/18 16:41:45 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"

//Verifier les nombres doublons

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
int		ft_issort(t_stack *a, t_stack *b);

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	ft_addnode(t_node **lst_a, char *av);
void	simplesort(t_stack *a, t_stack *b);

long	ft_atol(char *s);

t_node	*ft_newnode(int value);

#endif