/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmih <sgmih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:58:34 by sgmih             #+#    #+#             */
/*   Updated: 2025/01/31 15:05:06 by sgmih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	parse(char **av, t_list **stack_a)
{
	int		i;
	int		res;
	int		j;
	char	**str;

	i = 1;
	while (av[i])
	{
		check_empty(av[i], stack_a);
		check_valid(av[i], stack_a);
		str = ft_split(av[i], ' ');
		if (str == NULL)
			return ;
		j = 0;
		while (str[j])
		{
			res = ft_atoi(str[j], stack_a);
			check_exist(stack_a, res, str);
			ft_lstadd_back(stack_a, ft_lstnew(stack_a, res));
			(free(str[j]), str[j] = NULL);
			j++;
		}
		free(str);
		i++;
	}
}

static	void	error(t_list **a, t_list **b, char *line)
{
	free_leaks(b);
	free(line);
	ft_error(a);
}

static void	parse_command(t_list **a, t_list **b, char *command)
{
	if (!ft_strncmp(command, "pb\n", 3))
		push_a(a, b);
	else if (!ft_strncmp(command, "pa\n", 3))
		push_b(b, a);
	else if (!ft_strncmp(command, "sa\n", 3))
		swap_a(a);
	else if (!ft_strncmp(command, "sb\n", 3))
		swap_b(b);
	else if (!ft_strncmp(command, "ss\n", 3))
		swap_a_b(a, b);
	else if (!ft_strncmp(command, "ra\n", 3))
		rotate_a(a);
	else if (!ft_strncmp(command, "rb\n", 3))
		rotate_b(b);
	else if (!ft_strncmp(command, "rr\n", 3))
		rotate_a_b(a, b);
	else if (!ft_strncmp(command, "rra\n", 4))
		reverse_rotate_a(a);
	else if (!ft_strncmp(command, "rrb\n", 4))
		reverse_rotate_b(b);
	else if (!ft_strncmp(command, "rrr\n", 4))
		reverse_rotate_a_b(a, b);
	else
		error(a, b, command);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;
	char	*next_line;

	stack_a = NULL;
	stack_b = NULL;
	if (ac >= 2)
	{
		parse(av, &stack_a);
		size = ft_lstsize(stack_a);
		next_line = get_next_line(0);
		while (next_line)
		{
			parse_command(&stack_a, &stack_b, next_line);
			free(next_line);
			next_line = get_next_line(0);
		}
		if (is_sorted(&stack_a) && ft_lstsize(stack_a) == size)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		(free_leaks(&stack_a), free_leaks(&stack_b));
	}
	return (0);
}
