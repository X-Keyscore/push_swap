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

void	ctrl_err(int success, t_list_node **stack_1, t_list_node **stack_2)
{
	if (success)
		return ;
	putstr("Error\n", 2);
	if (stack_1)
		list_clear(stack_1);
	if (stack_2)
		list_clear(stack_2);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_list_node	*stack_1;
	t_list_node	*stack_2;

	stack_1 = NULL;
	stack_2 = NULL;
	if (argc < 2)
		exit(EXIT_SUCCESS);
	parser(argc, argv, &stack_1);
	algorithm(&stack_1, &stack_2);
	list_clear(&stack_1);
	list_clear(&stack_2);
	exit(EXIT_SUCCESS);
}
