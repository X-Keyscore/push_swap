/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_annex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anraymon <anraymon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 01:00:24 by anraymon          #+#    #+#             */
/*   Updated: 2023/12/07 01:00:24 by anraymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
** @return 1 if the first node in head is the smallest or else 0.
**/
int	is_smallest(t_list_node *head)
{
	t_list_node	*cmp;

	cmp = head;
	while (cmp)
	{
		if (head->data > cmp->data)
			return (0);
		cmp = cmp->next;
	}
	return (1);
}

/**
** @return 1 if static_node is the smallest in head or else 0.
**/
int	is_smallest_in(t_list_node *static_node, t_list_node *head)
{
	while (static_node && head)
	{
		if (head->data < static_node->data)
			return (0);
		head = head->next;
	}
	return (1);
}

/**
** @return The smallest value in the list.
**/
int	get_sml_val(t_list_node *head)
{
	t_list_node	*tmp;
	int			min_value;

	if (!head)
		return (0);
	min_value = head->data;
	tmp = head;
	while (tmp)
	{
		if (min_value > tmp->data)
			min_value = tmp->data;
		tmp = tmp->next;
	}
	return (min_value);
}

/**
** @return The index of smallest number in the list
**/
int	get_smallest_index(t_list_node *head)
{
	t_list_node	*tmp;
	size_t		i;
	size_t		min_i;
	int			min_value;

	if (!head)
		return (0);
	min_value = head->data;
	tmp = head;
	min_i = 0;
	i = 1;
	while (tmp)
	{
		if (min_value > tmp->data)
		{
			min_value = tmp->data;
			min_i = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (min_i);
}

/**
** @brief Move top the smallest in the list
**/
int	move_top_smallest_in(t_list_node **head, int mode)
{
	size_t	smallest_i;
	size_t	step;
	int		success_op;
	int		type_move;

	if (!*head)
		return (1);
	type_move = 1;
	smallest_i = get_smallest_index(*head);
	if (!smallest_i)
		return (1);
	step = --smallest_i;
	if (smallest_i > (list_length(*head) / 2) && type_move--)
		step = list_length(*head) - smallest_i;
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
