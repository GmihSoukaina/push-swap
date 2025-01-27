/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmih <sgmih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:36:46 by sgmih             #+#    #+#             */
/*   Updated: 2025/01/27 16:55:19 by sgmih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack, char *str)
{
	t_list	*first;
	t_list	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	if (str)
		write(1, str, ft_strlen(str));
}

void swap_a(t_list **stack_a)
{
    swap(stack_a, NULL);
    write(1, "sa\n", 3);
}

void swap_b(t_list **stack_b)
{
    swap(stack_b, NULL);
    write(1, "sb\n", 3);
}

void swap_a_b(t_list **stack_a, t_list **stack_b)
{
    swap(stack_a, NULL);
    swap(stack_b, NULL);
    write(1, "ss\n", 3);
}