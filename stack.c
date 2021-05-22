#include "push_swap.h"

int	list_get_content(t_list *stack, long number)
{
	long	position;
	long	empty;
	t_list	*tmp;

	position = 0;
	empty = 0;
	tmp = stack;
	while (position < number)
	{
		if (tmp->content != NULL)
		{
			tmp = tmp->next;
			position++;
		}
		else
			empty++;
	}
	return (ft_atoi(tmp->content));
}

int	stack_is_sorted(t_list *stack)
{
	long	size;
	long	position;

	if (stack == NULL)
		return (0);
	size = stack_size(stack);
	position = 1;
	while (position < size)
	{
		if (list_get_content(stack, position - 1) \
		> list_get_content(stack, position))
			return (0);
		position++;
	}
	return (1);
}

int	stack_back_sorted(t_list *stack)
{
	long	size;
	long	position;

	if (stack == NULL)
		return (0);
	size = stack_size(stack);
	position = 1;
	while (position < size)
	{
		if (list_get_content(stack, position - 1) \
		> list_get_content(stack, position))
			return (0);
		position++;
	}
	return (1);
}

t_list	*fill_stack(int args_count, char **args)
{
	long	position;
	t_list	*stack;
	t_list	*tmp;

	stack = list_create(args[1]);
	if (stack == NULL)
	{
		list_clean(stack);
		return (NULL);
	}
	position = 2;
	while (position < args_count)
	{
		tmp = list_create(args[position]);
		if (tmp == NULL)
		{
			list_clean(stack);
			return (NULL);
		}
		stack = list_add_back(stack, tmp);
		position++;
	}
	return (stack);
}

long	stack_size(t_list *stack)
{
	long	position;
	t_list	*tmp;

	position = 0;
	tmp = stack;
	while (tmp != NULL && ++position)
		tmp = tmp->next;
	return (position);
}
