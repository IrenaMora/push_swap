#include "push_swap.h"

long	ft_strlen(char *str)
{
	long	position;

	position = 0;
	while (str[position] != '\0')
		position++;
	return (position);
}

long	ft_putstr(char *str, int output)
{
	long	position;

	position = 0;
	while (str[position] != '\0')
		write(output, &str[position++], 1);
	return (position);
}

int	ft_strcompare(char *str1, char *str2)
{
	long	position;

	position = 0;
	while (str1[position] != '\0' && str2[position] != '\0')
	{
		if (str1[position] != str2[position])
			return (0);
		position++;
	}
	if (str1[position] == '\0' && str2[position] == '\0')
		return (1);
	return (0);
}

int	is_continue(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int	is_sorted(int args_count, char **args)
{
	long	position;

	position = 2;
	while (position < args_count)
	{
		if (ft_atoi(args[position - 1]) > ft_atoi(args[position]))
			return (0);
		position++;
	}
	return (1);
}
