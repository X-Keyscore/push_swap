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
# include <stdio.h> //delete

typedef struct t_list_node
{
	int					data;
	struct t_list_node	*prev;
	struct t_list_node	*next;
}	t_list_node;

size_t			list_length(t_list_node *head);
void				list_push_front(t_list_node **head, int data);
void				list_push_back(t_list_node **head, int data);
void				list_pop_front(t_list_node **head);
void				list_pop_back(t_list_node **head);
int					list_peer(t_list_node *head, size_t length);
void				list_clear(t_list_node **head);

void				putstr(char *s, int fd);
void				parser(int argc, char **argv, t_list_node **head);

size_t			pa_pb(t_list_node **stack_pop, t_list_node **stack_push, int mode);
size_t			ra_rb(t_list_node **stack, int mode);
size_t			rra_rrb(t_list_node **stack, int mode);

int					is_sorted(t_list_node *head);
int					is_smallest(t_list_node *head, size_t end_index);
int					is_smallest_in(t_list_node *stack_1, t_list_node *stack_2, size_t end_index);
size_t			move_top_smallest(t_list_node **head);
size_t			get_smallest_index(t_list_node *main_node);
size_t			algorithm(t_list_node **stack_1, t_list_node **stack_2);

int					main(int argc, char **argv);

#endif