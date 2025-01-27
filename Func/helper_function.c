/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmih <sgmih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:42:30 by sgmih             #+#    #+#             */
/*   Updated: 2025/01/27 17:37:10 by sgmih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstmax(t_list *lst)
{
	t_list	*tmp;
	t_list	*max;

	tmp = lst;
	max = tmp;
	while (tmp)
	{
		if (tmp->content > max->content)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

t_list	*ft_lstmin(t_list *lst)
{
	t_list	*tmp;
	t_list	*min;

	tmp = lst;
	min = tmp;
	while (tmp)
	{
		if (tmp->content < min->content)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

void	free_leaks(t_list **stack)
{
	t_list	*temp;

	if (!stack || !(*stack))
		return ;
	temp = *stack;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}
