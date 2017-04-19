/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_both.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 21:45:27 by mfrankev          #+#    #+#             */
/*   Updated: 2017/03/04 21:45:29 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_swap_both(t_lst **stack_a, t_lst **stack_b)
{
	lst_swap_first(*stack_a);
	lst_swap_first(*stack_b);
	return ;
}

void	lst_rotate_both(t_lst **stack_a, t_lst **stack_b)
{
	lst_rotate(stack_a);
	lst_rotate(stack_b);
	return ;
}

void	lst_rev_rotate_both(t_lst **stack_a, t_lst **stack_b)
{
	lst_rev_rotate(stack_a);
	lst_rev_rotate(stack_b);
	return ;
}
