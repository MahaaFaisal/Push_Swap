/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:47:56 by mafaisal          #+#    #+#             */
/*   Updated: 2024/01/27 17:20:24 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

void	pop_push(t_list **from, t_list **to)
{
	t_list	*from_temp;

	if (isempty(*from))
		return ;
	from_temp = *from;
	*from = (*from)->next;
	from_temp->next = *to;
	*to = from_temp;
}

void	swap_top(t_list **stack)
{
	t_list	*stack_temp;
	t_list	*third_temp;

	if (isempty(*stack) || !(*stack)->next)
		return ;
	stack_temp = *stack;
	*stack = (*stack)->next;
	third_temp = (*stack)->next;
	(*stack)->next = stack_temp;
	(*stack)->next->next = third_temp;
}

void	rotate(t_list **stack, t_list **stack2)
{
	t_list	*first_temp;
	t_list	*last;

	if (*stack && lstsize(*stack) >= 2)
	{
		first_temp = *stack;
		*stack = (*stack)->next;
		last = ft_lstlast(*stack);
		last->next = first_temp;
		first_temp->next = NULL;
	}
	if (stack2 && lstsize(*stack2) >= 2)
	{
		first_temp = *stack2;
		*stack2 = (*stack2)->next;
		last = ft_lstlast(*stack2);
		last->next = first_temp;
		first_temp->next = NULL;
	}
}

void	revrotate(t_list **stack, t_list **stack2)
{
	t_list	*last;
	t_list	*seclast;

	if (*stack && lstsize(*stack) >= 2)
	{
		last = ft_lstlast(*stack);
		seclast = ft_lstseclast(*stack);
		last->next = *stack;
		*stack = last;
		seclast->next = NULL;
	}
	if (stack2 && lstsize(*stack2) >= 2)
	{
		last = ft_lstlast(*stack2);
		seclast = ft_lstseclast(*stack2);
		last->next = *stack2;
		*stack2 = last;
		seclast->next = NULL;
	}
}
