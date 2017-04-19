/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_6.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 21:45:41 by mfrankev          #+#    #+#             */
/*   Updated: 2017/03/04 21:45:43 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		lst_size(t_lst *head)
{
	int		size;
	t_lst	*current;

	size = 0;
	if (head == NULL)
	{
		return (0);
	}
	current = head;
	size = 1;
	while (current->next != head)
	{
		current = current->next;
		size++;
	}
	return (size);
}

int		lst_is_num_bigger_in_n(t_lst *head, int i, int size)
{
	t_lst	*cur;

	if (size <= 0)
		return (0);
	if (head == NULL)
		return (0);
	if (head == head->next || size == 1)
		return ((i < head->val ? 1 : 0));
	cur = head;
	if (cur->val > i)
		return (1);
	cur = cur->next;
	while (cur != head && size-- > 1)
	{
		if (cur->val > i)
			return (1);
		cur = cur->next;
	}
	return (0);
}

int		lst_is_num_smaller_in_n(t_lst *head, int i, int size)
{
	t_lst	*cur;

	if (size <= 0)
		return (0);
	if (head == NULL)
		return (0);
	if (head == head->next || size == 1)
		return ((i > head->val ? 1 : 0));
	cur = head;
	if (cur->val < i)
		return (1);
	cur = cur->next;
	while (cur != head && size-- > 1)
	{
		if (cur->val < i)
			return (1);
		cur = cur->next;
	}
	return (0);
}

int		*lst_to_array(t_lst *head)
{
	int		*array;
	int		size;
	int		i;
	t_lst	*cur;

	i = 0;
	if (head == NULL)
		return (NULL);
	size = lst_size(head);
	array = (int*)malloc(sizeof(int) * size + 1);
	cur = head;
	array[i++] = (cur ? cur->val : 0);
	if (cur)
		cur = cur->next;
	while (cur != head)
	{
		array[i++] = cur->val;
		cur = cur->next;
	}
	return (array);
}

int		lst_search_val(t_lst *head, int value)
{
	t_lst *elem;

	if (head == NULL)
		return (0);
	elem = head;
	if (elem->val == value)
		return (1);
	elem = elem->next;
	while (elem != head)
	{
		if (elem->val == value)
			return (1);
		elem = elem->next;
	}
	return (0);
}
