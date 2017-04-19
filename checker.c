/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 21:43:28 by mfrankev          #+#    #+#             */
/*   Updated: 2017/03/05 15:32:11 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int argc, char **argv)
{
	t_lst	*stack_a;
	t_flags	*flags;
	int		n;

	flags = parsing_flags(&argc, &argv);
	if (!(pushing_numbers(argc, argv, &stack_a)) || argc == 0)
	{
		if (argc > 1)
			ft_putstr(RED"Error\n"RESET);
		return (1);
	}
	if (flags->v && flags->c)
		print_stacks_color(stack_a, NULL);
	else if (flags->v)
		print_stacks(stack_a, NULL);
	n = do_sorting(&argc, argv, &stack_a, flags);
	if (argc >= 0)
		ft_putstr(n >= 0 ? GRN"    OK\n"RESET : RED"     KO\n"RESET);
	if (flags->n && n != MIN_INT && flags->c)
		ft_printf(BLU"Number of operations = %d\n"RESET, ABS(n));
	else if (flags->n && n != MIN_INT)
		ft_printf("Number of operations = %d\n", ABS(n));
	del_list(&stack_a);
	free(flags);
	return (0);
}

int			do_oper(char *oper, t_lst **stack_a, t_lst **stack_b)
{
	if (ft_strstr(oper, "rrr"))
		lst_rev_rotate_both(stack_a, stack_b);
	else if (ft_strstr(oper, "rr") && ft_strlen(oper) != 2)
		lst_rev_rotate(oper[2] == 'a' ? stack_a : stack_b);
	else if (ft_strstr(oper, "rr"))
		lst_rotate_both(stack_a, stack_b);
	else if (ft_strstr(oper, "r"))
		lst_rotate(oper[1] == 'a' ? stack_a : stack_b);
	else if (ft_strstr(oper, "ss"))
		lst_swap_both(stack_a, stack_b);
	else if (ft_strstr(oper, "s"))
		lst_swap_first(oper[1] == 'a' ? *stack_a : *stack_b);
	else if (ft_strstr(oper, "pa"))
		lst_push_from_stack(stack_b, stack_a);
	else if (ft_strstr(oper, "pb"))
		lst_push_from_stack(stack_a, stack_b);
	else
		return (0);
	return (1);
}

int			do_sorting(int *argc, char **argv, t_lst **stack_a, t_flags *flags)
{
	t_lst	*stack_b;
	char	*line;
	int		n;

	n = 0;
	stack_b = NULL;
	while (get_next_line(flags->fd_input, &line))
	{
		if (VALID_C && ft_strlen(line) >= 2)
			do_oper(line, stack_a, &stack_b);
		else
		{
			ft_putstr(RED"Error\n"RESET);
			*argc = -1;
			return (-1);
		}
		if (flags->v && flags->c)
			print_stacks_color(*stack_a, stack_b);
		else if (flags->v)
			print_stacks(*stack_a, stack_b);
		free(line);
		n++;
	}
	del_list(&stack_b);
	return ((lst_is_sorted(*stack_a) && stack_b == NULL ? n : -n));
}

t_flags		*parsing_flags(int *argc, char ***argv)
{
	t_flags	*flags;
	int		i;

	i = 1;
	flags = (t_flags*)malloc(sizeof(t_flags));
	ft_bzero(flags, sizeof(*flags));
	skip_argc_argv(argc, argv, 1);
	if (*argc == 0)
		return (flags);
	if ((*argv)[0][0] == '-')
	{
		while ((*argv)[0][i])
		{
			if ((*argv)[0][i] == 'c')
				flags->c = 1;
			else if ((*argv)[0][i] == 'v')
				flags->v = 1;
			else if ((*argv)[0][i] == 'n')
				flags->n = 1;
			i++;
		}
		skip_argc_argv(argc, argv, 1);
	}
	return (flags);
}
