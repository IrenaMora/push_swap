#include "push_swap.h"

void	add_command(char **commands, int *command_size, int command)
{
	int	pos;

	pos = 0;
	while (pos < *command_size)
	{
		if ((*commands)[pos] == 0)
		{
			(*commands)[pos] = command;
			break ;
		}
		pos++;
	}
}

int	sort_by_side(t_list *stack, int value)
{
	int	size;
	int	position;

	size = stack_size(stack);
	position = get_position_by_value(stack, value);
	if (size / 2 >= position - 1)
		return (1);
	return (2);
}

void	on_top_value(t_list *stack, int	value, \
int *command_size, char **commands)
{
	while (get_first(stack) != value)
		if (sort_by_side(stack, value) == 1)
			command_ra(stack, command_size, commands);
	else
		command_rra(stack, command_size, commands);
}

void	back_sort(t_list **stack, t_list **stack_b, \
int *command_size, char **commands)
{
	int	min_value;

	min_value = get_min_value(*stack_b);
	if (sort_by_side(*stack_b, min_value) == 1)
		command_rb(*stack_b, command_size, commands);
	else
		command_rrb(*stack_b, command_size, commands);
	while (*stack_b != NULL)
		command_pa(stack, stack_b, command_size, commands);
}

t_list	*sort_stack(t_list *stack, t_list *stack_b, \
int args_count, char **args)
{
	int	size;

	size = stack_size(stack);
	if (size == 2)
		ft_putstr("ra\n", 1);
	else if (size == 3)
		sort_three(stack);
	else if (size == 4)
		sort_four(&stack, &stack_b);
	else if (size == 5)
		sort_five(&stack, &stack_b);
	else if (size >= 6)
		sort_more(stack, stack_b, args_count, args);
	if (size <= 5)
		list_clean(stack);
	return (NULL);
}
