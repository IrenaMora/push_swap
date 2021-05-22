#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# define SHOW_COMMANDS_EVAL 1

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

void	push_swap(int args_count, char **args);
int		args_validation(int args_count, char **args);
int		is_sorted(int args_count, char **args);
t_list	*fill_stack(int args_count, char **args);
t_list	*sort_stack(t_list *stack, t_list *stack_b, \
int args_count, char **args);
void	sort_two(t_list *stack);
void	sort_three(t_list *stack);
void	sort_four(t_list **stack, t_list **stack_b);
void	sort_five(t_list **stack, t_list **stack_b);
void	sort_more(t_list *stack, t_list *stack_b, \
int args_count, char **args);
long	ft_strlen(char *str);
long	ft_putstr(char *str, int output);
int		str_is_digit(char *str);
int		str_is_double(int args_count, char **args);
int		str_overflow(char *str);
int		ft_strcompare(char *str1, char *str2);
int		is_continue(char c);
int		ft_atoi(char *str);
t_list	*list_create(char *content);
t_list	*list_add_front(t_list *first, t_list *lst);
t_list	*list_add_back(t_list *first, t_list *lst);
void	list_clean(t_list *first);
int		list_get_content(t_list *stack, long number);
int		stack_is_sorted(t_list *stack);
int		stack_back_sorted(t_list *stack);
long	stack_size(t_list *stack);
int		get_first(t_list *stack);
int		get_second(t_list *stack);
int		get_last(t_list *stack);
void	command_sa(t_list *stack);
void	command_pa(t_list **stack_a, t_list **stack_b, \
int *command_size, char **commands);
void	command_pb(t_list **stack_a, t_list **stack_b, \
int *command_size, char **commands);
void	command_ra(t_list *stack, int *command_size, \
char **commands);
void	command_rb(t_list *stack, int *command_size, \
char **commands);
void	command_rra(t_list *stack, int *command_size, \
char **commands);
void	command_rrb(t_list *stack, int *command_size, \
char **commands);
void	command_rr(t_list *stack_a, t_list *stack_b, \
int *command_size, char **commands);
void	command_rrr(t_list *stack_a, t_list *stack_b, \
int *command_size, char **commands);
void	command_sa_cut(t_list *stack);
void	command_ra_cut(t_list *stack);
void	command_rra_cut(t_list *stack);
void	show_stack(t_list *stack); /* DEBUG */
void	show_stacks(t_list *stack, t_list *stack_b);
void	add_command(char **commands, int *command_size, int command);
int		sort_by_side(t_list *stack, int value);
void	on_top_value(t_list *stack, int	value, \
int *command_size, char **commands);
int		get_position_by_value(t_list *stack, int value);
int		get_nearly_by_value(t_list *stack, int value);
int		get_max_value(t_list *stack);
int		get_min_value(t_list *stack);
int		get_min_near_value(t_list *stack, int near);
void	on_top_best(t_list *stack, int range, \
int *command_size, char **commands);
void	sort_stack_one(t_list **stack, t_list **stack_b, \
int *command_size, char **commands);
char	*write_command_by_id(int command);
int		commands_optimize(char **commands, int command_size);
void	back_sort(t_list **stack, t_list **stack_b, \
int *command_size, char **commands);
int		get_optimal_range(t_list *stack);
int		get_command_size(t_list **stack, t_list **stack_b, \
int args_count, char **args);
char	*commands_init(char **commands, int command_size);

#endif
