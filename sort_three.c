/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 21:44:34 by mfrankev          #+#    #+#             */
/*   Updated: 2017/03/04 21:44:36 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	short_sort_3(t_lst **stack_a)
{
	if (((*stack_a)->val < (*stack_a)->next->val) && ((*stack_a)->next->val < \
	(*stack_a)->prev->val) && ((*stack_a)->next->next->val > (*stack_a)->val))
	{
		stack_operation("RRA", stack_a, NULL);
		stack_operation("SA", stack_a, NULL);
	}
	else if (((*stack_a)->val > (*stack_a)->next->val) && \
	((*stack_a)->next->val < (*stack_a)->prev->val) &&\
	((*stack_a)->next->next->val < (*stack_a)->val))
		stack_operation("RA", stack_a, NULL);
	else if (((*stack_a)->val > (*stack_a)->next->val) && \
	((*stack_a)->next->val > (*stack_a)->prev->val) &&\
	((*stack_a)->next->next->val < (*stack_a)->val))
	{
		stack_operation("SA", stack_a, NULL);
		stack_operation("RRA", stack_a, NULL);
	}
	else if (((*stack_a)->val > (*stack_a)->next->val) && \
	((*stack_a)->next->val < (*stack_a)->prev->val) && \
	((*stack_a)->next->next->val > (*stack_a)->val))
		stack_operation("SA", stack_a, NULL);
	else if (((*stack_a)->val > (*stack_a)->next->val) && \
	((*stack_a)->next->val < (*stack_a)->prev->val) && \
	((*stack_a)->next->next->val > (*stack_a)->val))
		stack_operation("RRA", stack_a, NULL);
}

void	sort_three(t_lst **stack_a, t_lst **stack_b)
{
	if (lst_size(*stack_a) == 3)
		short_sort_3(stack_a);
	if (lst_is_nsorted(*stack_a, 3))
		return ;
	if ((*stack_a)->val > (*stack_a)->next->val)
		stack_operation("SA", stack_a, stack_b);
	if (lst_is_nsorted(*stack_a, 3))
		return ;
	stack_operation("RA", stack_a, stack_b);
	if ((*stack_a)->val > (*stack_a)->next->val)
		stack_operation("SA", stack_a, stack_b);
	stack_operation("RRA", stack_a, stack_b);
	if ((*stack_a)->val > (*stack_a)->next->val)
		stack_operation("SA", stack_a, stack_b);
}

void	rev_sort_three(t_lst **stack_a, t_lst **stack_b)
{
	if (lst_size(*stack_b) == 3)
		short_rev_sort_3(stack_b);
	if (lst_is_nrev_sorted(*stack_b, 3))
		return ;
	if ((*stack_b)->val < (*stack_b)->next->val)
		stack_operation("SB", stack_a, stack_b);
	stack_operation("RB", stack_a, stack_b);
	if ((*stack_b)->val < (*stack_b)->next->val)
		stack_operation("SB", stack_a, stack_b);
	stack_operation("RRB", stack_a, stack_b);
	if ((*stack_b)->val < (*stack_b)->next->val)
		stack_operation("SB", stack_a, stack_b);
}

void	short_rev_sort_3(t_lst **stack_b)
{
	if (((*stack_b)->val > (*stack_b)->next->val) && ((*stack_b)->next->val < \
	(*stack_b)->prev->val) && ((*stack_b)->next->next->val < (*stack_b)->val))
	{
		stack_operation("RRB", NULL, stack_b);
		stack_operation("SB", NULL, stack_b);
	}
	else if (((*stack_b)->val < (*stack_b)->next->val) && \
	((*stack_b)->next->val > (*stack_b)->prev->val) &&\
	((*stack_b)->next->next->val > (*stack_b)->val))
		stack_operation("RB", NULL, stack_b);
	else if (((*stack_b)->val < (*stack_b)->next->val) && \
	((*stack_b)->next->val < (*stack_b)->prev->val) &&\
	((*stack_b)->next->next->val > (*stack_b)->val))
	{
		stack_operation("SB", NULL, stack_b);
		stack_operation("RRB", NULL, stack_b);
	}
	else if (((*stack_b)->val < (*stack_b)->next->val) && \
	((*stack_b)->next->val > (*stack_b)->prev->val) && \
	((*stack_b)->next->next->val < (*stack_b)->val))
		stack_operation("SB", NULL, stack_b);
	else if (((*stack_b)->val > (*stack_b)->next->val) && \
	((*stack_b)->next->val < (*stack_b)->prev->val) && \
	((*stack_b)->next->next->val > (*stack_b)->val))
		stack_operation("RRB", NULL, stack_b);
}
