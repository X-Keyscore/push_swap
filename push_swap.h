/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anraymon <anraymon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 01:28:22 by anraymon          #+#    #+#             */
/*   Updated: 2023/12/05 01:28:22 by anraymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct t_list_node
{
	int					data;
	struct t_list_node	*prev;
	struct t_list_node	*next;
}	t_list_node;

t_list_node	*list_create_node(int data);
size_t		list_length(t_list_node *head);
int			list_push_front(t_list_node **head, int data);
int			list_push_back(t_list_node **head, int data);
void		list_pop_front(t_list_node **head);
void		list_pop_back(t_list_node **head);
void		list_clear(t_list_node **head);
int			list_peer(t_list_node *head);
int			list_sorted(t_list_node *head);
int			pa_pb(t_list_node **stack_pop,
				t_list_node **stack_push, int mode);
int			ra_rb(t_list_node **stack, int mode);
int			rra_rrb(t_list_node **stack, int mode);
int			sa_sb(t_list_node **stack, int mode);

long		ft_atoi(const char *nptr);
int			is_int(char *s, size_t start, size_t end);
int			is_digit_int(char *s);
void		putstr(char *s, int fd);
void		parser(int argc, char **argv, t_list_node **head);

int			is_smallest(t_list_node *head);
int			is_smallest_in(t_list_node *static_node, t_list_node *head);
int			get_sml_val(t_list_node *head);
int			get_smallest_index(t_list_node *head);
int			move_top_smallest_in(t_list_node **head, int mode);

int			is_biggest(t_list_node *head);
int			get_big_val(t_list_node *head);
int			is_biggest_in(t_list_node *static_node, t_list_node *head);

int			inf_is_in(t_list_node *static_node, t_list_node *stack_1,
				t_list_node *stack_2);
int			end_is_inferior_at(t_list_node *static_node, t_list_node *head);
size_t		get_inf_idx_at_in(t_list_node *static_node, t_list_node *head);
t_list_node	*get_inferior_node_at_in(t_list_node *static_node,
				t_list_node *head);
int			move_top_inf_at_in(t_list_node *static_node,
				t_list_node **head, int mode);

size_t		get_superior_index_at_in(t_list_node *static_node,
				t_list_node *head);
int			move_top_sup_at_in(t_list_node *static_node,
				t_list_node **head, int mode);

int			tcheck_below_max(t_list_node *head, long max, long mid);
int			tcheck_above_min(t_list_node *head, long min, long mid);

long		utils_get_move(size_t index, t_list_node *head);
int			utils_calc_div(size_t x);
int			utils_pre_stack_inf(t_list_node **stack_1, t_list_node **stack_2,
				int data_target);

void		sorter_simple(t_list_node **stack_1, t_list_node **stack_2,
				size_t len_stack_1);
void		pre_sorter_linear(t_list_node **stack_1, t_list_node **stack_2,
				long max_gap, long min_gap);
void		move_inf_optimize(t_list_node **stack_1, t_list_node **stack_2,
				long move_inf);
void		sorter_optimize(t_list_node **stack_1, t_list_node **stack_2);
void		algorithm(t_list_node **stack_1, t_list_node **stack_2);

int			ctrl_err(t_list_node **stack_1, t_list_node **stack_2,
				int success_op);
int			main(int argc, char **argv);

#endif