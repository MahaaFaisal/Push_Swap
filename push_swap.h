/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:38:04 by mafaisal          #+#    #+#             */
/*   Updated: 2024/01/27 17:20:07 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"

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
int		isalldigit(char *str);
int		is_space(char c);
int		str_to_int(const char *str, int *error);
t_list	*ft_push(t_list **into, int content);
int		word_count(const char *s);
char	**ft_split(char const *s);
int		instack(int num, t_list *stack);
void	free_exit(t_list **istack, char **spl);
char	**free_content(char	**splitted);
t_list	*free_stack(t_list **stack);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		issorted(t_list *stack);
int		isempty(t_list *stack);
int		lstsize(t_list *stack);
void	sort_three(t_list **a, char c);
void	sort(t_list **a, t_list **b);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstseclast(t_list *lst);
void	swap_top(t_list **stack, char c);
void	pop_push(t_list **from, t_list **to, char c);
void	rotate(t_list **stack, t_list **stack2, char c);
void	revrotate(t_list **stack, t_list **stack2, char c);
t_list	*get_min(t_list *stack);
t_list	*get_max(t_list *stack);
void	update_stacks(t_list **stack1, t_list **stack2);
void	update_target(t_list **stackb, t_list **stacka);
void	cheap_to_top(t_list **a, t_list **b);
#endif
