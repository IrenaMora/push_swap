#include "push_swap.h"

int	get_optimal_range(t_list *stack)
{
	int	pos;
	int	range;

	pos = 0;
	while (pos * 100 < stack_size(stack))
		pos++;
	range = stack_size(stack) / 32 + pos + 1;
	return (range);
}

int	get_command_size(t_list **stack, t_list **stack_b, \
int args_count, char **args)
{
	int	range;
	int	command_size;

	range = get_optimal_range(*stack);
	command_size = 0;
	while (stack_size(*stack) != 0)
	{
		on_top_best(*stack, range, &command_size, NULL);
		sort_stack_one(stack, stack_b, &command_size, NULL);
	}
	back_sort(stack, stack_b, &command_size, NULL);
	list_clean(*stack);
	*stack = fill_stack(args_count, args);
	if (*stack == NULL)
		return (-1);
	return (command_size);
}

char	*commands_init(char **commands, int command_size)
{
	int	pos;

	if (command_size == -1)
		return (NULL);
	pos = 0;
	*commands = malloc(sizeof(char) * (command_size + 1));
	if (*commands == NULL)
		return (NULL);
	while (pos < command_size)
		(*commands)[pos++] = 0;
	return (*commands);
}
