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

t_list_node	*list_create_node(int data)
{
	t_list_node	*new_node;

	new_node = (t_list_node *)malloc(sizeof(t_list_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

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

int	list_sorted(t_list_node *head)
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
