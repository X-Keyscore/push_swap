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

size_t			list_length(t_list_node *head);
int				list_push_front(t_list_node **head, int data);
int				list_push_back(t_list_node **head, int data);
void			list_pop_front(t_list_node **head);
void			list_pop_back(t_list_node **head);
void			list_clear(t_list_node **head);
int				list_peer(t_list_node *head);

int				pa_pb(t_list_node **stack_pop,
					t_list_node **stack_push, int mode);
int				ra_rb(t_list_node **stack, int mode);
int				rra_rrb(t_list_node **stack, int mode);

int				is_digit_int(char *s);
long			ft_atoi(const char *nptr);
void			putstr(char *s, int fd);
void			parser(int argc, char **argv, t_list_node **head);

int				get_smallest_value(t_list_node *head);

int				is_biggest(t_list_node *head);
int				is_biggest_in(t_list_node *static_node, t_list_node *head);

size_t			get_inferior_index_at_in(t_list_node *static_node,
					t_list_node *head);
int				move_top_inferior_at_in(t_list_node *static_node,
					t_list_node **head, int mode);

int				is_sorted(t_list_node *head);
int				below_max(t_list_node *head, long max);
void			pre_sort(t_list_node **stack_1, t_list_node **stack_2,
					long max, int push_mode);
void			algorithm(t_list_node **stack_1, t_list_node **stack_2);

void			ctrl_err(int success_op, t_list_node **stack_1,
					t_list_node **stack_2);
int				main(int argc, char **argv);

#endif