/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_annex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anraymon <anraymon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 01:59:22 by anraymon          #+#    #+#             */
/*   Updated: 2023/12/07 01:59:22 by anraymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	list_peer(t_list_node *head)
{
	t_list_node	*head_cmp;

	while (head)
	{
		head_cmp = head->next;
		while (head_cmp)
		{
			if (head->data == head_cmp->data)
				return (1);
			head_cmp = head_cmp->next;
		}
		head = head->next;
	}
	return (0);
}

void	list_clear(t_list_node **head)
{
	t_list_node	*prev;

	prev = *head;
	while (*head)
	{
		*head = (*head)->next;
		free(prev);
		prev = *head;
	}
}
