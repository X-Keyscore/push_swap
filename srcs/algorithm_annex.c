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
** @param main_node must not be null
**/
size_t	get_smallest_index(t_list_node *main_node)
{
	t_list_node	*min_node;
	size_t	min_i;
	size_t i;

	if (!main_node->next)
		return (0);
	min_node = main_node;
	min_i = 0;
	i = 0;
	while (main_node)
	{
		if (min_node->data > main_node->data)
		{
			min_node = main_node;
			min_i = i;
		}
		main_node = main_node->next;
		i++;
	}
	return (min_i);
}