#include "push_swap.h"

void	ft_error(t_list **stack)
{
	// remoooove void and used stack 
	//(void)stack;
	write(1, "Error\n", 6);
	free_leaks(stack);
	exit(1);
}

void	check_empty(char *av, t_list **stack)
{
	int	i;

	i = 0;
	if (!av[0])
		ft_error(stack);
	while ((av[i] >= 9 && av[i] <= 13) || av[i] == ' ')
		i++;
	if (!av[i])
		ft_error(stack);
}

void	check_valid(char *av, t_list **stack)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] == ' ')
			i++;
		else if (av[i] == '+' || av[i] == '-')
		{
			if (av[i + 1] < '0' || av[i + 1] > '9')
				ft_error(stack);
			i++;
		}
		else if (av[i] >= '0' && av[i] <= '9')
			i++;
		else
			ft_error(stack);
	}
}

void	check_exist(t_list **stack, int res, char **str)
{
	t_list	*temp;
	char	**temp_str = str; // Save original pointer

	if (!stack || !(*stack))  
		return ;

	temp = *stack;
	while (temp != NULL)
	{
		if (temp->content == res) // If duplicate is found
		{
			while (*temp_str) // Free each part of the split array
			{
				free(*temp_str);
				temp_str++;
			}
			free(str); // Free the array itself
			ft_error(stack);
		}
		temp = temp->next;
	}
}

// void	check_exist(t_list **stack, int res, char **str)
// {
// 	t_list	*temp;
// 	char **temp_str;
// 	if (!stack || !(*stack))  // Ensure the stack is not NULL and contains elements
// 		return ;
// 	temp = *stack;
// 	while (temp != NULL)
// 	{
// 		//printf("Checking stack value: %d against input value: %d\n", temp->content, res); // Debug print
// 		if (temp->content == res) // If a duplicate is found
// 		{
// 			temp_str = str;
// 			while (*str) // Free each part of the split array
// 			{
// 				free(*str);
// 				str++;
// 			}
// 			free(temp_str);
// 			ft_error(stack);
// 		}
// 		temp = temp->next;
// 	}
// }