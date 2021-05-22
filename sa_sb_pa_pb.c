#include "push_swap.h"

void	command_sa(t_list *stack)
{
	char	*value1;
	char	*value2;

	if (!stack || !(stack->next))
		return ;
	value1 = stack->content;
	value2 = stack->next->content;
	stack->content = value2;
	stack->next->content = value1;
}

void	command_pb(t_list **stack_a, t_list **stack_b, \
int *command_size, char **commands)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (commands == NULL)
		(*command_size)++;
	else if (commands != NULL)
		add_command(commands, command_size, 6);
	if (!(*stack_a))
		return ;
	tmp1 = (*stack_a)->next;
	tmp2 = NULL;
	if (*stack_b)
		tmp2 = (*stack_b);
	*stack_b = *stack_a;
	*stack_a = tmp1;
	(*stack_b)->next = tmp2;
}

void	command_pa(t_list **stack_b, t_list **stack_a, \
int *command_size, char **commands)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (commands == NULL)
		(*command_size)++;
	else if (commands != NULL)
		add_command(commands, command_size, 5);
	if (!(*stack_a))
		return ;
	tmp1 = (*stack_a)->next;
	tmp2 = NULL;
	if (*stack_b)
		tmp2 = (*stack_b);
	*stack_b = *stack_a;
	*stack_a = tmp1;
	(*stack_b)->next = tmp2;
}
