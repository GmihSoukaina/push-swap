/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmih <sgmih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:39:07 by sgmih             #+#    #+#             */
/*   Updated: 2025/01/29 18:26:18 by sgmih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate(t_list **stack, char *str)
{
	t_list	*first;
	t_list	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	last = ft_lstlast(*stack);
	last->next = first;
	first->next = NULL;
	if (str)
		write(1, str, ft_strlen(str));
}

void rotate_a(t_list **stack_a)
{
    rotate(stack_a, NULL);
    write(1, "ra\n", 3);
}

void rotate_b(t_list **stack_b)
{
    rotate(stack_b, NULL);
    write(1, "rb\n", 3);
}

void rotate_a_b(t_list **stack_a, t_list **stack_b)
{
    rotate(stack_a, NULL);
    rotate(stack_b, NULL);
    write(1, "rr\n", 3);
}
