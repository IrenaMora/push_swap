#include "push_swap.h"

void	push_swap(int args_count, char **args)
{
	t_list	*stack;
	t_list	*stack_b;

	if (!args_validation(args_count, args))
	{
		ft_putstr("Error\n", 2);
		return ;
	}
	if (is_sorted(args_count, args))
		return ;
	stack = fill_stack(args_count, args);
	stack_b = NULL;
	sort_stack(stack, stack_b, args_count, args);
}

int	main(int args_count, char **args)
{
	push_swap(args_count, args);
}
