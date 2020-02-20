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


void	ra_2(t_stacks *st)
{
	action(st, "ra");
	action(st, "ra");
}



void	ra_sa(t_stacks *st)
{
	action(st, "ra");
	action(st, "sa");
}

void	sa_ra(t_stacks *st)
{
	action(st, "sa");
	action(st, "ra");
}

void	ra_pb(t_stacks *st)
{
	action(st, "ra");
	action(st, "pb");
}

void	pa_ra(t_stacks *st)
{
	action(st, "pa");
	action(st, "ra");
}

void	ra_pa(t_stacks *st)
{
	action(st, "ra");
	action(st, "pa");
}

void	pa_2(t_stacks *st)
{
	action(st, "pa");
	action(st, "pa");
}

void	pb_2_ss(t_stacks *st)
{
	action(st, "pb");
	action(st, "pb");
	action(st, "ss");
}

void	pb_ra(t_stacks *st)
{
	action(st, "pb");
	action(st, "ra");
}

void	pb_sa(t_stacks *st)
{
	action(st, "pb");
	action(st, "sa");
}

void	pb_2(t_stacks *st)
{
	action(st, "pb");
	action(st, "pb");
}

void	pa_sb(t_stacks *st)
{
	action(st, "pa");
	action(st, "sb");
}

void	pa_2_ss(t_stacks *st)
{
	action(st, "pa");
	action(st, "pa");
	action(st, "ss");
}

void	sort_1_1(t_stacks *st, t_info *pc0, int *srt)
{
	if (st->a[st->pa] == srt[pc0->begin + 2])
	{
		// printf("LEGO\n");
		action(st, "ra");
		action(st, "pa");
		action(st, "ra");
	}
	else if (st->b[st->pb + 1] == srt[pc0->begin + 2])
	{
	// printf("HJKO\n");
		action(st, "pa");
		action(st, "ra");
		action(st, "ra");
	}
}


