/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 21:09:50 by mafaisal          #+#    #+#             */
/*   Updated: 2024/01/27 16:15:37 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_exit(t_list **istack, char **spl)
{
	if (istack)
		free_stack(istack);
	if (spl)
		free_content(spl);
	write (2, "Error\n", 6);
	exit(1);
}

void	push_args(int ac, char **av, t_list **istack)
{
	int		i;
	int		num_idx;
	int		content;
	char	**nums_in_str;
	int		error;

	i = ac - 1;
	error = 0;
	while (i > 0)
	{
		if (!isalldigit(av[i]))
			free_exit(istack, NULL);
		num_idx = word_count(av[i]) - 1;
		nums_in_str = ft_split(av[i--]);
		if (!nums_in_str || !*nums_in_str)
			free_exit(istack, nums_in_str);
		while (num_idx >= 0)
		{
			content = str_to_int(nums_in_str[num_idx--], &error);
			if (error == 1 || !ft_push(istack, content))
				free_exit(istack, nums_in_str);
		}
		free_content(nums_in_str);
	}
}
