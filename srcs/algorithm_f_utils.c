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

long	utils_get_move(size_t index, t_list_node *head)
{
	long	step;

	if (!index || !head)
		return (0);
	step = index;
	if (index > (list_length(head) / 2))
		step = ((list_length(head) - index) + 1) * -1;
	return (step);
}

int	utils_calc_div(size_t x)
{
	double	y;
	double	m;
	double	b;

	if (!x)
		return (0);
	if (x < 25)
	{
		y = 1;
	}
	else
	{
		m = (8.0 - 4.0) / (500.0 - 100.0);
		b = 4.0 - m * 100.0;
		y = m * x + b;
	}
	return ((int)y);
}

int	utils_pre_stack_inf(t_list_node **stack_1, t_list_node **stack_2,
	int data_target)
{
	if (end_is_inferior_at(*stack_2, *stack_1) && (*stack_2)->data < data_target
		&& (*stack_2)->data < (*stack_1)->data)
	{
		ctrl_err(stack_1, stack_2, pa_pb(stack_2, stack_1, 0));
		return (1);
	}
	else if (end_is_inferior_at(*stack_2, *stack_1)
		&& (*stack_2)->data < data_target
		&& (*stack_2)->data > (*stack_1)->data)
	{
		ctrl_err(stack_1, stack_2,
			move_top_sup_at_in(*stack_2, stack_1, 0));
		ctrl_err(stack_1, stack_2, pa_pb(stack_2, stack_1, 0));
		return (1);
	}
	return (0);
}
