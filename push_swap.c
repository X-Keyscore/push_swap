/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anraymon <anraymon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 01:27:25 by anraymon          #+#    #+#             */
/*   Updated: 2023/12/05 01:27:25 by anraymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void displayList(t_list_node *stack_1, t_list_node *stack_2)
{
  while (stack_1 && stack_2) {
   	printf("%5d | %d\n", stack_1->data, stack_2->data);
    stack_1 = stack_1->next;
		stack_2 = stack_2->next;
  }
	while (stack_1) {
    printf("%5d | \n", stack_1->data);
    stack_1 = stack_1->next;
  }
		while (stack_2) {
    printf("%5s | %d\n", "", stack_2->data);
    stack_2 = stack_2->next;
  }
}



int	main(int argc, char **argv)
{
	t_list_node *stack_1 = NULL;
	t_list_node *stack_2 = NULL;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	parser(argc, argv, &stack_1);
	//displayList(stack_1, stack_2);
	//printf("op = %ld\n", algorithm(&stack_1, &stack_2));
	//displayList(stack_1, stack_2);
	list_clear(&stack_1);
	list_clear(&stack_2);
	/*
	list_push_back(&stack_1, 2);
	list_push_back(&stack_1, 1);
	list_push_back(&stack_1, 3);
	list_push_back(&stack_1, 6);
	list_push_back(&stack_1, 5);
	list_push_back(&stack_1, 8);

	displayList(stack_1, stack_2);
	printf("size = %ld\n", list_length(stack_1));
	printf("op = %ld\n", algorithm(&stack_1, &stack_2));
	displayList(stack_1, stack_2);*/

}
