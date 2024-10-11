/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:02:16 by mafaisal          #+#    #+#             */
/*   Updated: 2024/01/10 08:48:25 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**free_content(char	**splitted)
{
	int	k;

	k = 0;
	while (splitted[k])
	{
		free(splitted[k]);
		splitted[k] = NULL;
		k++;
	}
	free(splitted);
	splitted = NULL;
	return (NULL);
}

int	word_count(const char *s)
{
	unsigned int	count;
	unsigned int	i;

	count = 0;
	i = 0;
	while (*(s + i))
	{
		if ((is_space(*(s + i))
				&& !is_space(*(s + i + 1)) && *(s + i + 1) != '\0')
			|| (!is_space(*(s + i)) && i == 0))
		{
			count++;
		}
		i++;
	}
	return (count);
}

char	**ft_split(char const *s)
{
	char			**splitted;
	unsigned int	beg;
	unsigned int	end;
	int				idx;

	if (!s)
		return (NULL);
	splitted = malloc(sizeof(char *) * (word_count(s) + 1));
	if (!splitted)
		return (NULL);
	beg = 0;
	idx = 0;
	while (s[beg] != '\0' && idx < word_count(s))
	{
		while (s[beg] && is_space(s[beg]))
			beg++;
		end = beg;
		while (s[end] && !is_space(s[end]))
			end++;
		splitted[idx] = ft_substr(s, beg, end - beg);
		if (splitted[idx++] == NULL)
			return (free_content(splitted), NULL);
		beg = end;
	}
	return (splitted[idx] = NULL, splitted);
}
