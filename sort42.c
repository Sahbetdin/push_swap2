/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort42.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:46:01 by btrifle           #+#    #+#             */
/*   Updated: 2020/02/24 14:46:03 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	sort_1_1(t_stacks *st, t_info *pc0, int *srt)
{
	if (st->a[st->pa] == srt[pc0->begin + 2])
	{
		action(st, "ra", 1);
		action(st, "pa", 1);
		action(st, "ra", 1);
	}
	else if (st->b[st->pb + 1] == srt[pc0->begin + 2])
	{
		action(st, "pa", 1);
		ra_2(st);
	}
}

void	sort_4_st_pb_4(t_stacks *st, t_info *pc0, int *srt)
{
	pa_2(st);
	pa_2(st);
	action(st, "ra", 1);
	pc0->lt = 'A';
	change_piece_beg_am(pc0, 1);
	sort_3_elements(st, pc0, srt);
}

void	sort_4_st_pa_2(t_stacks *st, t_info *pc0, int *srt)
{
	action(st, "pb", 1);
	sa_ra(st);
	if (st->a[st->pa + 1] == srt[pc0->begin + 1])
		action(st, "sa", 1);
	if (st->a[st->pa] == srt[pc0->begin + 1])
	{
		action(st, "ra", 1);
		sort_1_1(st, pc0, srt);
	}
	else if (st->b[st->pb + 1] == srt[pc0->begin + 1])
	{
		pa_ra(st);
		print_piece(*pc0);
		change_piece_beg_am(pc0, 2);
		sort_2_elements(st, pc0);
	}
}

void	sort_4_st_pa_3(t_stacks *st, t_info *pc0, int *srt, int *addr_flag)
{
	pb_2(st);
	sa_ra(st);
	if (st->a[st->pa] == srt[pc0->begin + 1])
	{
		action(st, "ra", 1);
		pc0->lt = 'B';
		*addr_flag = 20;
	}
	else if (st->b[st->pb + 1] == srt[pc0->begin + 1])
	{
		pa_ra(st);
		sort_1_1(st, pc0, srt);
	}
	else if (st->b[st->pb + 2] == srt[pc0->begin + 1])
	{
		action(st, "sb", 1);
		pa_ra(st);
		sort_1_1(st, pc0, srt);
	}
}

void	sort_4_st_pb_3(t_stacks *st, t_info *pc0, int *srt)
{
	pa_2(st);
	pa_ra(st);
	if (st->a[st->pa + 1] == srt[pc0->begin + 1])
		action(st, "sa", 1);
	if (st->a[st->pa] == srt[pc0->begin + 1])
	{
		action(st, "ra", 1);
		sort_top_top(st);
	}
	else if (st->b[st->pb + 1] == srt[pc0->begin + 1])
	{
		pa_ra(st);
		pc0->lt = 'A';
		change_piece_beg_am(pc0, 2);
		sort_2_elements(st, pc0);
	}
}
