/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:43:34 by mafaisal          #+#    #+#             */
/*   Updated: 2024/01/25 13:58:13 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_push(t_list	**into, int data)
{
	t_list	*node;

	if (instack(data, *into))
		return (NULL);
	node = malloc (sizeof(t_list));
	if (!node)
		return (free_stack(into));
	node -> data = data;
	node -> next = NULL;
	if (*into)
	{
		node -> next = *into;
	}
	*into = node;
	return (*into);
}

t_list	*free_stack(t_list **stack)
{
	t_list	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free (temp);
	}
	return (NULL);
}

int	lstsize(t_list *stack)
{
	int		count;
	t_list	*loop;

	if (!stack)
		return (0);
	loop = stack;
	count = 0;
	while (loop)
	{
		count++;
		loop = loop->next;
	}
	return (count);
}
