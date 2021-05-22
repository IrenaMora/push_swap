#include "push_swap.h"

void	command_rr(t_list *stack_a, t_list *stack_b, \
int *command_size, char **commands)
{
	if (commands == NULL)
		(*command_size)++;
	else if (commands != NULL)
		add_command(commands, command_size, 7);
	command_ra(stack_a, command_size, commands);
	command_rb(stack_b, command_size, commands);
}

void	command_rrr(t_list *stack_a, t_list *stack_b, \
int *command_size, char **commands)
{
	if (commands == NULL)
		(*command_size)++;
	else if (commands != NULL)
		add_command(commands, command_size, 8);
	command_rra(stack_a, command_size, commands);
	command_rrb(stack_b, command_size, commands);
}
