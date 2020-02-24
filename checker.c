/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:05:41 by btrifle           #+#    #+#             */
/*   Updated: 2020/02/24 17:05:43 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	if_ok(int i)
{
	if (i == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	run_gnl(t_stacks *st)
{
	char	*s;
	int		res;

	while (get_next_line(0, &s) > 0)
	{
		res = action(st, s, 0);
		if (res != 1)
			write(1, "BAD INPUT\n", 10);
		free(s);
	}
	free(s);
}

int		main(int ac, char **av)
{
	t_stacks	*st;
	int			*sorted;
	int			res;
	int			*num;

	if (!(num = (int *)malloc(sizeof(int) * 8)))
		return (0);
	st = NULL;
	if (ac == 1)
		return (0);
	res = set_st_a(ac, av, &st, &sorted);
	if (bad_input(res, num) == 0)
		return (0);
	if (if_allocated_b(st) == 0)
	{
		free(sorted);
		return (0);
	}
	run_gnl(st);
	if_ok(check_stacks(st));
	free_stacks_after_checker(st, sorted, num);
	return (0);
}
