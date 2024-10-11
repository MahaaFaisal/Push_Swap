/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 09:09:35 by mafaisal          #+#    #+#             */
/*   Updated: 2024/01/27 17:19:04 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_CHECKER_H
# define PUSH_SWAP_CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include "get_next_line/get_next_line.h"

typedef struct s_list
{
	int				data;
	struct s_list	*next;
	struct s_list	*target;
	int				location;
	int				cost;
}	t_list;

int		main(int ac, char **av);
void	push_args(int ac, char **av, t_list **istack);
int		str_to_int(const char *str, int *error);
t_list	*ft_push(t_list **into, int content);
int		instack(int num, t_list *stack);
t_list	*free_stack(t_list **stack);
int		isalldigit(char *str);
int		is_space(char c);
char	**ft_split(char const *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**free_content(char	**splitted);
int		word_count(const char *s);
int		issorted(t_list *stack);
int		isempty(t_list *stack);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstseclast(t_list *lst);
void	swap_top(t_list **stack);
void	pop_push(t_list **from, t_list **to);
void	rotate(t_list **stack, t_list **stack2);
void	revrotate(t_list **stack, t_list **stack2);
int		lstsize(t_list *stack);
void	free_exit(t_list **istacka, t_list **istackb, char **spl);
#endif
