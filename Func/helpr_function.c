#include "push_swap.h"

// // Function to assign index based on content
// void fun_index(t_list **str, t_list *node)
// {
//     t_list *tmp;
//     if (!str || !*str)
//         return;
//     tmp = *str;
//     while (tmp)
//     {
//         // If the content of 'tmp' is greater than the 'node' content, increment the 'index' of the current node.
//         if (tmp->content < node->content)
//             tmp->index++;
//         // If the content of 'tmp' is smaller than the 'node' content, increment the 'index' of 'node'.
//         else if (tmp->content > node->content)
//             node->index++;
//         tmp = tmp->next;
//     }
// }

// void fun_index(t_list **str, t_list *node)
// { 
//     t_list *tmp;
//     int count;
//     if (!str || !*str)
//         return;
//     tmp = *str;
//     count = 0;
//     while (tmp)
//     {
//         if (tmp->content < node->content) 
//             count++;
//         tmp = tmp->next;
//     }
// 	printf("Debug: Content: %d, Count: %d\n", node->content, count);
//     node->index = count;
// }

// void fun_index_count(t_list **head)
// {
//     t_list *tmp;
//     if (!head || !*head) 
//         return;
//     tmp = *head; 
//     while (tmp)
//     {
//         fun_index(head, tmp);  // Assign the correct index based on content
//         tmp = tmp->next;
//     }
// }


void	fun_index(t_list **str, t_list *node)
{
	t_list	*tmp;

	if (!str || !*str)
		return ;
	tmp = *str;
	while (tmp)
	{
		if (tmp->content > node->content)
			tmp->index++; 
		else
			node->index++; 
		tmp = tmp->next;
	}
}

void	fun_position(t_list **s1)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *s1;
	while (tmp)
	{
		tmp->position = i;  // Set the position of each node
		tmp = tmp->next;
		i++;
	}
}

static	int	ft_intlen(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

int	ft_atoi(char *str, t_list **stack)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
		if (!(*str >= '0' && *str <= '9'))
			ft_error(stack);
	}
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + (*str - '0'); //Converts "123" to 123 by iterating
		str++;
	}
	res *= sign;
	if (res > 2147483647 || res < -2147483648 || *str == '-' || *str == '+'
		|| (ft_intlen(res) > 10 && res > 0) || (ft_intlen(res) > 11 && res < 0))
		ft_error(stack);
	return (res);
}
