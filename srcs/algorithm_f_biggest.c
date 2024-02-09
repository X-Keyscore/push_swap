/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_f_biggest.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anraymon <anraymon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:14:00 by anraymon          #+#    #+#             */
/*   Updated: 2023/12/16 19:34:15 by anraymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
** @return 1 if the first node in head is the biggest or else 0.
**/
int	is_biggest(t_list_node *head)
{
	t_list_node	*cmp;

	cmp = head;
	while (cmp)
	{
		if (head->data < cmp->data)
			return (0);
		cmp = cmp->next;
	}
	return (1);
}

/**
** @return 1 if static_node is the biggest in head or else 0.
**/
int	is_biggest_in(t_list_node *static_node, t_list_node *head)
{
	while (static_node && head)
	{
		if (head->data > static_node->data)
			return (0);
		head = head->next;
	}
	return (1);
}

/**
** @return The biggest number in the list.
**/
int	get_big_val(t_list_node *head)
{
	t_list_node	*tmp;
	int			max_value;

	if (!head)
		return (0);
	max_value = head->data;
	tmp = head;
	while (tmp)
	{
		if (max_value < tmp->data)
			max_value = tmp->data;
		tmp = tmp->next;
	}
	return (max_value);
}
