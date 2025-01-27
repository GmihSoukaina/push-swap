#include "push_swap.h"

int	ft_sort_3(t_list **lst)
{
	if (!*lst || !(*lst)->next)
		return (0);

	if ((*lst) == ft_lstmax((*lst)))
		rotate(lst, "ra\n");

	else if ((*lst)->next == ft_lstmax((*lst)))
		reverse_rotate(lst, "rra\n");

	if ((*lst)->content > (*lst)->next->content)
		swap(lst, "sa\n");

	return (0);
}
 
int	ft_sort_4(t_list **stack_a, t_list **stack_b)
{
	while ((*stack_a) != ft_lstmin((*stack_a)))
	{
		//printf("Current Min: %d\n", ft_lstmin(*stack_a)->content);
		if ((*stack_a)->next == ft_lstmin((*stack_a)))
		{
			//printf("Swapping: sa\n");
			swap(stack_a, "sa\n");
		}
		else
		{
			//printf("Reverse Rotating: rra\n");
			reverse_rotate(stack_a, "rra\n");
		}
		
	}
	//print_stack(*stack_a, "A");
	//print_stack(*stack_b, "B");

	push(stack_a, stack_b, "pb\n");
	ft_sort_3(stack_a);
	push(stack_b, stack_a, "pa\n");

	//print_stack(*stack_a, "A");
	//print_stack(*stack_b, "B");
	return (0);
}

int	ft_sort_5(t_list **stack_a, t_list **stack_b)
{
	while ((*stack_a) != ft_lstmin((*stack_a)))
	{
		//printf("Current Min: %d\n", ft_lstmin(*stack_a)->content);
		if ((*stack_a)->next == ft_lstmin((*stack_a)))
			swap(stack_a, "sa\n");
		else
			reverse_rotate(stack_a, "rra\n");
	}
	// print_stack(*stack_a, "A");
	// print_stack(*stack_b, "B");

	push(stack_a, stack_b, "pb\n");
	ft_sort_4(stack_a, stack_b);
	push(stack_b, stack_a, "pa\n");

	// print_stack(*stack_a, "A");
	// print_stack(*stack_b, "B");
	return (0);
}

void print_stack(t_list *stack, char *name)
{
    printf("%s: ", name);
    while (stack)
    {
        printf("content: %d ->, index: %d ->,position: %d ->", stack->content, stack->index, stack->position);
        stack = stack->next;
    }
    printf("NULL\n");
}

int	ft_sort(t_list **stack_a, t_list **stack_b, int size)
{
	int	j;
	int	i;

	i = 0;

	// printf("Initial Stack A:\n");
    // print_stack(*stack_a, "A");

    // printf("Initial Stack B:\n");
    // print_stack(*stack_b, "B");

	if (size <= 100)
		j = 15;
	else
		j = 35;
	while (*stack_a)
	{
		// printf("i after if :%d,\n", i);
		// printf("Index :%d,\n", (*stack_a)->index);

		if ((*stack_a)->index <= i)
		{
			// printf("i ised if :%d,\n", i);
			// printf("Index :%d,\n", (*stack_a)->index);
			//printf("pb");
			push(stack_a, stack_b, "pb\n");
			i++;
		}
		else if ((*stack_a)->index <= i + j)
		{
			// printf("i + j insed ifelse :%d,\n", i + j);
			// printf("Index :%d,\n", (*stack_a)->index);

			push(stack_a, stack_b, "pb\n");
			rotate(stack_b, "rb\n");
			i++;
		}
		else
		{
            rotate(stack_a, "ra\n");
		}
	}
	return (push_a(stack_a, stack_b), 0);
}
