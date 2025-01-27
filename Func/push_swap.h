# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <libc.h>

typedef struct s_list
{
    int             content;
    int             index;
    int             position;
    struct s_list   *next;
} t_list;

/* functions */
void    parse(char **av, t_list **stack_a);
void    check_exist(t_list **stack, int res, char **str);
void    check_empty(char *av, t_list **stack);
void    check_valid(char *av, t_list **stack);
char    **ft_split(char *s, char c);
void	fun_position(t_list **s1);
void    fun_index(t_list **str, t_list *node);
void	fun_index(t_list **s1, t_list *node);
void    ft_lstadd_back(t_list **lst, t_list *new);
void    ft_lstadd_front(t_list **lst, t_list *new);
t_list  *ft_lstmax(t_list *lst);
t_list  *ft_lstmin(t_list *lst);
t_list  *ft_lstlast(t_list *lst);
t_list  *ft_lstnew(t_list **stack_a, int content);
size_t  ft_strlen(char *str);
void    ft_error(t_list **stack);
int	ft_lstsize(t_list *lst);
int ft_atoi(char *str, t_list **stack);
int ft_sort_3(t_list **lst);
int	ft_sort_4(t_list **stack_a, t_list **stack_b);
int	ft_sort_5(t_list **stack_a, t_list **stack_b);
void push(t_list **src, t_list **dst, char *str);
void reverse_rotate(t_list **stack, char *str);
void swap(t_list **stack, char *str);
void rotate(t_list **stack, char *str);
int	ft_sort(t_list **a, t_list **b, int size);
void push_a(t_list **stack_a, t_list **stack_b);
void    ft_lstclear(t_list **lst);
void	free_leaks(t_list **stack);



//void reverse_rotate_a_b(t_list **stack_a, t_list **stack_b);
//void rotate_a_b(t_list **stack_a, t_list **stack_b);




void print_stack(t_list *stack, char *name);


// void ft_lstclear(t_list **lst);

// void free_leaks(t_list **stack);



# endif