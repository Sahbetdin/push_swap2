
#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "./my_libft/libft.h"

#define INT_MAX 2147483647

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
void	set_first_info(t_info *pc, int n);
int		*sort_array(int *arr, int n);
int		set_st_a(int ac, char **av, t_stacks **st, int **sorted);
int		set_st_b(t_stacks *st);

int		check_if_num_backsp(int ac, char **av);
int		check_if_dupl(t_stacks *st, int **srt);
int		amount_of_numb(int ac, char **av);
int		amount_of_numb_in_one_av(char *str);


char	*ft_atoi_backsp(const char *str, int *p_numb, int *n);
int		free_st_a_dupl(t_stacks *st);
int		*make_me_sorted(t_stacks *st);
int		parse_all_args(t_stacks *st, char *ptr, int *j_addr, int *n_addr);

//library functions
void    ft_swap(int *a, int *b);
// int     ft_memcmp(const void *s1, const void *s2, size_t n);
//operations
void	swap_in_stack(t_stacks *st, char c);
void	swap_both(t_stacks *st);
void	push_1_to_2(t_stacks *st, char c);
void	rotate(t_stacks *st, char c);
void	rotate_both(t_stacks *st);
void	reverse_rotate(t_stacks *st, char c);
void	reverse_rotate_both(t_stacks *st);
//action
int		action(t_stacks *st, char *act, int fl);
void	ra_2(t_stacks *st);
void	pa_2(t_stacks *st);
void	pa_ra(t_stacks *st);
void	sa_ra(t_stacks *st);
void	sa_rra(t_stacks *st);
void	rra_sa(t_stacks *st);
void	pb_2(t_stacks *st);
void	zerofy_piece(t_info *pc0);
void	change_piece_beg_am(t_info *pc0, int delta);
//sort_1_1
void	sort_1_1(t_stacks *st, t_info *pc0, int *srt);
//sort <= 4 elements
void	sort_2_elements(t_stacks *st, t_info *pc0);
void	sort_3_elements(t_stacks *st, t_info *pc0, int *srt);
void	sort_4_elements(t_stacks *st, t_info *pc0, int *srt);
void	sort_top_top(t_stacks *st, t_info *pc0);
void	sort_4_st_pa_2(t_stacks *st, t_info *pc0, int *srt);
void	sort_4_only(t_stacks *st, t_info *pc0, int *srt);
void	sort_3_for_4(t_stacks *st, int min2);
void	sort_4_st_pa_3(t_stacks *st, t_info *pc0, int *srt, int *addr_flag);
void	sort_4_st_pb_3(t_stacks *st, t_info *pc0, int *srt);
void	sort_4_st_pb_4(t_stacks *st, t_info *pc0, int *srt);
//printing
void	print_piece(t_info piece0);
void	print_arrays(t_stacks *st);
void	print_sorted(int *srt, int n);
//in ps.c
void	process_stacks(t_stacks *st, t_info *pc, int *sorted);
void	divide_piece_info(t_info *pc, int flag);
int		check_stacks(t_stacks *st);
#endif
