/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 21:44:55 by mfrankev          #+#    #+#             */
/*   Updated: 2017/03/05 13:49:12 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_lst *stack_a;
	t_lst *stack_b;
	t_lst *commands;

	stack_a = NULL;
	stack_b = NULL;
	skip_argc_argv(&argc, &argv, 1);
	if (argc == 0)
		return (2);
	if (!(pushing_numbers(argc, argv, &stack_a)))
	{
		ft_putstr(RED"Error\n"RESET);
		return (1);
	}
	commands = quicksort_stack(&stack_a, &stack_b, lst_size(stack_a));
	if (commands)
	{
		optimize(&commands);
		print_operations(&commands);
	}
	del_list(&stack_a);
	del_list(&stack_b);
	return (0);
}

t_lst	*quicksort_stack(t_lst **stack_a, t_lst **stack_b, int sort_len)
{
	int pushed;
	int rotated;
	int pivot;

	pushed = 0;
	rotated = 0;
	pivot = get_n_pivot1(*stack_a, sort_len);
	short_sort(stack_a, stack_b, sort_len);
	if (lst_is_nsorted(*stack_a, sort_len))
		return (stack_operation("finish", stack_a, stack_b));
	while (lst_is_num_smaller_in_n(*stack_a, pivot, sort_len - pushed \
	- rotated))
	{
		if ((*stack_a)->val >= pivot && ++rotated)
			stack_operation("RA", stack_a, stack_b);
		else if (++pushed)
			stack_operation("PB", stack_a, stack_b);
	}
	while (rotated-- && !(lst_size(*stack_a) + pushed == sort_len))
		stack_operation("RRA", stack_a, stack_b);
	quicksort_stack(stack_a, stack_b, sort_len - pushed);
	rev_quicksort_stack(stack_a, stack_b, pushed);
	while (pushed--)
		stack_operation("PA", stack_a, stack_b);
	return (stack_operation("finish", stack_a, stack_b));
}

int		short_sort(t_lst **stack_a, t_lst **stack_b, int sort_len)
{
	if (sort_len == 2 && !lst_is_nsorted(*stack_a, 2))
	{
		stack_operation("SA", stack_a, stack_b);
		return (0);
	}
	else if (sort_len == 3 && !lst_is_nsorted(*stack_a, sort_len))
	{
		sort_three(stack_a, stack_b);
		return (0);
	}
	return (1);
}

int		short_rev_sort(t_lst **stack_a, t_lst **stack_b, int sort_len)
{
	if (sort_len == 2 && !lst_is_nrev_sorted(*stack_b, sort_len))
	{
		stack_operation("SB", stack_a, stack_b);
		return (0);
	}
	if (sort_len == 3 && !lst_is_nrev_sorted(*stack_b, sort_len))
	{
		rev_sort_three(stack_a, stack_b);
		return (0);
	}
	return (1);
}

void	rev_quicksort_stack(t_lst **stack_a, t_lst **stack_b, int sort_len)
{
	int	pushed;
	int	rotated;
	int	pivot;

	pushed = 0;
	rotated = 0;
	pivot = get_n_pivot1(*stack_b, sort_len);
	short_rev_sort(stack_a, stack_b, sort_len);
	if (lst_is_nrev_sorted(*stack_b, sort_len))
		return ;
	while (lst_is_num_bigger_in_n(*stack_b, pivot - 1, sort_len - pushed\
	- rotated))
	{
		if ((*stack_b)->val < pivot && ++rotated)
			stack_operation("RB", stack_a, stack_b);
		else if (++pushed)
			stack_operation("PA", stack_a, stack_b);
	}
	quicksort_stack(stack_a, stack_b, pushed);
	while (rotated-- && !(lst_size(*stack_b) + pushed == sort_len))
		stack_operation("RRB", stack_a, stack_b);
	rev_quicksort_stack(stack_a, stack_b, sort_len - pushed);
	while (pushed--)
		stack_operation("PB", stack_a, stack_b);
	return ;
}
