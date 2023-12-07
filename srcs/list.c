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

/**
* Insert an element at the begin of list
* @param head_node struct t_list_node
* @param data Your data
*/
void	list_push_front(t_list_node **head, int data)
{
  t_list_node *new_node;

	new_node = malloc(sizeof(*new_node));
	if (!new_node)
	{
		list_clear(head);
		exit(EXIT_FAILURE);
	}
  new_node->data = data;
  new_node->next = (*head);
  new_node->prev = NULL;
  if ((*head) != NULL)
    (*head)->prev = new_node;
  (*head) = new_node;
}

/**
** @return 1 if the node data is the biggest or else 0
**/
void	list_push_back(t_list_node **head, int data)
{
  t_list_node *new_node;
	t_list_node *temp;

  new_node = malloc(sizeof(*new_node));
	if (!new_node)
	{
		list_clear(head);
		exit(EXIT_FAILURE);
	}
  new_node->data = data;
  new_node->next = NULL;
  temp = *head;
  if (*head == NULL) {
    new_node->prev = NULL;
    *head = new_node;
    return;
  }
  while (temp->next != NULL)
    temp = temp->next;
  temp->next = new_node;
  new_node->prev = temp;
}

void	list_pop_front(t_list_node **head)
{
	t_list_node *curr;

	if ((*head) == NULL)
		return ;
	curr = *head;
	*head = (*head)->next;
	curr->next = NULL;
	free(curr);
}

void	list_pop_back(t_list_node **head)
{
	t_list_node *curr;
	t_list_node *prev;

	if ((*head) == NULL)
		return ;
	curr = *head;
	while (curr->next != NULL) {
			curr = curr->next;
	}
	prev = curr->prev;
	prev->next = NULL;
	curr->prev = NULL;
	free(curr);
}
