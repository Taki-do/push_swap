/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:20:38 by taomalbe          #+#    #+#             */
/*   Updated: 2025/01/04 14:06:09 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*top;
}	t_stack;

typedef struct s_var
{
	int		ac;
	char	**tab;
	char	**av;
	t_stack	*a;
	t_stack	*b;
	t_node	*lst_a;
	t_node	*current;
}	t_var;

int		ft_sqrt(int nb);
int		ft_notflow(char *s);
int		ft_double(t_stack *a);
int		countelem(char **split);
int		ft_issort(t_stack *a, t_stack *b);
int		ft_tab_is_numeric(char *av[]);

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
void	ft_splitfree(char **split);
void	simplesort(t_stack *a, t_stack *b);
void	ft_freenode(t_stack *a, t_stack *b);
void	ft_addnode(t_node **lst_a, char *av);

//Algos

int		find_highest(t_stack *s);
int		calculate_chunks(int stack_size);
int		find_index(t_stack *s, int value);
int		calculate_chunk_size(int stack_size, int chunks);

void	sort_three(t_stack *a);
void	chunksort(t_stack *a, t_stack *b);
void	insertion_sort(t_stack *a, t_stack *b);

long	ft_atol(char *s);

t_node	*ft_newnode(int value);

#endif