/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anraymon <anraymon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 01:05:39 by anraymon          #+#    #+#             */
/*   Updated: 2023/12/06 01:05:39 by anraymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
** @brief Take the first element at the top of stack_pop
** and place it on stack_push.
** Does nothing if stack_pop is empty.
*/
int	pa_pb(t_list_node **stack_pop, t_list_node **stack_push, int mode)
{
	if (!*stack_pop)
		return (1);
	if (!list_push_front(stack_push, (*stack_pop)->data))
		return (0);
	list_pop_front(stack_pop);
	if (mode == 0)
		putstr("pa\n", 1);
	else
		putstr("pb\n", 1);
	return (1);
}

/**
** @brief Shifts all elements of stack one position up.
** The first element becomes the last.
*/
int	ra_rb(t_list_node **stack, int mode)
{
	if (!*stack)
		return (1);
	if (!list_push_back(stack, (*stack)->data))
		return (0);
	list_pop_front(stack);
	if (mode == 0)
		putstr("ra\n", 1);
	else
		putstr("rb\n", 1);
	return (1);
}

/**
** @brief Move all elements in the stack one position down.
** The last element becomes the first.
*/
int	rra_rrb(t_list_node **stack, int mode)
{
	t_list_node	*tmp;

	if (!*stack)
		return (1);
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	if (!list_push_front(stack, tmp->data))
		return (0);
	list_pop_back(stack);
	if (mode == 0)
		putstr("rra\n", 1);
	else
		putstr("rrb\n", 1);
	return (1);
}

/**
** @brief Swap element on stack.
*/
int	sa_sb(t_list_node **stack, int mode)
{
	int	tmp_1;
	int	tmp_2;

	if (!*stack || !(*stack)->next)
		return (1);
	tmp_1 = (*stack)->data;
	list_pop_front(stack);
	tmp_2 = (*stack)->data;
	list_pop_front(stack);
	if (!list_push_front(stack, tmp_1))
		return (0);
	if (!list_push_front(stack, tmp_2))
		return (0);
	if (mode == 0)
		putstr("sa\n", 1);
	else
		putstr("sb\n", 1);
	return (1);
}
