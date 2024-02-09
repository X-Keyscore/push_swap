/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_f_superior.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anraymon <anraymon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 21:44:02 by anraymon          #+#    #+#             */
/*   Updated: 2023/12/16 22:29:41 by anraymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
** @return The index of the upper number at static_node in head.
**/
size_t	get_superior_index_at_in(t_list_node *static_node, t_list_node *head)
{
	size_t	min_i;
	size_t	i;
	long	min_gap;

	if (!static_node || !head)
		return (0);
	min_gap = UINT_MAX;
	min_i = 0;
	i = 1;
	while (head)
	{
		if (head->data > static_node->data
			&& min_gap > (head->data - static_node->data))
		{
			min_gap = head->data - static_node->data;
			min_i = i;
		}
		head = head->next;
		i++;
	}
	return (min_i);
}

/**
** @brief Move top the upper number at static_node in head.
**/
int	move_top_sup_at_in(t_list_node *static_node,
	t_list_node **head, int mode)
{
	size_t	superior_i;
	size_t	step;
	int		success_op;
	int		type_move;

	if (!static_node || !*head)
		return (1);
	type_move = 1;
	superior_i = get_superior_index_at_in(static_node, *head);
	if (!superior_i)
		return (1);
	step = --superior_i;
	if (superior_i > (list_length(*head) / 2) && type_move--)
		step = list_length(*head) - superior_i;
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
