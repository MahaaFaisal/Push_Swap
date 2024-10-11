/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:34:03 by mafaisal          #+#    #+#             */
/*   Updated: 2024/01/27 15:55:38 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	to_top(t_list **stack, t_list *node, char c)
{
	if (!*stack)
		return ;
	if (node->location == node->cost)
	{
		while (*stack != node)
			rotate(stack, NULL, c);
	}
	else
	{
		while (*stack != node)
			revrotate(stack, NULL, c);
	}
}

t_list	*cheapest(t_list *b)
{
	t_list	*cheapest;
	t_list	*loop;

	loop = b;
	cheapest = b;
	while (loop && (cheapest->cost + cheapest->target->cost) > 0)
	{
		if ((loop->cost + loop->target->cost)
			< (cheapest->cost + cheapest->target->cost))
			cheapest = loop;
		loop = loop->next;
	}
	return (cheapest);
}

void	cheap_to_top(t_list **a, t_list **b)
{
	t_list	*cheap;

	cheap = cheapest(*b);
	if (!*b)
		return ;
	if (cheap->location == cheap->cost
		&& cheap->target->location == cheap->target->cost)
	{
		while (*b != cheap && *a != cheap->target)
			rotate(a, b, 'r');
	}
	else if (cheap->location != cheap->cost
		&& cheap->target->location != cheap->target->cost)
	{
		while (*b != cheap && *a != cheap->target)
			revrotate(a, b, 'r');
	}
	update_stacks(a, b);
	to_top(b, cheap, 'b');
	to_top(a, cheap->target, 'a');
}

void	sort_three(t_list **s, char c)
{
	if (!issorted (*s) && (ft_lstlast(*s) == get_min(*s)))
	{
		if ((*s)->data > (*s)->next->data)
			swap_top(s, c);
		if (!issorted(*s))
			revrotate(s, NULL, c);
	}
	else if (!issorted (*s) && (*s == get_max(*s) || (*s)->next == get_max(*s)))
	{
		if ((*s)->next == get_max(*s))
			swap_top(s, c);
		if (!issorted(*s))
			rotate(s, NULL, c);
	}
	else if (!issorted(*s))
		swap_top(s, c);
}

void	sort(t_list **a, t_list **b)
{
	while (lstsize(*a) > 3)
	{
		pop_push(a, b, 'b');
	}
	sort_three(a, 'a');
	while (*b)
	{
		update_target(b, a);
		update_stacks(a, b);
		cheap_to_top(a, b);
		pop_push(b, a, 'a');
	}
	update_stacks(a, b);
	to_top(a, get_min(*a), 'a');
}
