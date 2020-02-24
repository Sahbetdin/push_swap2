/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:51:36 by btrifle           #+#    #+#             */
/*   Updated: 2020/02/21 14:51:38 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

int		active_piece(t_info *pc)
{
	int i;

	i = 1;
	while (i < 200)
	{
		if (pc[i].amount != 0 && pc[i + 1].amount == 0)
			break ;
		i++;
	}
	return (i);
}

void	process_more_than_4_a(t_stacks *st, t_info *pc_i, int *sorted, int *num)
{
	if (is_pb(st, pc_i, sorted, num[5]))
	{
		action(st, "pb", 1);
		num[6] = st->b[st->pb + 1];
		num[6] = num[5] && !(num[6] >= sorted[(pc_i + 2)->begin] &&
			num[6] < sorted[(pc_i + 2)->end]) && st->pb < st->n - 2;
		if (num[6] && !is_pb(st, pc_i, sorted, num[5]))
		{
			action(st, "rr", 1);
			num[2]++;
		}
		else if (num[6])
			action(st, "rb", 1);
		num[7]++;
	}
	else
	{
		action(st, "ra", 1);
		num[2]++;
	}
}

void	process_cycle(t_stacks *st, t_info *pc_i, int *sorted, int *num)
{
	num[2] = 0;
	num[0] = 0;
	while (num[0] < num[1] && num[7] < num[3])
	{
		if (pc_i->lt == 'A')
			process_more_than_4_a(st, pc_i, sorted, num);
		else if (pc_i->lt == 'B')
		{
			if (st->b[st->pb + 1] >= sorted[(pc_i + 2)->begin] &&
				st->b[st->pb + 1] < sorted[(pc_i + 1)->end])
			{
				num[7]++;
				action(st, "pa", 1);
			}
			else
			{
				action(st, "rb", 1);
				num[2]++;
			}
		}
		num[0]++;
	}
}

/*
** here pc_i_1 is pc_i + 1
*/

void	check_if_b_empty(t_info *pc_i_1, int *num)
{
	if (pc_i_1->amount > 3 && num[5])
	{
		divide_piece_info(pc_i_1, 0);
		num[3] = pc_i_1->amount + (pc_i_1 + 1)->amount;
	}
	else
		num[3] = pc_i_1->amount;
}

/*
** num[0] = j; num[1] = count; num[2] = rot_cnt; num[3] = need_to_push;
** num[4] = flag; num[5] = flag1; num[6] = tmp; num[7] = k;
*/

void	process_stacks(t_stacks *st, t_info *pc, int *sorted, int *num)
{
	int i;

	i = -1;
	while (++i < 8)
		num[i] = 0;
	i = active_piece(pc);
	if (pc[i].amount > 4)
	{
		num[1] = pc[i].amount;
		num[4] = 1;
		if ((pc[i].lt == 'A' && st->pa + pc[i].amount == st->n) ||
		(pc[i].lt == 'B' && st->pb + pc[i].amount + 1 == st->n))
			num[4] = 0;
		check_first_element(st, pc + i, sorted);
		if (st->pb + 1 == st->n)
			num[5] = 1;
		else
			num[5] = 0;
		divide_piece_info(pc + i, 1);
		check_if_b_empty(pc + i + 1, num);
		process_cycle(st, pc + i, sorted, num);
		rotate_back_stacks(st, pc + i, num[2], num[4]);
	}
	else
		sort_234(st, pc + i, sorted);
}
