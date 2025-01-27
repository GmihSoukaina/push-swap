#include "push_swap.h"

void print_list(t_list *stack_a)
{
    t_list *tmp = stack_a;

    while (tmp)
    {
        printf("Content: %d, Index: %d, Position: %d\n", tmp->content, tmp->index, tmp->position);
        tmp = tmp->next;
    }
}

void parse(char **av, t_list **stack_a)
{
    int i;
    int res;
    int j;
    char **str;

    i = 1;
    while (av[i])
    {
        check_empty(av[i], stack_a);
        check_valid(av[i], stack_a);

        str = ft_split(av[i], ' ');

        if (str == NULL)
            return;

        j = 0;
        while (str[j])
        {
            res = ft_atoi(str[j], stack_a);
            //check_exist(stack_a, res, &str[j]);
            check_exist(stack_a, res, str); 
            ft_lstadd_back(stack_a, ft_lstnew(stack_a, res));
            free(str[j]);
            str[j] = NULL;
            j++;
        }
        //print_list(*stack_a);
        free(str);
        i++;
    }
}

// void fun()
// {
//     system("leaks push_swap");
// }
int main(int ac, char **av)
{
    //atexit(fun);
    // printf("%s", av[3]);
    // return 1;
    t_list *stack_a;
    t_list *stack_b;
    t_list	*tmp;
    int size;

    stack_a = NULL;
    stack_b = NULL;
    if (ac >= 2)
    {
        parse(av, &stack_a);

        size = ft_lstsize(stack_a);
        tmp = stack_a;
        while (tmp->next)
        {
            if (tmp->content > tmp->next->content)
                break ;
            tmp = tmp->next;
        }
        if (!tmp->next) // If we reached the end, the list is already sorted
        {
            ft_lstclear(&stack_a);
            return (0);
        }

        // Sort based on the size of the stack
        if (size <= 3)
            ft_sort_3(&stack_a); // Sort using ft_sort_3 for 3 or fewer elements
        if (size == 4)
            ft_sort_4(&stack_a, &stack_b); // Sort using ft_sort_4 for exactly 4 elements
        if (size == 5)
            ft_sort_5(&stack_a, &stack_b); // Sort using ft_sort_5 for exactly 5 elements
        if (size > 5)
            ft_sort(&stack_a, &stack_b, size); 
        ft_lstclear(&stack_a); // Free allocated memory after sorting

        //ft_sort(&stack_a, &stack_b, ft_lstsize(stack_a)); // Sorting function
        free_leaks(&stack_a);
        free_leaks(&stack_b);
        //printf("Before sorting:\n");
        //print_list(stack_a);

        //ft_sort_4(&stack_a, &stack_b);
        // printf("size stack_a: %d\n", ft_lstsize(stack_a));
        // printf("size stack_a: %d\n", ft_lstsize(stack_b));
    }
    //printf("After sorting:\n");
    //print_list(stack_a);
    //print_list(stack_b);
    return (0);
}
