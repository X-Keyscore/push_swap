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

/**
** @return 1 if list is sorted or 0
**/
int	is_sorted(t_list_node *head)
{
	t_list_node	*tmp;

	if (!head)
		return (1);
	tmp = head;
	while (tmp->next)
	{
		if (tmp->data >= tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

/**
** @return 1 if there are still numbers smaller than max or 0 
**/
int	below_max(t_list_node *head, long max)
{
	t_list_node	*tmp;

	tmp = head;
	while (tmp)
	{
		if (tmp->data <= max && !is_biggest_in(tmp, head))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

/**
** @brief Sorted optimized to create packages from smallest to largest.
** The smallest numbers in the center and the largest on the outside.
**/
void	pre_sort(t_list_node **stack_1, t_list_node **stack_2,
	long max, int push_mode)
{
	max = (long)get_smallest_value(*stack_1) + max;
	while (list_length(*stack_1) > 1)
	{
		while (below_max(*stack_1, max))
		{
			if ((*stack_1)->data <= max && !is_biggest(*stack_1))
			{
				ctrl_err(pa_pb(stack_1, stack_2, 1), stack_1, stack_2);
				if (push_mode)
					ctrl_err(ra_rb(stack_2, 1), stack_1, stack_2);
			}
			else if ((*stack_1)->data <= max + 30 && !is_biggest(*stack_1))
			{
				ctrl_err(pa_pb(stack_1, stack_2, 1), stack_1, stack_2);
				if (!push_mode)
					ctrl_err(ra_rb(stack_2, 1), stack_1, stack_2);
			}
			else
				ctrl_err(ra_rb(stack_1, 0), stack_1, stack_2);
		}
		max = (long)get_smallest_value(*stack_1) + 42;
		push_mode *= -1;
	}
}

void	algorithm(t_list_node **stack_1, t_list_node **stack_2)
{
	long		max;
	int			push_mode;

	push_mode = -1;
	max = 42;
	if (!*stack_2 && is_sorted(*stack_1))
		return ;
	pre_sort(stack_1, stack_2, max, push_mode);
	while (*stack_2)
	{
		ctrl_err(move_top_inferior_at_in(*stack_1, stack_2, 1),
			stack_1, stack_2);
		ctrl_err(pa_pb(stack_2, stack_1, 0), stack_1, stack_2);
	}
}
