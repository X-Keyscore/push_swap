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

long	ft_atoi(const char *nptr)
{
	int		i;
	int		neg;
	long	res;

	i = 0;
	neg = 1;
	res = 0;
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

int	is_digit_int(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	if (s[0] == '-' || s[0] == '+')
		i++;
	while (s[i])
	{
		if (!(s[i] >= '0' && '9' >= s[i]))
			return (0);
		i++;
	}
	if (s[0] == '+')
		i--;
	if (s[0] == '-' && i > 11)
		return (0);
	else if (s[0] != '-' && i > 10)
		return (0);
	if (s[0] == '-' && i > 10 && ft_atoi(s) < INT_MIN)
		return (0);
	else if (s[0] != '-' && i > 9 && ft_atoi(s) > INT_MAX)
		return (0);
	return (1);
}

void	parser(int argc, char **argv, t_list_node **head)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		ctrl_err(is_digit_int(argv[i]), head, NULL);
		ctrl_err(list_push_back(head, ft_atoi(argv[i])), head, NULL);
		i++;
	}
	ctrl_err(!list_peer(*head), head, NULL);
}
