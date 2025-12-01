/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:04:49 by yikebata          #+#    #+#             */
/*   Updated: 2025/12/01 18:54:33 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include "libft.h"

typedef struct s_node
{
	int				val;
	int				idx;
	int				cur_pos;
	int				optimal_cost;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*target;
	bool			above_median_flag;
	bool			cheapest_flag;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

# define SMALL_CHUNK_SIZE 20
# define LARGE_CHUNK_SIZE 65

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
int		contains_only_spaces(char *str);

//swap.c
void	sa(t_stack *stack_a, int print);
void	sb(t_stack *stack_b, int print);
void	ss(t_stack *stack_a, t_stack *stack_b, int print);

//push.c
void	pa(t_stack *stack_a, t_stack *stack_b, int print);
void	pb(t_stack *stack_a, t_stack *stack_b, int print);

//rotate.c
void	ra(t_stack *stack_a, int print);
void	rb(t_stack *stack_b, int print);
void	rr(t_stack *stack_a, t_stack *stack_b, int print);

//reverse_rotate.c
void	rra(t_stack *stack_a, int print);
void	rrb(t_stack *stack_a, int print);
void	rrr(t_stack *stack_a, t_stack *stack_b, int print);

//coordinate_compression.c
int		coordinate_compression(t_stack *stack);

//two_sort.c
void	two_sort(t_stack *stack_a);

//three_sort.c
void	three_sort(t_stack *stack_a);

//four_five_sort.c
void	four_five_sort(t_stack *stack_a, t_stack *stack);

//large_sort.c
void	large_sort(t_stack *stack_a, t_stack *stack_b);

//move_to_a.c
t_node	*get_cheapest(t_stack *stack);
void	additional_rotate(t_stack *stack, t_node *expected_top, char type);
t_node	*find_min(t_stack *stack);

//update_node_info.c
void	update_index(t_stack *stack);
void	set_target(t_stack *stack_a, t_stack *stack_b);
void	cal_move_cost(t_stack *stack_a, t_stack *stack_b);

//both_rotate.c
void	rotate_both(t_stack *a, t_stack *b, t_node *cheapest);
void	reverse_rotate_both(t_stack *a, t_stack *b, t_node *cheapest);

#endif