void	sort_4_elements(t_stacks *st, t_info *pc0, int *srt)
{
	int k;
	int flag;

//переделать . чтобы обрабатывался пустой стэк, в который переношу (обычно А!)





////
	k = 0;
	// printf("IN SORTING 4 ELEMENTS: lt = %c\n", pc0->lt);
	if (pc0->lt == 'A')
	{
		// printf("%d\n", st->a[st->pa]);
		// printf("%d\n", st->a[st->pa + 1]);
		// printf("%d\n", st->a[st->pa + 2]);
		// printf("%d\n", st->a[st->pa + 3]);
		// printf("pc: begin = %d, end = %d\n", srt[pc0->begin], srt[pc0->end - 1]);
	// print_piece(pc0[0]);
	// print_piece(pc[1]);
	// print_piece(pc[2]);
		flag = 0;
		if (st->a[st->pa + 1] == srt[pc0->begin])
			action(st, "sa");
		if (st->a[st->pa] == srt[pc0->begin] && pc0->amount + st->pa != st->n)
		{
			action(st, "ra");
			flag = 10;
		}
		else if (st->a[st->pa + 2] == srt[pc0->begin])
		{
			// printf("AHO \n");
			action(st, "pb");
			action(st, "sa");
			action(st, "ra");
			// printf("NOW HERE: st->a[st->pa] = %d\n", st->a[st->pa]);
			// printf("NOW HERE: st->a[st->pa + 1] = %d\n", st->a[st->pa + 1]);
			// printf("NOW HERE: st->b[st->pb + 1] = %d\n", st->b[st->pb + 1]);
			if (st->a[st->pa + 1] == srt[pc0->begin + 1])
				action(st, "sa");
			if (st->a[st->pa] == srt[pc0->begin + 1])
			{
				action(st, "ra");
				sort_1_1(st, pc0, srt);
			}
			else if (st->b[st->pb + 1] == srt[pc0->begin + 1])
			{
			// printf("OEKL \n");
				action(st, "pa");
				action(st, "ra");
				action(st, "ra");
				action(st, "ra");
			}
		}
		else if (st->a[st->pa + 3] == srt[pc0->begin])
		{ // * * * 1
			// printf("CULT \n");
			// print_arrays(st);
			action(st, "pb");
			action(st, "pb");
			action(st, "sa");
			action(st, "ra");
			// print_arrays(st);

			if (st->a[st->pa] == srt[pc0->begin + 1])
			{ //  2 | 1  * *  --> | 1 2   * * (take two elem from B)
			// printf("STD\n");
				action(st, "ra");
				pc0->lt = 'B';
				flag = 20;
			}
			else if (st->b[st->pb + 1] == srt[pc0->begin + 1])
			{ //  * | 1    2 *  -->  * | 1 2    * *
				// printf("GLA\n");
				action(st, "pa");
				action(st, "ra");
				sort_1_1(st, pc0, srt);
			}
			else if (st->b[st->pb + 2] == srt[pc0->begin + 1])
			{ //  * | 1     * 2 -->  * | 1 2  *  *
				// printf("DAS\n");
				action(st, "sb");
				action(st, "pa");
				action(st, "ra");
				sort_1_1(st, pc0, srt);
			}
		}



		if (flag == 10)
		{
			pc0->begin++;
			pc0->amount--;
			sort_3_elements(st, pc0, srt);
		}
		else if (flag == 20)
		{
			pc0->begin += 2;
			pc0->amount -= 2;
			sort_2_elements(st, pc0);
		}
	}
	else if (pc0->lt == 'B')
	{		
		// printf("%d\n", st->b[st->pb + 1]);
		// printf("%d\n", st->b[st->pb + 2]);
		// printf("%d\n", st->b[st->pb + 3]);
		// printf("%d\n", st->b[st->pb + 4]);

		if (st->b[st->pb + 1] < st->b[st->pb + 2] &&
		st->b[st->pb + 2] < st->b[st->pb + 3] &&
		st->b[st->pb + 3] < st->b[st->pb + 4]) // 1 2 3 4 in B
		{ // проверил
			// printf("WORK IN B\n");
			pa_ra(st);
			pa_ra(st);
			pa_ra(st);
			pa_ra(st);
		}
		else if (st->b[st->pb + 1] < st->b[st->pb + 2] &&
		st->b[st->pb + 2] < st->b[st->pb + 4] &&
		st->b[st->pb + 4] < st->b[st->pb + 3]) // 1 2 4 3
		{ // проверил
		//	printf("WORK IN Gre\n");
			pa_ra(st);
			pa_ra(st);
			pa_2(st);
			ra_2(st);
		}
		else if (st->b[st->pb + 1] < st->b[st->pb + 3] &&
		st->b[st->pb + 3] < st->b[st->pb + 2] &&
		st->b[st->pb + 2] < st->b[st->pb + 4]) // 1 3 2 4
		{ // проверил
//			printf("THIS MAKES\n");
			pa_ra(st);
			pa_2(st);
			ra_2(st);
			pa_ra(st);
		}
		else if (st->b[st->pb + 1] < st->b[st->pb + 3] &&
		st->b[st->pb + 3] < st->b[st->pb + 4] &&
		st->b[st->pb + 4] < st->b[st->pb + 2]) // 1 3 4 2
		{ //поправил, проверил
			// printf("IN B YES\n");
			// pa_ra(st);
			// pa_2(st);
			// ra_pa(st);
			// ra_2(st);

			pa_ra(st);
			pa_sb(st);
			pa_ra(st);
			action(st, "ra");
			pa_ra(st);
		}
		else if (st->b[st->pb + 1] < st->b[st->pb + 4] &&
		st->b[st->pb + 4] < st->b[st->pb + 2] &&
		st->b[st->pb + 2] < st->b[st->pb + 3]) // [1] < [4] < [2] < [3]
		{//поправил, проверил
//			printf("HGOED\n");
			pa_ra(st);
			pa_sb(st);
			pa_ra(st);
			ra_pa(st);
			action(st, "ra");
			// pa_ra(st);
			// pa_2(st);
			// ra_pa(st);
			// ra_2(st);
		}
		else if (st->b[st->pb + 1] < st->b[st->pb + 4] &&
		st->b[st->pb + 4] <	st->b[st->pb + 3] &&
		st->b[st->pb + 3] < st->b[st->pb + 2]) // 1 4 3 2
		{ //было верно
			//printf("VLAFD\n");
			pa_ra(st);
			pa_2(st);
			pa_ra(st);
			ra_2(st);
		}
		else if (st->b[st->pb + 2] < st->b[st->pb + 1] &&
		st->b[st->pb + 1] < st->b[st->pb + 3] &&
		st->b[st->pb + 3] < st->b[st->pb + 4]) // 2 1 3 4
		{//было верно
			//printf("JOKE\n");
			pa_2(st);
			ra_2(st);
			pa_ra(st);
			pa_ra(st);
		}
		else if (st->b[st->pb + 2] < st->b[st->pb + 1] &&
		st->b[st->pb + 1] < st->b[st->pb + 4] &&
		st->b[st->pb + 4] < st->b[st->pb + 3]) // 2 1 4 3
		{ //было верно
			// printf("HORR\n");
			pa_2(st);
			ra_2(st);
			pa_2(st);
			ra_2(st);
		}
		else if (st->b[st->pb + 2] < st->b[st->pb + 3] &&
			st->b[st->pb + 3] < st->b[st->pb + 1] && 
			st->b[st->pb + 1] < st->b[st->pb + 4]) // 2 3 1 4
		{ //поправил
			// printf("GSDA\n");
			pa_2(st);
			ra_pa(st);
			ra_2(st);
			pa_ra(st);
		}
		else if (st->b[st->pb + 2] < st->b[st->pb + 3] &&
		st->b[st->pb + 3] < st->b[st->pb + 4] &&
		st->b[st->pb + 4] < st->b[st->pb + 1]) // 2 3 4 1
		{//поправил
			// printf("UREIN\n");
			pa_2(st);
			ra_pa(st);
			ra_pa(st);
			ra_2(st);
		}
		else if (st->b[st->pb + 2] < st->b[st->pb + 4] && 
			st->b[st->pb + 4] < st->b[st->pb + 1] &&
			st->b[st->pb + 1] < st->b[st->pb + 3]) // 2 4 1 3
		{ //поправил
			// printf("LORD\n");
			pa_2(st);
			action(st, "ra");
			action(st, "sb");
			pa_ra(st);
			ra_pa(st);
			action(st, "ra");
		}
		else if (st->b[st->pb + 2] < st->b[st->pb + 4] &&
			st->b[st->pb + 4] < st->b[st->pb + 3] &&
			st->b[st->pb + 3] < st->b[st->pb + 1]) // 2 4 3 1
		{ //поправил
			// printf("FRESD\n");
			pa_2(st);
			ra_pa(st);
			pa_ra(st);
			ra_2(st);
		}
		else if (st->b[st->pb + 3] < st->b[st->pb + 1] && 
			st->b[st->pb + 1] < st->b[st->pb + 2] && 
			st->b[st->pb + 2] < st->b[st->pb + 4]) // 3 1 2 4
		{ //corrected
			// printf("JKLEA\n");
			pa_2(st);
			pa_ra(st);
			action(st, "sa");
			ra_2(st);
			pa_ra(st);
		}
		else if (st->b[st->pb + 3] < st->b[st->pb + 1] &&
		st->b[st->pb + 1] < st->b[st->pb + 4] &&
		st->b[st->pb + 4] < st->b[st->pb + 2]) // 3 1 4 2
		{ //corrected
			// printf("LOEFA\n");
			pa_2(st);
			pa_ra(st);
			action(st, "sa");
			ra_pa(st);
			ra_2(st);
		}
		else if (st->b[st->pb + 3] < st->b[st->pb + 2] &&
			st->b[st->pb + 2] < st->b[st->pb + 1] && 
			st->b[st->pb + 1] < st->b[st->pb + 4]) // 3 2 1 4
		{//corrected
			// printf("TOWEL\n");
			pa_2(st);
			pa_ra(st);
			ra_2(st);
			pa_ra(st);
		}
		else if (st->b[st->pb + 3] < st->b[st->pb + 2] && 
			st->b[st->pb + 2] < st->b[st->pb + 4] && 
			st->b[st->pb + 4] < st->b[st->pb + 1]) // 3 2 4 1
		{ //corrected
			// printf("KLOWN\n");
			pa_2(st);
			pa_ra(st);
			ra_pa(st);
			ra_2(st);
		}
		else if (st->b[st->pb + 3] < st->b[st->pb + 4] &&
			st->b[st->pb + 4] < st->b[st->pb + 1] && 
			st->b[st->pb + 1] < st->b[st->pb + 2]) // 3 4 1 2
		{ //было верно
			// printf("SHOW\n");
			pa_2(st);
			pa_ra(st);
			pa_ra(st);
			action(st, "sa");
			ra_2(st);
		}
		else if (st->b[st->pb + 3] < st->b[st->pb + 4] && 
			st->b[st->pb + 4] < st->b[st->pb + 2] && 
			st->b[st->pb + 2] < st->b[st->pb + 1]) // 3 4 2 1
		{//was correct
			// printf("FREE\n");
			pa_2(st);
			pa_ra(st);
			pa_ra(st);
			ra_2(st);
		}
		else if (st->b[st->pb + 4] < st->b[st->pb + 1] &&
			st->b[st->pb + 1] < st->b[st->pb + 2] && 
			st->b[st->pb + 2] < st->b[st->pb + 3]) // 4 1 2 3
		{ // corrected
			// printf("HOKL\n");
			pa_2(st);
			action(st, "ss");
			pa_ra(st);
			ra_2(st);
			pa_ra(st);
		}
		else if (st->b[st->pb + 4] < st->b[st->pb + 1] && 
			st->b[st->pb + 1] < st->b[st->pb + 3] && 
			st->b[st->pb + 3] < st->b[st->pb + 2]) // 4 1 3 2
		{//corrected
			// printf("LOPS\n");
			pa_2(st);
			action(st, "ss");
			pa_ra(st);			
			ra_pa(st);
			ra_2(st);
		}
		else if (st->b[st->pb + 4] < st->b[st->pb + 2] &&
		st->b[st->pb + 2] < st->b[st->pb + 1] && 
		st->b[st->pb + 1] < st->b[st->pb + 3]) // 4 2 1 3
		{ //corrected
			printf("OPS\n");
			pa_2(st);
			action(st, "sb");
			pa_ra(st);
			ra_2(st);
			pa_ra(st);			
		}
		else if (st->b[st->pb + 4] < st->b[st->pb + 2] && 
			st->b[st->pb + 2] < st->b[st->pb + 3] && 
			st->b[st->pb + 3] < st->b[st->pb + 1]) // 4 2 3 1
		{//corrected
			// printf("OANM\n");
			pa_2(st);
			pa_2(st);
			ra_sa(st);
			ra_2(st);
			action(st, "ra");
		}
		else if (st->b[st->pb + 4] < st->b[st->pb + 3] &&
		st->b[st->pb + 3] < st->b[st->pb + 1] && 
		st->b[st->pb + 1] < st->b[st->pb + 2]) // 4 3 1 2
		{ //corrected
			// printf("LPAS\n");
			pa_2(st);
			action(st, "ss");
			pa_ra(st);
			pa_ra(st);
			ra_2(st);
		}
		else if (st->b[st->pb + 4] < st->b[st->pb + 3] && 
			st->b[st->pb + 3] < st->b[st->pb + 2] && 
			st->b[st->pb + 2] < st->b[st->pb + 1]) // 4 3 2 1
		{ //was correct
			// printf("LGJA\n");
			pa_2(st);
			pa_2(st);
			ra_2(st);
			ra_2(st);
		}
	}
	pc0->lt = 0;
	pc0->begin = 0;
	pc0->end = 0;
	pc0->amount = 0;
}
