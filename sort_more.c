#include "push_swap.h"

void	on_top_best(t_list *stack, int range, \
int *command_size, char **commands)
{
	int	pos;
	int	size;
	int	nearly;
	int	current_value;
	int	best_value;

	pos = 0;
	size = stack_size(stack);
	current_value = get_max_value(stack);
	nearly = get_nearly_by_value(stack, current_value);
	best_value = current_value;
	while (pos < range && pos < size - 1)
	{
		if (get_position_by_value(stack, current_value) == 1)
			break ;
		current_value = get_min_near_value(stack, current_value);
		if (nearly < get_nearly_by_value(stack, current_value))
		{
			nearly = get_nearly_by_value(stack, current_value);
			best_value = current_value;
		}
		pos++;
	}
	on_top_value(stack, best_value, command_size, commands);
}

void	set_max_value(t_list **st, t_list **st_b, \
int *command_size, char **commands)
{
	while (get_max_value(*st_b) != get_first(*st_b))
		if (sort_by_side(*st_b, get_max_value(*st_b)) == 1)
			command_rb(*st_b, command_size, commands);
	else
		command_rrb(*st_b, command_size, commands);
	command_pb(st, st_b, command_size, commands);
}

void	set_min_value(t_list **st, t_list **st_b, \
int *command_size, char **commands)
{
	while (get_min_value(*st_b) != get_last(*st_b))
		if (sort_by_side(*st_b, get_min_value(*st_b)) == 1)
			command_rb(*st_b, command_size, commands);
	else
		command_rrb(*st_b, command_size, commands);
	command_pb(st, st_b, command_size, commands);
}

void	sort_stack_one(t_list **st, t_list **st_b, \
int *command_size, char **commands)
{
	if (stack_size(*st_b) == 0)
		command_pb(st, st_b, command_size, commands);
	else if (get_max_value(*st_b) < get_first(*st))
		set_max_value(st, st_b, command_size, commands);
	else if (get_min_value(*st_b) > get_first(*st))
		set_min_value(st, st_b, command_size, commands);
	else
	{
		while (get_min_near_value(*st_b, get_first(*st)) != get_first(*st_b))
			if (sort_by_side(*st_b, get_min_near_value(*st_b, \
			get_first(*st))) == 1)
				command_rb(*st_b, command_size, commands);
		else
			command_rrb(*st_b, command_size, commands);
		command_pb(st, st_b, command_size, commands);
	}
}

void	sort_more(t_list *stack, t_list *stack_b, \
int args_count, char **args)
{
	int		pos;
	int		range;
	char	*commands;
	int		command_size;

	range = get_optimal_range(stack);
	command_size = get_command_size(&stack, &stack_b, args_count, args);
	commands = commands_init(&commands, command_size);
	if (commands == NULL)
		return ;
	while (stack_size(stack) != 0)
	{
		on_top_best(stack, range, &command_size, &commands);
		sort_stack_one(&stack, &stack_b, &command_size, &commands);
	}
	back_sort(&stack, &stack_b, &command_size, &commands);
	while (commands_optimize(&commands, command_size) != 0)
		pos = 0;
	pos = 0;
	while (commands[pos] != 0 && pos < command_size)
		write_command_by_id(commands[pos++]);
	list_clean(stack);
	free(commands);
}
