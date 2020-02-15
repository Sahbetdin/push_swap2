
#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "./my_libft/libft.h"


typedef struct	s_stacks
{
	int			*a;
	int			*b;
	int			pa;
	int			pb;
	int			n;
	int			oper;
}				t_stacks;

typedef struct	s_info
{
	int			begin;
	int			end;
	int			amount;
	char		lt;
}				t_info;

void	set_arr_to_zero(int *b, int n);
void	set_arr_with_numbers(int *a, int n);
int		*sort_array(int *arr, int n);
//library functions
void    ft_swap(int *a, int *b);
int     ft_memcmp(const void *s1, const void *s2, size_t n);
//operations
void	swap_in_stack(t_stacks *st, char c);
void	swap_both(t_stacks *st);
void	push_1_to_2(t_stacks *st, char c);
void	rotate(t_stacks *st, char c);
void	rotate_both(t_stacks *st);
void	reverse_rotate(t_stacks *st, char c);
void	reverse_rotate_both(t_stacks *st);
//action
void	action(t_stacks *st, char *act);
//sort <= 4 elements
void	sort_2_elements(t_stacks *st, t_info *pc0);
void	sort_3_elements(t_stacks *st, t_info *pc0, int *srt);
void	sort_4_elements(t_stacks *st, t_info *pc0, int *srt);
//printing
void	print_piece(t_info piece0);
void	print_arrays(t_stacks *st);
#endif
