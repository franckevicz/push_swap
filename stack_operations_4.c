/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 21:45:27 by mfrankev          #+#    #+#             */
/*   Updated: 2017/03/05 15:33:56 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_operations(t_lst **operations)
{
	while (*operations)
	{
		if ((*operations)->val == SA || (*operations)->val == SB)
			ft_putstr((*operations)->val == SA ? "sa\n" : "sb\n");
		else if ((*operations)->val == SS)
			ft_putstr("ss\n");
		else if ((*operations)->val == PA)
			ft_putstr("pa\n");
		else if ((*operations)->val == PB)
			ft_putstr("pb\n");
		else if ((*operations)->val == RA)
			ft_putstr("ra\n");
		else if ((*operations)->val == RB)
			ft_putstr("rb\n");
		else if ((*operations)->val == RR)
			ft_putstr("rr\n");
		else if ((*operations)->val == RRA)
			ft_putstr("rra\n");
		else if ((*operations)->val == RRB)
			ft_putstr("rrb\n");
		else if ((*operations)->val == RRR)
			ft_putstr("rrr\n");
		lst_del_elem(operations);
	}
}

void	print_stacks(t_lst *stack_a, t_lst *stack_b)
{
	print_arrays(lst_to_array(stack_a), lst_size(stack_a), \
	lst_to_array(stack_b), lst_size(stack_b));
}

void	print_arrays(int *stack_a, int size_a, int *stack_b, int size_b)
{
	int i;
	int j;

	i = 0;
	j = 0;
	ft_putstr("  STACK_A      |       STACK_B  \n\n");
	while (i < size_a || j < size_b)
	{
		if (i < size_a)
			ft_printf("%8d", stack_a[i]);
		else
			ft_putstr("        ");
		ft_putstr("             ");
		if (j < size_b)
			ft_printf("%8d\n", stack_b[j]);
		else
			ft_putstr("  \n");
		i++;
		j++;
	}
	ft_putstr("\n\n");
	free(stack_a);
	free(stack_b);
	return ;
}

void	del_list(t_lst **head)
{
	int		i;
	t_lst	*tmp;

	tmp = *head;
	i = 0;
	if (*head)
		i = 1;
	while (*head)
		lst_del_elem(head);
	if (i)
		*head = tmp;
	return ;
}

void	lst_swap_first(t_lst *head)
{
	int tmp;

	if (head)
	{
		tmp = head->val;
		head->val = head->next->val;
		head->next->val = tmp;
	}
	return ;
}
