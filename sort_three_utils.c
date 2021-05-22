#include "push_swap.h"

void	command_sa_cut(t_list *stack)
{
	command_sa(stack);
	ft_putstr("sa\n", 1);
}

void	command_ra_cut(t_list *stack)
{
	int	value;

	value = 0;
	command_ra(stack, &value, NULL);
	ft_putstr("ra\n", 1);
}

void	command_rra_cut(t_list *stack)
{
	int	value;

	value = 0;
	command_rra(stack, &value, NULL);
	ft_putstr("rra\n", 1);
}
