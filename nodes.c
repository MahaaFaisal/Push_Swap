/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:49:52 by mafaisal          #+#    #+#             */
/*   Updated: 2024/01/25 14:14:56 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	last = lst;
	while (last && last->next)
	{
		last = last->next;
	}
	return (last);
}

t_list	*ft_lstseclast(t_list *lst)
{
	t_list	*seclast;

	seclast = lst;
	while (seclast && seclast->next && seclast->next->next)
	{
		seclast = seclast->next;
	}
	return (seclast);
}

t_list	*get_min(t_list *stack)
{
	t_list	*min;
	t_list	*loop;

	min = stack;
	loop = stack;
	while (loop)
	{
		if (min->data > loop->data)
			min = loop;
		loop = loop->next;
	}
	return (min);
}

t_list	*get_max(t_list *stack)
{
	t_list	*max;
	t_list	*loop;

	max = stack;
	loop = stack;
	while (loop)
	{
		if (max->data < loop->data)
			max = loop;
		loop = loop->next;
	}
	return (max);
}
