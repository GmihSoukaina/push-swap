/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmih <sgmih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:34:58 by sgmih             #+#    #+#             */
/*   Updated: 2025/01/31 14:39:22 by sgmih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_list **stack)
{
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
	char	**temp_str;

	if (!stack || !(*stack))
		return ;
	temp_str = str;
	temp = *stack;
	while (temp != NULL)
	{
		if (temp->content == res)
		{
			while (*temp_str)
			{
				free(*temp_str);
				temp_str++;
			}
			free(str);
			ft_error(stack);
		}
		temp = temp->next;
	}
}
