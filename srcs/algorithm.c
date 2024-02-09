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
#include <stdio.h>
/**
** @brief Simple sorting for a small stack.
**/
void	sorter_simple(t_list_node **stack_1, t_list_node **stack_2,
	size_t len_stack_1)
{
	size_t	i;

	i = len_stack_1;
	while (i-- > 3)
	{
		ctrl_err(stack_1, stack_2, move_top_smallest_in(stack_1, 0));
		ctrl_err(stack_1, stack_2, pa_pb(stack_1, stack_2, 1));
	}
	while (!list_sorted(*stack_1))
	{
		if (!is_biggest(*stack_1) && !is_smallest(*stack_1))
			ctrl_err(stack_1, stack_2, sa_sb(stack_1, 0));
		if (!list_sorted(*stack_1))
			ctrl_err(stack_1, stack_2, ra_rb(stack_1, 0));
	}
	while (*stack_2)
	{
		ctrl_err(stack_1, stack_2,
			move_top_sup_at_in(*stack_1, stack_2, 1));
		ctrl_err(stack_1, stack_2, pa_pb(stack_2, stack_1, 0));
	}
}

/**
** @brief Create a linear list starting from the center outwards.
** Largest towards the top, smallest towards the bottom.
**/
void	pre_sorter_linear(t_list_node **stack_1, t_list_node **stack_2,
	long max_gap, long min_gap)
{
	long	mid;
	long	max;
	long	min;

	mid = ((long)get_big_val(*stack_1) + (long)get_sml_val(*stack_1)) / 2;
	max = mid + max_gap;
	min = mid - min_gap;
	while (list_length(*stack_1) > 1)
	{
		if (!is_biggest(*stack_1) && (*stack_1)->data >= mid
			&& (*stack_1)->data < max)
			ctrl_err(stack_1, stack_2, pa_pb(stack_1, stack_2, 1));
		else if (!is_biggest(*stack_1) && (*stack_1)->data <= mid
			&& (*stack_1)->data > min)
		{
			ctrl_err(stack_1, stack_2, pa_pb(stack_1, stack_2, 1));
			ctrl_err(stack_1, stack_2, ra_rb(stack_2, 1));
		}
		else
			ctrl_err(stack_1, stack_2, ra_rb(stack_1, 0));
		if (!tcheck_below_max(*stack_1, max, mid))
			max += max_gap;
		if (!tcheck_above_min(*stack_1, min, mid))
			min -= min_gap;
	}
}

void	move_inf_optimize(t_list_node **stack_1, t_list_node **stack_2,
	long move_inf)
{
	t_list_node	*node_target;
	int			data_target;

	if (move_inf > 0 || move_inf < 0)
	{
		data_target = get_inferior_node_at_in(*stack_1, *stack_2)->data;
		node_target = list_create_node(data_target);
		ctrl_err(stack_1, stack_2, !!node_target);
	}
	else
		return ;
	while (*stack_2 && data_target != (*stack_2)->data && move_inf > 0)
	{
		if (!utils_pre_stack_inf(stack_1, stack_2, data_target))
			ctrl_err(stack_1, stack_2, ra_rb(stack_2, 1));
	}
	while (*stack_2 && data_target != (*stack_2)->data && move_inf < 0)
	{
		ctrl_err(stack_1, stack_2, rra_rrb(stack_2, 1));
		if (data_target == (*stack_2)->data)
			break ;
		utils_pre_stack_inf(stack_1, stack_2, data_target);
	}
	ctrl_err(stack_1, stack_2, move_top_sup_at_in(node_target, stack_1, 0));
	free(node_target);
}

/**
** @brief Optimize for stack linear sort.
**/
void	sorter_optimize(t_list_node **stack_1, t_list_node **stack_2)
{
	long	move_inf;

	while (*stack_2)
	{
		if (inf_is_in(*stack_1, *stack_1, *stack_2) == 1)
			ctrl_err(stack_1, stack_2,
				move_top_inf_at_in(*stack_1, stack_1, 0));
		else
		{
			move_inf = utils_get_move(get_inf_idx_at_in(*stack_1, *stack_2),
					*stack_2);
			move_inf_optimize(stack_1, stack_2, move_inf);
			ctrl_err(stack_1, stack_2, pa_pb(stack_2, stack_1, 0));
		}
	}
}

/**
** @brief Pre sorte in stack 2 is sorte in stack 1.
**/
void	algorithm(t_list_node **stack_1, t_list_node **stack_2)
{
	size_t	len_stack_1;
	long	mid;
	long	max_gap;
	long	min_gap;

	if (list_sorted(*stack_1))
		return ;
	len_stack_1 = list_length(*stack_1);
	if (len_stack_1 <= 10)
		sorter_simple(stack_1, stack_2, len_stack_1);
	if (list_sorted(*stack_1))
		return ;
	mid = ((long)get_big_val(*stack_1) + (long)get_sml_val(*stack_1)) / 2;
	max_gap = ((long)get_big_val(*stack_1) - mid) / utils_calc_div(len_stack_1);
	min_gap = (mid - (long)get_sml_val(*stack_1)) / utils_calc_div(len_stack_1);
	pre_sorter_linear(stack_1, stack_2, max_gap, min_gap);
	printf("stack_1 f = %d\n", (*stack_1)->data);
	sorter_optimize(stack_1, stack_2);
	if (!list_sorted(*stack_1))
		ctrl_err(stack_1, stack_2, move_top_smallest_in(stack_1, 0));
}
