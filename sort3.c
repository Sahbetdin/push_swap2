/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:52:23 by btrifle           #+#    #+#             */
/*   Updated: 2020/02/12 16:52:25 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	sort_top_top(t_stacks *st)
{
	if (st->a[st->pa] < st->b[st->pb + 1])
	{
		action(st, "ra", 1);
		pa_ra(st);
	}
	else if (st->a[st->pa] > st->b[st->pb + 1])
	{
		action(st, "pa", 1);
		ra_2(st);
	}
}

void	sort_3_a_alone(t_stacks *st, t_info *pc0, int *srt)
{
	if (st->a[st->pa] < st->a[st->pa + 2] && st->a[st->pa + 2] <
	st->a[st->pa + 1])
	{
		action(st, "rra", 1);
		action(st, "sa", 1);
	}
	else if (st->a[st->pa + 1] == srt[pc0->begin])
	{
		if (st->a[st->pa] < st->a[st->pa + 2])
			action(st, "sa", 1);
		else if (st->a[st->pa] > st->a[st->pa + 2])
			action(st, "ra", 1);
	}
	else if (st->a[st->pa + 2] == srt[pc0->begin])
	{
		if (st->a[st->pa] < st->a[st->pa + 1])
			action(st, "rra", 1);
		else if (st->a[st->pa] > st->a[st->pa + 1])
			sa_rra(st);
	}
}

void	sort_3_a_not_alone(t_stacks *st, t_info *pc0, int *srt)
{
	if (st->a[st->pa] == srt[pc0->begin])
	{
		action(st, "ra", 1);
		sort_2_elements(st, pc0);
	}
	else if (st->a[st->pa + 1] == srt[pc0->begin])
	{
		sa_ra(st);
		sort_2_elements(st, pc0);
	}
	else if (st->a[st->pa + 2] == srt[pc0->begin])
	{
		action(st, "pb", 1);
		sa_ra(st);
		sort_top_top(st);
	}
}

void	sort_3_b(t_stacks *st, t_info *pc0, int *srt)
{
	if (st->b[st->pb + 1] == srt[pc0->begin])
	{
		pa_ra(st);
		action(st, "pa", 1);
		sort_top_top(st);
	}
	else if (st->b[st->pb + 2] == srt[pc0->begin])
	{
		pa_2(st);
		action(st, "ra", 1);
		sort_top_top(st);
	}
	else if (st->b[st->pb + 3] == srt[pc0->begin])
	{
		pa_2(st);
		pa_ra(st);
		pc0->lt = 'A';
		pc0->begin++;
		pc0->amount--;
		sort_2_elements(st, pc0);
	}
}

void	sort_3_elements(t_stacks *st, t_info *pc0, int *srt)
{
	if (pc0->lt == 'A' && pc0->amount + st->pa == st->n)
		sort_3_a_alone(st, pc0, srt);
	else if (pc0->lt == 'A')
		sort_3_a_not_alone(st, pc0, srt);
	else if (pc0->lt == 'B')
		sort_3_b(st, pc0, srt);
	zerofy_piece(pc0);
}
