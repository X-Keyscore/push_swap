/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   module1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anraymon <anraymon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 03:04:35 by anraymon          #+#    #+#             */
/*   Updated: 2023/12/05 03:04:35 by anraymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	list_length(t_list_node *head)
{
	size_t	count;

	count = 0;
	while (head)
	{
		head = head->next;
		count++;
	}
	return (count);
}

int	list_push_front(t_list_node **head, int data)
{
	t_list_node	*new_node;

	new_node = malloc(sizeof(*new_node));
	if (!new_node)
		return (0);
	new_node->data = data;
	new_node->next = *head;
	*head = new_node;
	return (1);
}

int	list_push_back(t_list_node **head, int data)
{
	t_list_node	*new_node;
	t_list_node	*temp;

	new_node = (t_list_node *)malloc(sizeof(t_list_node));
	if (!new_node)
		return (0);
	new_node->data = data;
	new_node->next = NULL;
	if (!*head)
	{
		*head = new_node;
		return (1);
	}
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
	return (1);
}

void	list_pop_front(t_list_node **head)
{
	t_list_node	*del;

	if (!*head)
		return ;
	del = *head;
	*head = (*head)->next;
	del->next = NULL;
	free(del);
}

void	list_pop_back(t_list_node **head)
{
	t_list_node	*del;
	t_list_node	*prev;

	if (!*head)
		return ;
	prev = *head;
	while (prev->next->next)
		prev = prev->next;
	del = prev->next;
	prev->next = NULL;
	free(del);
}
