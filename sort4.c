/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:52:30 by btrifle           #+#    #+#             */
/*   Updated: 2020/02/12 16:52:32 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	sort_4_a(t_stacks *st, t_info *pc0, int *srt)
{
	int flag;

	flag = 0;
	if (st->a[st->pa + 1] == srt[pc0->begin])
		action(st, "sa", 1);
	if (st->a[st->pa] == srt[pc0->begin])
	{
		action(st, "ra", 1);
		flag = 10;
	}
	else if (st->a[st->pa + 2] == srt[pc0->begin])
		sort_4_st_pa_2(st, pc0, srt);
	else if (st->a[st->pa + 3] == srt[pc0->begin])
		sort_4_st_pa_3(st, pc0, srt, &flag);
	if (flag == 10)
	{
		change_piece_beg_am(pc0, 1);
		sort_3_elements(st, pc0, srt);
	}
	else if (flag == 20)
	{
		change_piece_beg_am(pc0, 2);
		sort_2_elements(st, pc0);
	}
}

void	sort_4_elements(t_stacks *st, t_info *pc0, int *srt)
{
	int k;

	k = 0;
	if (pc0->lt == 'A' && pc0->amount + st->pa == st->n)
		sort_4_only(st, pc0, srt);
	else if (pc0->lt == 'A')
		sort_4_a(st, pc0, srt);
	else if (pc0->lt == 'B')
	{
		if (st->b[st->pb + 2] == srt[pc0->begin])
			action(st, "sb", 1);
		if (st->b[st->pb + 1] == srt[pc0->begin])
		{
			pa_ra(st);
			change_piece_beg_am(pc0, 1);
			sort_3_elements(st, pc0, srt);
		}
		else if (st->b[st->pb + 3] == srt[pc0->begin])
			sort_4_st_pb_3(st, pc0, srt);
		else if (st->b[st->pb + 4] == srt[pc0->begin])
			sort_4_st_pb_4(st, pc0, srt);
	}
	zerofy_piece(pc0);
}
