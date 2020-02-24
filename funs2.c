/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:53:00 by btrifle           #+#    #+#             */
/*   Updated: 2020/02/12 16:53:01 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	set_first_info(t_info *pc, int n)
{
	pc->begin = 0;
	pc->end = n;
	pc->amount = pc->end - pc->begin;
	pc->lt = 'A';
}

void	divide_piece_info(t_info *pc, int flag)
{
	int		mid;
	t_info	*old;

	old = pc;
	pc++;
	mid = (old->begin + old->end) / 2;
	if (flag == 1 && old->lt == 'A')
		pc->lt = 'B';
	else if (flag == 1 && old->lt == 'B')
		pc->lt = 'A';
	else if (flag == 0 && old->lt == 'A')
		pc->lt = 'A';
	else if (flag == 0 && old->lt == 'B')
		pc->lt = 'B';
	pc->begin = old->begin;
	pc->end = mid;
	pc->amount = pc->end - pc->begin;
	old->begin = mid;
	old->amount = old->end - old->begin;
}

void	free_stacks(t_stacks *st)
{
	free(st->a);
	free(st->b);
	free(st);
}

/*
** if pa is 0 and st->a is sorted, then return 1
** else return 0
*/

int		check_stacks(t_stacks *st)
{
	int i;

	if (st->pa != 0)
		return (0);
	i = 0;
	while (i < st->n - 1)
	{
		if (st->a[i] > st->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

/*
** begin increases by delta
** amount decreases by delta
*/

void	change_piece_beg_am(t_info *pc0, int delta)
{
	pc0->begin += delta;
	pc0->amount -= delta;
}
