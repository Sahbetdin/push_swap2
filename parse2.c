/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:04:58 by btrifle           #+#    #+#             */
/*   Updated: 2020/02/24 17:05:00 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	free_stacks_after_success(t_stacks *st, t_info *pc, int *srt, int *num)
{
	free(st->a);
	free(st->b);
	st->a = NULL;
	st->b = NULL;
	free(st);
	st = NULL;
	free(srt);
	srt = NULL;
	free(num);
	num = NULL;
	free(pc);
	pc = NULL;
}

void	free_stacks_after_checker(t_stacks *st, int *srt, int *num)
{
	free(st->a);
	free(st->b);
	st->a = NULL;
	st->b = NULL;
	free(st);
	st = NULL;
	free(srt);
	srt = NULL;
	free(num);
	num = NULL;
}

int		bad_input(int res, int *num)
{
	if (res == 0)
		write(1, "\033[1;31mMalloc error in 'a'\n\033[0m", 24);
	else if (res == -1)
		write(1, "\033[1;31mNo numerical input\n\033[0m", 31);
	else if (res == -2)
		write(1, "\033[1;31mInteger overflaw\n\033[0m", 28);
	else if (res == -3)
		write(1, "\033[1;31mDuplicates found\n\033[0m", 28);
	if (res == 0 || res == -1 || res == -2 || res == -3)
	{
		free(num);
		return (0);
	}
	return (1);
}

int		if_allocated_b(t_stacks *st)
{
	int res;

	res = set_st_b(st);
	if (res == 0)
	{
		write(1, "\033[1;31mMalloc error in 'b'\n\033[0m", 24);
		st->b = NULL;
		free(st->a);
		st->a = NULL;
		free(st);
		free(st);
		st = NULL;
		return (0);
	}
	return (1);
}
