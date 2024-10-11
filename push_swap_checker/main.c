/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:03:07 by mafaisal          #+#    #+#             */
/*   Updated: 2024/01/27 17:20:42 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1[i] == s2[i] && s1[i] && s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static void	perform_move(char *move, t_list **a, t_list **b)
{
	if (ft_strncmp(move, "sa\n", 4) == 0)
		swap_top(a);
	else if (ft_strncmp(move, "sb\n", 4) == 0)
		swap_top(b);
	else if (ft_strncmp(move, "pa\n", 4) == 0)
		pop_push(b, a);
	else if (ft_strncmp(move, "pb\n", 4) == 0)
		pop_push(a, b);
	else if (ft_strncmp(move, "ra\n", 4) == 0)
		rotate(a, NULL);
	else if (ft_strncmp(move, "rb\n", 4) == 0)
		rotate(b, NULL);
	else if (ft_strncmp(move, "rr\n", 4) == 0)
		rotate(a, b);
	else if (ft_strncmp(move, "rra\n", 5) == 0)
		revrotate(a, NULL);
	else if (ft_strncmp(move, "rrb\n", 5) == 0)
		revrotate(b, NULL);
	else if (ft_strncmp(move, "rrr\n", 5) == 0)
		revrotate(a, b);
	else if (ft_strncmp(move, "ss\n", 4) == 0)
	{
		swap_top(a);
		swap_top(b);
	}
}

static void	parse_move(t_list **a, t_list **b, char *move)
{
	if (ft_strncmp(move, "sa\n", 4) == 0 || ft_strncmp(move, "sb\n", 4) == 0
		||ft_strncmp(move, "pa\n", 4) == 0 || ft_strncmp(move, "pb\n", 4) == 0
		|| ft_strncmp(move, "ra\n", 4) == 0 || ft_strncmp(move, "rb\n", 4) == 0
		||ft_strncmp(move, "rra\n", 5) == 0 || ft_strncmp(move, "rrb\n", 5) == 0
		||ft_strncmp(move, "rr\n", 5) == 0 || ft_strncmp(move, "rrr\n", 5) == 0
		||ft_strncmp(move, "ss\n", 4) == 0)
		perform_move(move, a, b);
	else
	{
		free(move);
		free_exit(a, b, NULL);
	}
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	*next_move;

	a = NULL;
	b = NULL;
	push_args(argc, argv, &a);
	if (argc == 1)
		return (0);
	next_move = get_next_line(0);
	while (next_move)
	{
		parse_move(&a, &b, next_move);
		free(next_move);
		next_move = get_next_line(0);
	}
	free(next_move);
	if (issorted(a) && isempty(b))
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
