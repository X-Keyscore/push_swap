/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anraymon <anraymon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 00:48:00 by anraymon          #+#    #+#             */
/*   Updated: 2023/12/07 00:48:00 by anraymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_list_node *head)
{
	t_list_node *tmp;

	if (head == NULL)
			return (1);
	tmp = head;
	while (tmp->next)
	{
		if (tmp->data >= tmp->next->data)
			return (0);
		tmp=tmp->next;
	}
	return (1);
}

/**
** @param end_index stop comparison at this index
** @return 1 if the node data is the smallest or else 0
**/
int	is_smallest(t_list_node *head, size_t end_index)
{
	t_list_node	*cmp;
	size_t index;

	index = 0;
	cmp = head;
	while (head && index < end_index)
	{
		if (head->data < cmp->data)
			return (0);
		head = head->next;
		index++;
	}
	return (1);
}

int	is_smallest_in(t_list_node *stack_1, t_list_node *stack_2, size_t end_index)
{
	size_t index;

	index = 0;
	while (stack_1 && stack_2 && index < end_index)
	{
		if (stack_1->data < stack_2->data)
			return (0);
		stack_1 = stack_1->next;
		index++;
	}
	return (1);
}


size_t	move_top_smallest(t_list_node **head)
{
	int			type_move;
	size_t	smallest_index;
	size_t	step;
	size_t	op;

	op = 0;
	if (!*head)
		return (op);
	type_move = 1;
	smallest_index = get_smallest_index(*head);
	if (smallest_index > (list_length(*head) / 2))
		type_move = 0;
	if (type_move)
		step = smallest_index;
	else
		step = list_length(*head) - smallest_index;
	while (step--)
	{
		if (type_move)
			ra_rb(head, 1);
		else
			rra_rrb(head, 1);
		op++;
	}
	return (op);
}

size_t	algorithm(t_list_node **stack_1, t_list_node **stack_2)
{
	size_t	stack_1_len;
	size_t	safe_step;
	size_t	op;
	int			loop;

	op = 0;
	loop = 1;
	safe_step = 0;
	while (loop)
	{
		if (!*stack_2 && is_sorted(*stack_1))
			break ;
		if (is_smallest(*stack_1, list_length(*stack_1) - safe_step))
		{
			op += ra_rb(stack_1, 0);
			safe_step++;
		}
		else
			op += pa_pb(stack_1, stack_2, 1);
		op += move_top_smallest(stack_2);
		if (is_smallest_in(*stack_1, *stack_2, list_length(*stack_1) - safe_step))
			op += pa_pb(stack_2, stack_1, 0);
	}
	return (op);
}