/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anraymon <anraymon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 01:02:13 by anraymon          #+#    #+#             */
/*   Updated: 2023/12/07 01:02:13 by anraymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	putstr(char *s, int fd)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		i++;
	write(fd, s, i);
}

int	is_digit(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (!(s[i] >= '0' && '9' >= s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	neg;
	int	res;

	i = 0;
	neg = 1;
	res = 0;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + (nptr[i] - '0');
		i++;
	}
	return (res * neg);
}

void	parser(int argc, char **argv, t_list_node **head)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (!is_digit(argv[i]))
		{
			putstr("Error\n", 2);
			list_clear(head);
			exit(EXIT_FAILURE);
		}
		list_push_back(head, ft_atoi(argv[i]));
		i++;
	}
	if (list_peer(*head, list_length(*head)))
	{
		putstr("Error\n", 2);
		list_clear(head);
		exit(EXIT_FAILURE);
	}
}
