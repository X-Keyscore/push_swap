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
** @return The smallest number in the list
**/
int	get_smallest_value(t_list_node *head)
{
	t_list_node	*tmp;
	size_t		i;
	int			min_value;

	if (!head)
		return (0);
	min_value = head->data;
	tmp = head;
	i = 1;
	while (tmp && tmp->next)
	{
		if (min_value > tmp->next->data)
			min_value = tmp->next->data;
		tmp = tmp->next;
		i++;
	}
	return (min_value);
}
