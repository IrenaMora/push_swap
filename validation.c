#include "push_swap.h"

int	args_validation(int args_count, char **args)
{
	long	position;
	char	*arg;

	position = 1;
	if (args_count < 2)
		return (0);
	if (str_is_double(args_count, args))
		return (0);
	while (position < args_count)
	{
		arg = args[position];
		if (!str_is_digit(arg))
			return (0);
		if (str_overflow(arg))
			return (0);
		position++;
	}
	return (1);
}
