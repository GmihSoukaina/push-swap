/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpr_function_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmih <sgmih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:41:41 by sgmih             #+#    #+#             */
/*   Updated: 2025/01/29 18:26:05 by sgmih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	fun_index(t_list **str, t_list *node)
{
	t_list	*tmp;

	if (!str || !*str)
		return ;
	tmp = *str;
	while (tmp)
	{
		if (tmp->content > node->content)
			tmp->index++;
		else
			node->index++;
		tmp = tmp->next;
	}
}

void	fun_position(t_list **s1)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *s1;
	while (tmp)
	{
		tmp->position = i;
		tmp = tmp->next;
		i++;
	}
}

static	int	ft_intlen(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

int	ft_atoi(char *str, t_list **stack)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
		if (!(*str >= '0' && *str <= '9'))
			ft_error(stack);
	}
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	res *= sign;
	if (res > 2147483647 || res < -2147483648 || *str == '-' || *str == '+'
		|| (ft_intlen(res) > 10 && res > 0) || (ft_intlen(res) > 11 && res < 0))
		ft_error(stack);
	return (res);
}
