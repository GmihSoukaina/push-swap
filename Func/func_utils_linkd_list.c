#include "push_swap.h"

// t_list	*ft_lstnew(t_list **stack, int content)
// {
//     t_list *new_node;
//     new_node = malloc(sizeof(t_list));
//     if (!new_node)
//         return NULL;
//     new_node->content = content;
//     new_node->index = 0;
//     new_node->next = NULL;
//     return new_node;
// }

// t_list *ft_lstnew(int content)
// {
//     t_list *new_node;
//     new_node = malloc(sizeof(t_list));
//     if (!new_node)
//         return NULL;
//     new_node->content = content;
//     new_node->index = 0;  // Index will be assigned later
//     new_node->position = 0;
//     new_node->next = NULL;
//     return (new_node);
// }

t_list *ft_lstnew(t_list **stack_a, int content)
{
    t_list *new_node;

    new_node = (t_list *)malloc(sizeof(t_list));
    if (!new_node)
        return NULL;

    new_node->content = content;
    new_node->position = 0;
    new_node->next = NULL;
    new_node->index = 0; 
    fun_index(stack_a, new_node);
    return (new_node);
}

void	ft_lstadd_back(t_list **stack, t_list *new)
{
	t_list	*last;

	if (!stack || !new)
		return ;
	if (!(*stack))
	{
		*stack = new;
		return ;
	}
	last = ft_lstlast(*stack);
	last->next = new;
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr;

	if (!lst)
		return (NULL);
	ptr = lst;
	while (ptr->next)
	{
		ptr = ptr->next;
	}
	return (ptr);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*ptr;

	if (!lst)
		return ;
	while (*lst)
	{
		ptr = (*lst)->next;
		free(*lst);
		*lst = NULL;
		*lst = ptr;
	}
	lst = NULL;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

int	ft_lstsize(t_list *lst)
{
	int	count;

	if (!lst)
		return (0);
	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}