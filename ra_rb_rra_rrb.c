#include "push_swap.h"

void	command_ra(t_list *stack, int *command_size, char **commands)
{
	char	*first_value;
	t_list	*current;

	if (commands == NULL)
		(*command_size)++;
	else if (commands != NULL)
		add_command(commands, command_size, 1);
	if (stack == NULL)
		return ;
	current = stack;
	first_value = stack->content;
	while (current != NULL && current->next != NULL)
	{
		current->content = current->next->content;
		current = current->next;
	}
	current->content = first_value;
}

void	command_rb(t_list *stack, int *command_size, char **commands)
{
	char	*first_value;
	t_list	*current;

	if (commands == NULL)
		(*command_size)++;
	else if (commands != NULL)
		add_command(commands, command_size, 2);
	if (stack == NULL)
		return ;
	current = stack;
	first_value = stack->content;
	while (current != NULL && current->next != NULL)
	{
		current->content = current->next->content;
		current = current->next;
	}
	current->content = first_value;
}

void	command_rra(t_list *stack, int *command_size, char **commands)
{
	char	*tmp_saved;
	char	*tmp_saved2;
	t_list	*current;

	if (commands == NULL)
		(*command_size)++;
	else if (commands != NULL)
		add_command(commands, command_size, 3);
	if (stack == NULL || stack->next == NULL)
		return ;
	current = stack;
	tmp_saved = current->next->content;
	current->next->content = current->content;
	current = current->next;
	while (current != NULL && current->next != NULL)
	{
		tmp_saved2 = current->next->content;
		current->next->content = tmp_saved;
		current = current->next;
		tmp_saved = tmp_saved2;
	}
	stack->content = tmp_saved;
}

void	command_rrb(t_list *stack, int *command_size, char **commands)
{
	char	*tmp_saved;
	char	*tmp_saved2;
	t_list	*current;

	if (commands == NULL)
		(*command_size)++;
	else if (commands != NULL)
		add_command(commands, command_size, 4);
	if (stack == NULL || stack->next == NULL)
		return ;
	current = stack;
	tmp_saved = current->next->content;
	current->next->content = current->content;
	current = current->next;
	while (current != NULL && current->next != NULL)
	{
		tmp_saved2 = current->next->content;
		current->next->content = tmp_saved;
		current = current->next;
		tmp_saved = tmp_saved2;
	}
	stack->content = tmp_saved;
}
