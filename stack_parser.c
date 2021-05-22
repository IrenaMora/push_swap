#include "push_swap.h"

int	get_first(t_list *stack)
{
	return (ft_atoi(stack->content));
}

int	get_second(t_list *stack)
{
	return (ft_atoi(stack->next->content));
}

int	get_last(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (ft_atoi(tmp->content));
}
