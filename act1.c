
#include "ps_header.h"


void	ra_2(t_stacks *st)
{
	action(st, "ra", 1);
	action(st, "ra", 1);
}

void	pa_2(t_stacks *st)
{
	action(st, "pa", 1);
	action(st, "pa", 1);
}

void	pa_ra(t_stacks *st)
{
	action(st, "pa", 1);
	action(st, "ra", 1);
}

void	sa_ra(t_stacks *st)
{
	action(st, "sa", 1);
	action(st, "ra", 1);
}

void	sa_rra(t_stacks *st)
{
	action(st, "sa", 1);
	action(st, "rra", 1);
}

/*
** begin increases by delta
** amount decreases by delta
*/

void change_piece_beg_am(t_info *pc0, int delta)
{
	pc0->begin += delta;
	pc0->amount -= delta;
}
