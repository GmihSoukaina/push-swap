/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmih <sgmih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:36:46 by sgmih             #+#    #+#             */
/*   Updated: 2025/01/31 14:52:47 by sgmih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap(t_list **stack)
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
}

void	swap_a(t_list **stack_a)
{
	swap(stack_a);
}

void	swap_b(t_list **stack_b)
{
	swap(stack_b);
}

void	swap_a_b(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
