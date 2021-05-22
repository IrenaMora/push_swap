#include "push_swap.h"

t_list	*list_create(char *content)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

t_list	*list_add_front(t_list *first, t_list *lst)
{
	lst->next = first;
	first = lst;
	return (first);
}

t_list	*list_add_back(t_list *first, t_list *lst)
{
	t_list	*tmp;

	tmp = first;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = lst;
	return (first);
}

void	list_clean(t_list *first)
{
	t_list	*tmp;

	while (first)
	{
		tmp = first->next;
		free(first);
		first = tmp;
	}
}
