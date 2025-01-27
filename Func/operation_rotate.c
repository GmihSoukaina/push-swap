#include "push_swap.h"

void rotate(t_list **stack, char *str)
{
    t_list *first;
    t_list *last;

    if (!*stack || !(*stack)->next)
        return;

    first = *stack;
    *stack = first->next;
    last = ft_lstlast(*stack);
    last->next = first;
    first->next = NULL;
    if (str)
		write(1, str, ft_strlen(str));
}

// void rotate_a(t_list **stack_a)
// {
//     rotate(stack_a, NULL);
//     write(1, "ra\n", 3);
// }

// void rotate_b(t_list **stack_b)
// {
//     rotate(stack_b, NULL);
//     write(1, "rb\n", 3);
// }

// void rotate_a_b(t_list **stack_a, t_list **stack_b)
// {
//     rotate(stack_a, NULL);
//     rotate(stack_b, NULL);
//     write(1, "rr\n", 3);
// }
