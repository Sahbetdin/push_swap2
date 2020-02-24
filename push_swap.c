/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:59:03 by btrifle           #+#    #+#             */
/*   Updated: 2020/02/24 16:59:05 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"


// int check_initial(int ac, char **av, t_stacks *st, int *sorted)
// {
// 	return (0);
// }


int	main(int ac, char **av)
{
	int			res;
	t_stacks	*st;
	int			*sorted;
	t_info		*pc;
	int			n;
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
	n = 200;
	if (!(pc = (t_info *)malloc(sizeof(t_info) * 200)))
		return (0);
	set_first_info(pc + 1, st->n);
	while (check_stacks(st) == 0)
		process_stacks(st, pc, sorted, num);
	free_stacks_after_success(st, pc, sorted, num);
	return (0);
}
