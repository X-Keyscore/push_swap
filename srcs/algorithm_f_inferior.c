/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_f_inferior.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anraymon <anraymon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 01:12:46 by anraymon          #+#    #+#             */
/*   Updated: 2023/12/12 04:05:00 by anraymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
** @return The index of the lower number at static_node
**/
size_t	get_inferior_index_at_in(t_list_node *static_node, t_list_node *head)
{
	size_t	min_i;
	size_t	i;
	int		min_gap;

	if (!head)
		return (0);
	min_gap = INT_MAX;
	min_i = 0;
	i = 1;
	while (head)
	{
		if (min_gap > (static_node->data - head->data))
		{
			min_gap = (static_node->data - head->data);
			min_i = i;
		}
		head = head->next;
		i++;
	}
	return (min_i);
}

/**
** @brief Move top the lower number at static_node
**/
int	move_top_inferior_at_in(t_list_node *static_node,
	t_list_node **head, int mode)
{
	size_t	inferior_index;
	size_t	step;
	int		success_op;
	int		type_move;

	if (!static_node || !*head)
		return (1);
	type_move = 1;
	inferior_index = get_inferior_index_at_in(static_node, *head);
	if (!inferior_index)
		return (1);
	step = --inferior_index;
	if (inferior_index > (list_length(*head) / 2) && type_move--)
		step = list_length(*head) - inferior_index;
	while (step--)
	{
		if (type_move)
			success_op = ra_rb(head, mode);
		else
			success_op = rra_rrb(head, mode);
		if (!success_op)
			return (0);
	}
	return (1);
}
