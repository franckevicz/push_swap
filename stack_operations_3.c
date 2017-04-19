/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 12:38:18 by mfrankev          #+#    #+#             */
/*   Updated: 2017/03/05 12:48:59 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		number_of_smaller_n_next(t_lst *head, int i, int size)
{
	int		count;
	t_lst	*cur;

	if (head == NULL)
		return (0);
	count = 0;
	cur = head;
	if (cur->val < i)
		count += cur->val;
	while (cur != head && --size)
	{
		if (cur->val < i)
			count += cur->val;
	}
	return (count);
}

int		number_of_bigger_n_next(t_lst *head, int i, int size)
{
	int		count;
	t_lst	*cur;

	if (head == NULL)
		return (0);
	count = 0;
	cur = head;
	if (cur->val < i)
		count += cur->val;
	while (cur != head && --size)
	{
		if (cur->val > i)
			count += cur->val;
	}
	return (count);
}
