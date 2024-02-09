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

int	is_int(char *s, size_t start, size_t end)
{
	end = end - start;
	if (s[start] == '+')
		end--;
	if (s[start] == '-' && end > 11)
		return (0);
	else if (s[start] != '-' && end > 10)
		return (0);
	if (s[start] == '-' && end > 10 && ft_atoi(s) < INT_MIN)
		return (0);
	else if (s[start] != '-' && end > 9 && ft_atoi(s) > INT_MAX)
		return (0);
	return (1);
}

int	is_digit_int(char *s)
{
	size_t	i;
	size_t	start;

	i = 0;
	if (!s || !s[i])
		return (0);
	while (s[i] == ' ')
		i++;
	start = i;
	if (s[i] && (s[i] == '-' || s[i] == '+'))
		i++;
	if (!s[i])
		return (0);
	while (s[i] >= '0' && '9' >= s[i])
		i++;
	if (!(s[i - 1] >= '0' && '9' >= s[i - 1]) || !is_int(s, start, i))
		return (0);
	if (!s[i])
		return (1);
	while (s[i] == ' ')
		i++;
	if (s[i])
		return (0);
	return (1);
}

void	parser(int argc, char **argv, t_list_node **head)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		ctrl_err(head, NULL, is_digit_int(argv[i]));
		ctrl_err(head, NULL, list_push_back(head, ft_atoi(argv[i])));
		i++;
	}
	ctrl_err(head, NULL, !list_peer(*head));
}
