/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 21:44:04 by mfrankev          #+#    #+#             */
/*   Updated: 2017/03/04 21:44:09 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimize(t_lst **commands)
{
	int		n;

	while (42)
	{
		n = lst_size(*commands);
		remove_rr_r(commands);
		double_opers(commands);
		if (n - lst_size(*commands) == 0)
			break ;
	}
}

void	double_opers(t_lst **commands)
{
	t_lst	*crawler;
	t_lst	*tmp;
	int		value;

	crawler = (*commands);
	while (crawler->next != *commands)
	{
		if (((crawler->val == RRA && crawler->next->val == RRB) || \
		(crawler->val == RA && crawler->next->val == RB)) || \
		((crawler->val == RRB && crawler->next->val == RRA) || \
		(crawler->val == RB && crawler->next->val == RA)) || \
		(crawler->val == SA && crawler->next->val == SB) || \
		(crawler->val == SB && crawler->next->val == SA))
		{
			tmp = crawler->next;
			value = crawler->val + crawler->next->val;
			crawler->next = crawler->next->next;
			crawler->next->prev = crawler;
			lst_del_elem(&tmp);
			crawler->val = value;
			if (crawler == *commands)
				crawler = crawler->next;
		}
		crawler = crawler->next;
	}
}

void	remove_rr_r(t_lst **commands)
{
	t_lst	*crawler;
	t_lst	*tmp1;
	t_lst	*tmp2;

	crawler = (*commands)->next;
	while (crawler->next != *commands)
	{
		if (((crawler->val == RRA && crawler->next->val == RA) || \
		(crawler->val == RA && crawler->next->val == RRA)) || \
		((crawler->val == RRB && crawler->next->val == RB) || \
		(crawler->val == RB && crawler->next->val == RRB)) || \
		(crawler->val == PA && crawler->next->val == PB) || \
		(crawler->val == PB && crawler->next->val == PA))
		{
			tmp1 = crawler;
			tmp2 = crawler->next;
			crawler = crawler->prev;
			crawler->next = crawler->next->next->next;
			crawler->next->prev = crawler;
			lst_del_elem(&tmp1);
			lst_del_elem(&tmp2);
		}
		crawler = crawler->next;
	}
}
