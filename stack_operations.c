/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 21:45:35 by mfrankev          #+#    #+#             */
/*   Updated: 2017/03/04 21:45:37 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_add_elem(t_lst **head, int data)
{
	t_lst	*elem;
	t_lst	*prev;

	elem = (t_lst*)malloc(sizeof(t_lst));
	elem->val = data;
	if (*head)
	{
		prev = (*head)->prev;
		elem->next = *head;
		elem->prev = prev;
		prev->next = elem;
		(*head)->prev = elem;
	}
	else
	{
		elem->next = elem;
		elem->prev = elem;
	}
	*head = elem;
	return ;
}

void	lst_del_elem(t_lst **elem)
{
	t_lst *next;
	t_lst *prev;

	if (*elem == NULL)
		return ;
	next = (*elem)->next;
	prev = (*elem)->prev;
	prev->next = next;
	next->prev = prev;
	free(*elem);
	if (next == *elem)
		*elem = NULL;
	else
		*elem = next;
	return ;
}

void	lst_rotate(t_lst **head)
{
	if (*head)
		*head = (*head)->next;
	return ;
}

void	lst_rev_rotate(t_lst **head)
{
	if (*head)
		(*head) = (*head)->prev;
	return ;
}

void	push_operation(char *oper, t_lst **commands)
{
	if (ft_strstr(oper, "RRR"))
		lst_push_back(commands, RRR);
	else if (ft_strstr(oper, "RRA"))
		lst_push_back(commands, RRA);
	else if (ft_strstr(oper, "RRB"))
		lst_push_back(commands, RRB);
	else if (ft_strstr(oper, "RR"))
		lst_push_back(commands, RR);
	else if (ft_strstr(oper, "RA"))
		lst_push_back(commands, RA);
	else if (ft_strstr(oper, "RB"))
		lst_push_back(commands, RB);
	else if (ft_strstr(oper, "SS"))
		lst_push_back(commands, SS);
	else if (ft_strstr(oper, "SA"))
		lst_push_back(commands, SA);
	else if (ft_strstr(oper, "SB"))
		lst_push_back(commands, SB);
	else if (ft_strstr(oper, "PA"))
		lst_push_back(commands, PA);
	else if (ft_strstr(oper, "PB"))
		lst_push_back(commands, PB);
	return ;
}
