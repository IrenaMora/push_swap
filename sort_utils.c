#include "push_swap.h"

int	get_position_by_value(t_list *stack, int value)
{
	int		position;
	t_list	*tmp;

	if (!stack)
		return (-1);
	position = 1;
	tmp = stack;
	while (tmp != NULL)
	{
		if (value == ft_atoi(tmp->content))
			return (position);
		position++;
		tmp = tmp->next;
	}
	return (-1);
}

int	get_nearly_by_value(t_list *stack, int value)
{
	int	size;
	int	nearly;
	int	position;

	position = get_position_by_value(stack, value);
	size = stack_size(stack);
	nearly = size / 2 - position;
	if (nearly < 0)
		return (nearly * -1);
	return (nearly);
}

int	get_max_value(t_list *stack)
{
	t_list	*tmp;
	int		near_max;

	near_max = -2147483648;
	if (!stack)
		return (-1);
	tmp = stack;
	while (tmp != NULL)
	{
		if (near_max < ft_atoi(tmp->content))
			near_max = ft_atoi(tmp->content);
		tmp = tmp->next;
	}
	return (near_max);
}

int	get_min_value(t_list *stack)
{
	t_list	*tmp;
	int		near_min;

	near_min = 2147483647;
	if (!stack)
		return (-1);
	tmp = stack;
	while (tmp != NULL)
	{
		if (near_min > ft_atoi(tmp->content))
			near_min = ft_atoi(tmp->content);
		tmp = tmp->next;
	}
	return (near_min);
}

int	get_min_near_value(t_list *stack, int near)
{
	t_list	*tmp;
	int		near_min;

	near_min = -2147483648;
	if (!stack)
		return (-1);
	tmp = stack;
	while (tmp != NULL)
	{
		if (near > ft_atoi(tmp->content) && near_min < ft_atoi(tmp->content))
			near_min = ft_atoi(tmp->content);
		tmp = tmp->next;
	}
	return (near_min);
}
