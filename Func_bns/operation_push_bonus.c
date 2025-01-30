/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmih <sgmih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:40:40 by sgmih             #+#    #+#             */
/*   Updated: 2025/01/30 11:21:20 by sgmih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push(t_list **src, t_list **dst, char *str)
{
	t_list	*top_src;

	if (!*src)
		return ;
	top_src = *src;
	*src = (*src)->next;
	top_src->next = NULL;
	ft_lstadd_front(dst, top_src);
	if (str)
		write(1, str, ft_strlen(str));
}

void	ft_push_a(t_list **stack_a, t_list **stack_b)
{
	while (*stack_b)
	{
		fun_position(stack_b);
		if (*stack_b == ft_lstmax(*stack_b))
			push(stack_b, stack_a, "pa\n");
		else if (ft_lstmax(*stack_b)->position <= ft_lstsize(*stack_b) / 2)
			rotate(stack_b, "rb\n");
		else
			reverse_rotate(stack_b, "rrb\n");
	}
}
void push_a(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b, NULL);
    write(1, "pb\n", 3);
}

void push_b(t_list **stack_b, t_list **stack_a)
{
    push(stack_b, stack_a, NULL);
    write(1, "pa\n", 3);
}
