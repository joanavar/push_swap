/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 12:30:44 by joanavar          #+#    #+#             */
/*   Updated: 2024/06/15 12:39:50 by joanavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

static int	count_words(char *str, char c)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*str)
	{
		inside_word = false;
		while (*str == c)
			str++;
		while (*str != c && *str)
		{
			if (!inside_word)
			{
				count++;
				inside_word = true;
			}
			str++;
		}
	}
	return (count);
}

static char	*get_next_word(char *str, char c)
{
	static int	cursor;
	char		*next_word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (str[cursor] == c)
		cursor++;
	while (str[cursor + len] != c && str[cursor + len])
		len++;
	next_word = malloc(sizeof(char) * len + 1);
	if (!next_word)
		return (NULL);
	while (str[cursor] != c && str[cursor])
		next_word[i++] = str[cursor++];
	next_word[i++] = '\0';
	return (next_word);
}

char	**split(char *str, char c)
{
	int		word_count;
	char	**result_array;
	int		i;

	i = 0;
	word_count = count_words(str, c);
	if (!word_count)
		exit(1);
	result_array = malloc(sizeof(char *) * (word_count + 2));
	if (!result_array)
		return (NULL);
	while (word_count-- >= 0)
	{
		if (i == 0)
		{
			result_array[i] = malloc(sizeof(char));
			if (!result_array[i])
				return (NULL);
			result_array[i++][0] = '\0';
			continue ;
		}
		result_array[i++] = get_next_word(str, c);
	}
	result_array[i] = NULL;
	return (result_array);
}
