#include "push_swap.h"

void push(t_list **src, t_list **dst, char *str)
{
    t_list *top_src;

    if (!*src) // If the source is empty, nothing to do
        return;

    top_src = *src;  // Get the top element of source list
    *src = (*src)->next;  // Move the source pointer to the next element
    top_src->next = NULL; // Set the next pointer of the element to NULL
    ft_lstadd_front(dst, top_src);

    if (str)
		write(1, str, ft_strlen(str));
}

void push_a(t_list **stack_a, t_list **stack_b)
{
    // printf("Initial Stack A:\n");
    // print_stack(*stack_a, "A");

    // printf("Initial Stack B:\n");
    // print_stack(*stack_b, "B");
    while (*stack_b) // While stack_b is not empty
    {
        fun_position(stack_b); // Assuming this updates positions (you may need to implement this)

        // printf("Initial Stack B:\n");
        // print_stack(*stack_b, "B");
        // If the top element of stack_b is the max, push it to stack_a
        if (*stack_b == ft_lstmax(*stack_b))
            push(stack_b, stack_a, "pa\n");

        // Otherwise, rotate or reverse rotate to bring the max to the front
        else if (ft_lstmax(*stack_b)->position <= ft_lstsize(*stack_b) / 2)
            rotate(stack_b, "rb\n");
        else
            reverse_rotate(stack_b, "rrb\n");
    }
}
