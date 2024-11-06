/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanavar <joanavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:39:32 by joanavar          #+#    #+#             */
/*   Updated: 2024/06/15 13:16:49 by joanavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../projects/libft/libft.h"
# include "../projects/printf/ft_printf.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					num;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

//**Erros.c
int						error_syntax(char *str);

int						error_duplicate(t_stack_node *stack, int n);

void					free_stack(t_stack_node **stack);

void					free_errors(t_stack_node **a);

//**StackInits.c
void					init_stack_a(t_stack_node **a, char **argv);

t_stack_node			*get_cheapest(t_stack_node *stack);

void					prep_for_push(t_stack_node **stack, \
		t_stack_node *top_node, char stack_name);

//**stack_utils.c

int						stack_long(t_stack_node *stack);
t_stack_node			*find_last(t_stack_node *stack);
bool					stack_sorted(t_stack_node *stack);
t_stack_node			*find_min(t_stack_node *stack);
t_stack_node			*find_max(t_stack_node *stack);
void					rotate_both(t_stack_node **a, t_stack_node **b, \
		t_stack_node *cheapest_node);
void					rotate_both(t_stack_node **a, t_stack_node **b, \
		t_stack_node *cheapest_node);
void					move_a_to_b(t_stack_node **a, t_stack_node **b);
void					move_b_to_a(t_stack_node **a, t_stack_node **b);
void					min_on_top(t_stack_node **a);

//**split.c
char					**split(char *str, char c);
void					free_matrix(char **str);

//**init_b_to_a

void					init_nodes_b(t_stack_node *a, t_stack_node *b);

//**init_a_to_b.c
void					current_index(t_stack_node *stack);
void					set_cheapest(t_stack_node *stack);
void					init_nodes_a(t_stack_node *a, t_stack_node *b);

//***Commands
void					sa(t_stack_node **a, bool print);
void					sb(t_stack_node **b, bool print);
void					ss(t_stack_node **a, t_stack_node **b, bool print);
void					ra(t_stack_node **a, bool print);
void					rb(t_stack_node **b, bool print);
void					rr(t_stack_node **a, t_stack_node **b, bool print);
void					rra(t_stack_node **a, bool print);
void					rrb(t_stack_node **b, bool print);
void					rrr(t_stack_node **a, t_stack_node **b, bool print);
void					pa(t_stack_node **a, t_stack_node **b, \
		bool print);
void					pb(t_stack_node **b, t_stack_node **a, \
		bool print); // TODOS

//***Algorithm
void					sort_three(t_stack_node **a);
void					sort_stacks(t_stack_node **a, t_stack_node **b);

#endif
