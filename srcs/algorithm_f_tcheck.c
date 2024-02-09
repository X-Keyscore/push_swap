/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_f_tcheck.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anraymon <anraymon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 21:58:35 by anraymon          #+#    #+#             */
/*   Updated: 2023/12/16 15:59:20 by anraymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
** @return 1 if there are still numbers less than the max
** and greater than the mid or 0.
**/
int	tcheck_below_max(t_list_node *head, long max, long mid)
{
	t_list_node	*tmp;

	tmp = head;
	while (tmp)
	{
		if (!is_biggest_in(tmp, head) && tmp->data >= mid && tmp->data < max)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

/**
** @return 1 if there are still numbers greater than the min
** and less than the mid or 0.
**/
int	tcheck_above_min(t_list_node *head, long min, long mid)
{
	t_list_node	*tmp;

	tmp = head;
	while (tmp)
	{
		if (!is_biggest_in(tmp, head) && tmp->data <= mid && tmp->data > min)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
