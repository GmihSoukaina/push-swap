/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmih <sgmih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:40:06 by sgmih             #+#    #+#             */
/*   Updated: 2025/01/27 16:59:03 by sgmih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_list **stack, char *str)
{
	t_list	*last;
	t_list	*second_last;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	ft_lstadd_front(stack, last);
	if (str)
		write(1, str, ft_strlen(str));
}

void reverse_rotate_a(t_list **stack_a)
{
    reverse_rotate(stack_a, NULL);
    write(1, "rra\n", 3);
}

void reverse_rotate_b(t_list **stack_b)
{
    reverse_rotate(stack_b, NULL);
    write(1, "rrb\n", 3);
}

void reverse_rotate_a_b(t_list **stack_a, t_list **stack_b)
{
    reverse_rotate(stack_a, NULL);
    reverse_rotate(stack_b, NULL);
    write(1, "rrr\n", 3);
}
