#include "push_swap.h"

void	sort_three(t_list *stack)
{
	int	first;
	int	second;
	int	last;

	if (stack_is_sorted(stack))
		return ;
	first = get_first(stack);
	second = get_second(stack);
	last = get_last(stack);
	if (first < second && first < last && second > first)
	{
		command_rra_cut(stack);
		command_sa_cut(stack);
	}
	else if (first > second && first < last && second < last)
		command_sa_cut(stack);
	else if (first < second && first > last && second > last)
		command_rra_cut(stack);
	else if (first > second && first > last && second < last)
		command_ra_cut(stack);
	else if (first > second && first > last && second > last)
	{
		command_ra_cut(stack);
		command_sa_cut(stack);
	}
}

void	min_to_another_stack(t_list **stack, t_list **stack_b, int *cmd_size)
{
	int	pos_min_value;

	pos_min_value = get_min_value(*stack);
	while (get_first(*stack) != pos_min_value)
	{
		if (sort_by_side(*stack, pos_min_value) == 1)
		{
			command_ra(*stack, cmd_size, NULL);
			ft_putstr("ra\n", 1);
		}
		else
		{
			command_rra(*stack, cmd_size, NULL);
			ft_putstr("rra\n", 1);
		}
	}
	ft_putstr("pb\n", 1);
	command_pb(stack, stack_b, cmd_size, NULL);
}

void	sort_four(t_list **stack, t_list **stack_b)
{
	int	cmd_size;

	cmd_size = 0;
	min_to_another_stack(stack, stack_b, &cmd_size);
	sort_three(*stack);
	ft_putstr("pa\n", 1);
	command_pa(stack, stack_b, &cmd_size, NULL);
}

void	sort_five(t_list **stack, t_list **stack_b)
{
	int	cmd_size;

	min_to_another_stack(stack, stack_b, &cmd_size);
	min_to_another_stack(stack, stack_b, &cmd_size);
	sort_three(*stack);
	ft_putstr("pa\n", 1);
	command_pa(stack, stack_b, &cmd_size, NULL);
	ft_putstr("pa\n", 1);
	command_pa(stack, stack_b, &cmd_size, NULL);
}
