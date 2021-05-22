#include "push_swap.h"

int	ft_atoi(char *str)
{
	int	digit;
	int	position;
	int	addition;

	digit = 0;
	position = 0;
	addition = 1;
	while (str[position] != '\0' && is_continue(str[position]))
		position++;
	if (str[position] == '+')
		position++;
	else if (str[position] == '-' && ++position)
		addition = -1;
	while (str[position] != '\0')
	{
		digit = digit * 10 + (str[position] - 48);
		position++;
	}
	digit = digit * addition;
	return (digit);
}

int	str_is_digit(char *str)
{
	long	position;
	long	position_tmp;

	position = 0;
	while (str[position] != '\0' && is_continue(str[position]))
		position++;
	if (str[position] == '+' || str[position] == '-')
		position++;
	position_tmp = position;
	while (str[position] != '\0')
	{
		if (!(str[position] >= 48 && str[position] <= 57))
			return (0);
		position++;
	}
	if (position == position_tmp)
		return (0);
	if (position == 0)
		return (0);
	return (1);
}

int	str_is_double(int args_count, char **args)
{
	long	current;
	long	position;

	position = 1;
	while (position < args_count)
	{
		current = position + 1;
		while (current < args_count)
		{
			if (ft_strcompare(args[current], args[position]))
				return (1);
			current++;
		}
		position++;
	}
	return (0);
}

int	str_overflow(char *str)
{
	int		addition;
	long	digit;
	long	position;

	digit = 0;
	position = 0;
	addition = 1;
	while (str[position] != '\0' && is_continue(str[position]))
		position++;
	if ((str[position] == '+' || str[position] == '-') && position++)
		addition = -1;
	while (str[position] != '\0')
	{
		digit = digit * 10 + (str[position] - 48) * addition;
		addition = 1;
		position++;
		if (digit > 2147483647 || digit < -2147483648)
			return (1);
	}
	return (0);
}
