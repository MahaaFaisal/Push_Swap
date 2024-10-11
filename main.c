/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:43:21 by mafaisal          #+#    #+#             */
/*   Updated: 2024/01/27 17:19:53 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	push_args(argc, argv, &a);
	if (!issorted(a) && lstsize(a) > 3)
		sort(&a, &b);
	else
		sort_three(&a, 'a');
	free_stack(&a);
	return (0);
}
