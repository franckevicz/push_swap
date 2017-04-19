/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 12:39:34 by mfrankev          #+#    #+#             */
/*   Updated: 2017/03/05 12:48:36 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_n_pivot1(t_lst *stack_a, int n)
{
	int *array;
	int size;
	int tmp;

	size = n;
	array = lst_to_array(stack_a);
	gnome_sort(array, n);
	tmp = array[PIVOT_RANGE];
	free(array);
	return (tmp);
}

void	gnome_sort(int *array, int size)
{
	int i;
	int tmp;

	i = 1;
	while (i < size)
	{
		if (array[i - 1] <= array[i])
			++i;
		else
		{
			tmp = array[i];
			array[i] = array[i - 1];
			array[i - 1] = tmp;
			--i;
			if (i == 0)
				i = 1;
		}
	}
	return ;
}

int		get_pivot1(t_lst *stack_a)
{
	int *array;
	int size;
	int tmp;

	if (stack_a == NULL)
		return (MIN_INT);
	size = lst_size(stack_a);
	array = lst_to_array(stack_a);
	gnome_sort(array, size);
	tmp = array[PIVOT_RANGE];
	free(array);
	return (tmp);
}
