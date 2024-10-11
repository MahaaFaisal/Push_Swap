/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:59:05 by mafaisal          #+#    #+#             */
/*   Updated: 2024/01/25 13:59:49 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_target(t_list **stackb, t_list **stacka)
{
	t_list	*a;
	t_list	*b;

	b = *stackb;
	while (b)
	{
		a = *stacka;
		b->target = get_max(*stacka);
		while (a)
		{
			if (b->data < a->data && a->data < b->target->data)
				b->target = a;
			a = a->next;
		}
		if (b->data > b->target->data)
			b->target = get_min(*stacka);
		b = b->next;
	}
}

void	update_location(t_list **stack)
{
	int		location;
	t_list	*s;

	s = *stack;
	location = 0;
	while (s)
	{
		s->location = location;
		location++;
		s = s->next;
	}
}

void	update_cost(t_list **stack)
{
	t_list	*s;

	s = *stack;
	while (s)
	{
		if (s->location <= (lstsize(*stack) / 2))
			s->cost = s->location;
		else
			s->cost = lstsize(*stack) - s->location;
		s = s->next;
	}
}

void	update_stacks(t_list **stack1, t_list **stack2)
{
	update_location(stack1);
	update_cost(stack1);
	update_location(stack2);
	update_cost(stack2);
}
