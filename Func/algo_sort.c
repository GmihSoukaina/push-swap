/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmih <sgmih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:46:03 by sgmih             #+#    #+#             */
/*   Updated: 2025/02/01 15:35:13 by sgmih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort_3(t_list **lst)
{
	if (!*lst || !(*lst)->next)
		return (0);
	if ((*lst) == ft_lstmax((*lst)))
		rotate(lst, "ra\n");
	else if ((*lst)->next == ft_lstmax((*lst)))
		reverse_rotate(lst, "rra\n");
	if ((*lst)->content > (*lst)->next->content)
		swap(lst, "sa\n");
	return (0);
}

int	ft_sort_4(t_list **stack_a, t_list **stack_b)
{
	while ((*stack_a) != ft_lstmin((*stack_a)))
	{
		if ((*stack_a)->next == ft_lstmin((*stack_a)))
			swap(stack_a, "sa\n");
		else
			reverse_rotate(stack_a, "rra\n");
	}
	push(stack_a, stack_b, "pb\n");
	ft_sort_3(stack_a);
	push(stack_b, stack_a, "pa\n");
	return (0);
}

int	ft_sort_5(t_list **stack_a, t_list **stack_b)
{
	while ((*stack_a) != ft_lstmin((*stack_a)))
	{
		if ((*stack_a)->next == ft_lstmin((*stack_a)))
			swap(stack_a, "sa\n");
		else
			reverse_rotate(stack_a, "rra\n");
	}
	push(stack_a, stack_b, "pb\n");
	ft_sort_4(stack_a, stack_b);
	push(stack_b, stack_a, "pa\n");
	return (0);
}

int	ft_sort(t_list **stack_a, t_list **stack_b, int size)
{
	int	j;
	int	i;

	i = 0;
	if (size <= 100)
		j = 15;
	else
		j = 35;
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			push(stack_a, stack_b, "pb\n");
			i++;
		}
		else if ((*stack_a)->index <= i + j)
		{
			push(stack_a, stack_b, "pb\n");
			rotate(stack_b, "rb\n");
			i++;
		}
		else
			rotate(stack_a, "ra\n");
	}
	return (ft_push_a(stack_a, stack_b), 0);
}
