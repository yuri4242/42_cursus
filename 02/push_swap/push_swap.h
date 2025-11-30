/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:04:49 by yikebata          #+#    #+#             */
/*   Updated: 2025/11/30 18:13:43 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"

typedef struct s_node
{
	int				val;
	int				idx;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*target;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

//create_and_free_stacks.c
int		create_stacks(t_stack **stack_a, t_stack **stack_b);
void	free_stacks(t_stack **stack_a, t_stack **stack_b);
void	free_stack_content(t_stack *stack);

//args_to_lst.c
int		args_to_lst(char **args, t_stack *stack_a);

//check_args.c
int		check_int(char *arg);
int		check_overflow(long num);
int		check_dup(int num, t_stack *stack);
void	add_to_stack(int num, t_stack *stack);

//ps_split.c
char	**ps_split(char const *s);

//ps_list_operation.c
t_node	*ps_lstlast(t_node *lst);
void	ps_lstadd_back(t_node **lst, t_node *new);
t_node	*ps_lstnew(int val);

//utils.c
void	free_arr(char ***arr);
int		err_print(char ***arr);

//swap.c
void	sa(t_stack *stack_a, int print);
void	sb(t_stack *stack_b, int print);
void	ss(t_stack *stack_a, t_stack *stack_b, int print);

//push.c
void	pa(t_stack *stack_a, t_stack *stack_b, int print);
void	pa(t_stack *stack_a, t_stack *stack_b, int print);

//rotate.c
void	ra(t_stack *stack_a, int print);
void	rb(t_stack *stack_b, int print);
void	rr(t_stack *stack_a, t_stack *stack_b, int print);

//reverse_rotate.c
void	rra(t_stack *stack_a, int print);
void	rrb(t_stack *stack_a, int print);
void	rrr(t_stack *stack_a, t_stack *stack_b, int print);

//two_sort.c
void	two_sort(t_stack *stack_a);

#endif
