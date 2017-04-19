/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 21:44:22 by mfrankev          #+#    #+#             */
/*   Updated: 2017/03/04 21:44:25 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				pushing_numbers(int argc, char **argv, t_lst **stack)
{
	int i;

	i = 0;
	if (argc == 0)
		return (1);
	while (i < argc)
	{
		if (!check_val(argv[i], *stack))
			return (0);
		lst_push_back(stack, ft_atoi(argv[i]));
		i++;
	}
	return (1);
}

int				check_val(char *num, t_lst *stack)
{
	int i;
	int val;

	i = 0;
	if (num[i] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i++]))
			return (0);
	}
	val = ft_atoi(num);
	if (ft_strlen(num) > 11)
		return (0);
	if ((long long)val != ft_atoll(num))
		return (0);
	if (lst_search_val(stack, val))
		return (0);
	return (1);
}

long long		ft_atoll(const char *str)
{
	char		*s;
	int			flag;
	long long	result;

	result = 0;
	flag = 1;
	s = (char *)str;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '+')
		s++;
	else if (*s == '-')
	{
		s++;
		flag = -1;
	}
	while (*s >= '0' && *s <= '9')
	{
		result *= 10;
		result += *s++ - '0';
	}
	return (result * flag);
}
