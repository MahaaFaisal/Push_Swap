/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:44:43 by mafaisal          #+#    #+#             */
/*   Updated: 2024/01/18 12:10:11 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	instack(int num, t_list *stack)
{
	t_list	*loop;

	loop = stack;
	while (loop)
	{
		if (loop->data == num)
			return (1);
		loop = loop->next;
	}
	return (0);
}

int	issorted(t_list *stack)
{
	t_list	*loop;

	loop = stack;
	while (loop && loop->next)
	{
		if ((loop->data < loop ->next->data))
			loop = loop->next;
		else
			return (0);
	}
	return (1);
}

int	isempty(t_list *stack)
{
	if (stack)
		return (0);
	return (1);
}

int	isalldigit(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ((str[i] >= '0' && str[i] <= '9')
			|| is_space(str[i]) || str[i] == '+' || str[i] == '-'))
		i++;
	if (!str[i])
		return (1);
	return (0);
}
