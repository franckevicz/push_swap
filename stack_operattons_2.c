/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operattons_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 21:45:53 by mfrankev          #+#    #+#             */
/*   Updated: 2017/03/05 13:37:14 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_push_from_stack(t_lst **donor, t_lst **patient)
{
	int tmp;

	if (!(*donor))
		return ;
	tmp = (*donor)->val;
	lst_del_elem(donor);
	lst_add_elem(patient, tmp);
	return ;
}

int		lst_is_sorted(t_lst *head)
{
	int		tmp;
	t_lst	*cur;

	if (head == NULL)
		return (1);
	cur = head;
	tmp = cur->val;
	cur = cur->next;
	if (tmp > cur->val)
		return (0);
	while (cur->next != head)
	{
		tmp = cur->val;
		cur = cur->next;
		if (tmp > cur->val)
			return (0);
	}
	return (1);
}

int		lst_is_nsorted(t_lst *head, int n)
{
	int		tmp;
	t_lst	*cur;

	if (n <= 1)
		return (1);
	cur = head;
	tmp = cur->val;
	cur = cur->next;
	if (tmp > cur->val)
		return (0);
	while (cur->next != head && --n > 1)
	{
		tmp = cur->val;
		cur = cur->next;
		if (tmp > cur->val)
			return (0);
	}
	return (1);
}

int		lst_is_nrev_sorted(t_lst *head, int n)
{
	int		tmp;
	t_lst	*cur;

	if (n <= 1)
		return (1);
	cur = head;
	tmp = cur->val;
	cur = cur->next;
	if (tmp < cur->val)
		return (0);
	while (cur->next != head && --n > 1)
	{
		tmp = cur->val;
		cur = cur->next;
		if (tmp < cur->val)
			return (0);
	}
	return (1);
}

void	lst_push_back(t_lst **head, int data)
{
	t_lst *elem;
	t_lst *prev;

	g_count++;
	if (!(*head))
		lst_add_elem(head, data);
	else
	{
		prev = (*head)->prev;
		elem = (t_lst*)malloc(sizeof(t_lst));
		elem->val = data;
		elem->next = (*head);
		elem->prev = prev;
		prev->next = elem;
		(*head)->prev = elem;
	}
	return ;
}
