/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:49:52 by mafaisal          #+#    #+#             */
/*   Updated: 2024/01/27 10:54:17 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

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
