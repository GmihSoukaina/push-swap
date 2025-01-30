/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmih <sgmih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:26:30 by sgmih             #+#    #+#             */
/*   Updated: 2025/01/30 10:11:03 by sgmih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_stack(t_list **stack_a, t_list **stack_b, int size)
{
	t_list	*tmp;

	if (!*stack_a)
		return ;
	tmp = *stack_a;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			break ;
		if (!tmp->next->next)
		{
			ft_lstclear(stack_a);
			return ;
		}
		tmp = tmp->next;
	}
	if (size <= 3)
		ft_sort_3(stack_a);
	else if (size == 4)
		ft_sort_4(stack_a, stack_b);
	else if (size == 5)
		ft_sort_5(stack_a, stack_b);
	else
		ft_sort(stack_a, stack_b, size);
	ft_lstclear(stack_a);
}

// void ff(){
// 	system("leaks push_swap");
// }

int	main(int ac, char **av)
{
	//atexit(ff);
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	if (ac >= 2)
	{
		parse(av, &stack_a);
		size = ft_lstsize(stack_a);
		ft_stack(&stack_a, &stack_b, size);
		free_leaks(&stack_a);
		free_leaks(&stack_b);
	}
	return (0);
}
