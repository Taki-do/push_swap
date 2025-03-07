/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:20:38 by taomalbe          #+#    #+#             */
/*   Updated: 2025/02/04 10:21:07 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

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

int		ft_notflow(char *s);
int		only_spaces(char *s);
int		is_spaces(char *str);
int		ft_lowest(t_stack *a);
int		ft_double(t_stack *a);
int		get_absolute(int num);
int		countelem(char **split);
int		ft_issort(t_stack *a, t_stack *b);
int		ft_tab_is_numeric(char *av[], int i);
int		ft_fill2_lst(t_var *var, int tmp, int i);

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	ft_splitfree(char **split);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	exitfree(char **split, int mode);
void	simplesort(t_stack *a, t_stack *b);
void	ft_freenode(t_stack *a, t_stack *b);
void	ft_addnode(t_node **lst_a, char *av);

long	ft_atol(char *s);

t_node	*ft_newnode(int value);

//Algos

int		find_highest(t_stack *s);
int		calculate_chunks(int stack_size);
int		find_index(t_stack *s, int value);
int		calculate_chunk_size(int stack_size, int chunks);

void	sort_three(t_stack *a);
void	chunksort(t_stack *a, t_stack *b, int i);
void	insertion_sort(t_stack *a, t_stack *b);

#endif