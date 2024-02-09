/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_f_inferior.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anraymon <anraymon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 21:44:02 by anraymon          #+#    #+#             */
/*   Updated: 2024/02/09 02:27:05 by anraymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
** @return 1 if is in stack_1, 2 if is in stack_2 or 0 if stack_1
** and stack_2 is empty.
**/
int	inf_is_in(t_list_node *static_node, t_list_node *stack_1,
	t_list_node *stack_2)
{
	long	min_gap;

	if (!static_node || !stack_1 || !stack_2)
		return (0);
	min_gap = UINT_MAX;
	while (stack_1)
	{
		if (stack_1->data < static_node->data
			&& min_gap > (static_node->data - stack_1->data))
			min_gap = static_node->data - stack_1->data;
		stack_1 = stack_1->next;
	}
	while (stack_2)
	{
		if (stack_2->data < static_node->data
			&& min_gap > (static_node->data - stack_2->data))
			return (2);
		stack_2 = stack_2->next;
	}
	return (1);
}

int	end_is_inferior_at(t_list_node *static_node, t_list_node *head)
{
	t_list_node	*end;

	if (!static_node || !head)
		return (0);
	end = head;
	while (end->next)
		end = end->next;
	if (is_biggest_in(end, head) || end->data < static_node->data)
		return (1);
	return (0);
}

/**
** @return The index of the lower number at static_node.
**/
size_t	get_inf_idx_at_in(t_list_node *static_node, t_list_node *head)
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
		if (head->data < static_node->data
			&& min_gap > (static_node->data - head->data))
		{
			min_gap = static_node->data - head->data;
			min_i = i;
		}
		head = head->next;
		i++;
	}
	return (min_i);
}

/**
** @return The node of the lower number at static_node.
**/
t_list_node	*get_inferior_node_at_in(t_list_node *static_node,
	t_list_node *head)
{
	t_list_node	*min_node;
	long		min_gap;

	if (!static_node || !head)
		return (NULL);
	min_gap = UINT_MAX;
	min_node = head;
	while (head)
	{
		if (head->data < static_node->data
			&& min_gap > (static_node->data - head->data))
		{
			min_gap = static_node->data - head->data;
			min_node = head;
		}
		head = head->next;
	}
	return (min_node);
}

/**
** @brief Move top the lower number at static_node in head.
**/
int	move_top_inf_at_in(t_list_node *static_node,
	t_list_node **head, int mode)
{
	size_t	inferior_i;
	size_t	step;
	int		success_op;
	int		type_move;

	if (!static_node || !*head)
		return (1);
	type_move = 1;
	inferior_i = get_inf_idx_at_in(static_node, *head);
	if (!inferior_i)
		return (1);
	step = --inferior_i;
	if (inferior_i > (list_length(*head) / 2) && type_move--)
		step = list_length(*head) - inferior_i;
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
