#include "push_swap.h"

char	*write_command_by_id(int command)
{
	if (command == 1)
		ft_putstr("ra\n", 1);
	else if (command == 2)
		ft_putstr("rb\n", 1);
	else if (command == 3)
		ft_putstr("rra\n", 1);
	else if (command == 4)
		ft_putstr("rrb\n", 1);
	else if (command == 5)
		ft_putstr("pa\n", 1);
	else if (command == 6)
		ft_putstr("pb\n", 1);
	else if (command == 7)
		ft_putstr("rr\n", 1);
	else if (command == 8)
		ft_putstr("rrr\n", 1);
	return ("");
}

int	commands_one_back(char **commands, int command_size, int position)
{
	while (position < command_size && (*commands)[position] != 0)
	{
		(*commands)[position] = (*commands)[position + 1];
		position++;
	}
	(*commands)[position] = 0;
	return (0);
}

int	commands_optimize(char **commands, int command_size)
{
	int	position;
	int	pos_cur;
	int	pos_next;
	int	optimized;

	position = 0;
	optimized = 0;
	while ((*commands)[position] != 0 && position < command_size)
	{
		pos_cur = (*commands)[position];
		pos_next = (*commands)[position + 1];
		if (((pos_cur == 3 && pos_next == 4) || (pos_cur == 4 && pos_next == 3)) \
		&& ++optimized)
			(*commands)[position] = 8;
		else if (((pos_cur == 1 && pos_next == 2) || (pos_cur == 2 && pos_next == 1)) \
		&& ++optimized)
			(*commands)[position] = 7;
		if (optimized)
		{
			commands_one_back(commands, command_size, position + 1);
			return (1);
		}
		position++;
	}
	return (0);
}
