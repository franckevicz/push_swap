/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_5.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 21:45:35 by mfrankev          #+#    #+#             */
/*   Updated: 2017/03/05 14:54:00 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*stack_operation(char *oper, t_lst **stack_a, t_lst **stack_b)
{
	static t_lst	*commands = NULL;

	if (ft_strstr(oper, "RRR"))
		lst_rotate_both(stack_a, stack_b);
	else if (ft_strstr(oper, "RR") && ft_strlen(oper) != 2)
		lst_rev_rotate(oper[2] == 'A' ? stack_a : stack_b);
	else if (ft_strstr(oper, "RR"))
		lst_rotate_both(stack_a, stack_b);
	else if (ft_strstr(oper, "R"))
		lst_rotate(oper[1] == 'A' ? stack_a : stack_b);
	else if (ft_strstr(oper, "SS"))
		lst_swap_both(stack_a, stack_b);
	else if (ft_strstr(oper, "S"))
		lst_swap_first(oper[1] == 'A' ? *stack_a : *stack_b);
	else if (ft_strstr(oper, "PA"))
		lst_push_from_stack(stack_b, stack_a);
	else if (ft_strstr(oper, "PB"))
		lst_push_from_stack(stack_a, stack_b);
	else if (ft_strstr(oper, "finish"))
		return (commands);
	push_operation(oper, &commands);
	return (NULL);
}

void	skip_argc_argv(int *argc, char ***argv, int times)
{
	*argc -= times;
	*argv += times;
	return ;
}

void	print_stacks_color(t_lst *stack_a, t_lst *stack_b)
{
	print_arrays_color(lst_to_array(stack_a), lst_size(stack_a), \
	lst_to_array(stack_b), lst_size(stack_b));
}

void	print_arrays_color(int *stack_a, int size_a, int *stack_b, int size_b)
{
	int i;
	int j;

	i = 0;
	j = 0;
	ft_putstr(CYN"  STACK_A      |       STACK_B  \n\n"RESET);
	while (i < size_a || j < size_b)
	{
		if (i < size_a)
			ft_printf(YEL"%8d"RESET, stack_a[i]);
		else
			ft_putstr("        ");
		ft_putstr("             ");
		if (j < size_b)
			ft_printf(MAG"%8d\n"RESET, stack_b[j]);
		else
			ft_putstr("         \n");
		i++;
		j++;
	}
	ft_putstr("\n\n");
	free(stack_a);
	free(stack_b);
	return ;
}
