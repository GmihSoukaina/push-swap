#include "push_swap.h"

void swap(t_list **stack, char *str)
{
    t_list *first;
    t_list *second;

    if (!*stack || !(*stack)->next)
        return;
    first = *stack;
    second = first->next;

    first->next = second->next;
    second->next = first;
    *stack = second;
    if (str)
		write(1, str, ft_strlen(str));
}

// void swap_a(t_list **stack_a)
// {
//     swap(stack_a, NULL);
//     write(1, "sa\n", 3);
// }

// void swap_b(t_list **stack_b)
// {
//     swap(stack_b, NULL);
//     write(1, "sb\n", 3);
// }

// void swap_a_b(t_list **stack_a, t_list **stack_b)
// {
//     swap(stack_a, NULL);
//     swap(stack_b, NULL);
//     write(1, "ss\n", 3);
// }
