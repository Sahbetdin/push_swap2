/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 21:19:48 by btrifle           #+#    #+#             */
/*   Updated: 2020/02/24 21:19:49 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	print_piece(t_info piece0)
{
	ft_printf("begin =  %d, ", piece0.begin);
	ft_printf("end =    %d, ", piece0.end);
	ft_printf("amount = %d, ", piece0.amount);
	ft_printf("letter = %c\n", piece0.lt);
	ft_printf("~~~~~~~~~~~~~\n");
}

void	print_arrays(t_stacks *st)
{
	int i;

	ft_printf("\033[0;36m a:       \033[0m");
	ft_printf("%3d,", st->pa);
	i = st->pa - 1;
	while (++i < st->n)
		ft_printf("%4d", st->a[i]);
	ft_printf("\n");
	ft_printf("\033[0;36m b:      \033[0m ");
	ft_printf("%3d,", st->pb);
	i = st->pb;
	while (++i < st->n)
		ft_printf("%4d", st->b[i]);
	ft_printf("\033[0;33m \n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n \033[0m");
}

/*
** print sorted array
*/

void	print_sorted(int *srt, int n)
{
	int i;

	i = -1;
	ft_printf("               ");
	while (++i < n)
		ft_printf(" %2d ", i);
	ft_printf("\n");
	i = -1;
	ft_printf("\033[0;32m sorted array:\033[0m ");
	while (++i < n)
		ft_printf(" %2d ", srt[i]);
	ft_printf("\n");
}
