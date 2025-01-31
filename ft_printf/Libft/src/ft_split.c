/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogura <nogura@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:43:06 by nogura            #+#    #+#             */
/*   Updated: 2024/11/22 21:34:39 by nogura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	cnt;
	int		in_word;

	cnt = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			cnt++;
		}
		else if (*s == c)
		{
			in_word = 0;
		}
		s++;
	}
	return (cnt);
}

static size_t	get_word_length(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	*mallocpy_word(const char **s, char c)
{
	size_t	len;
	char	*word;
	size_t	i;

	len = get_word_length(*s, c);
	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (**s && **s != c)
		word[i++] = *(*s)++;
	word[i] = '\0';
	return (word);
}

static void	*ft_free(char **s, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;

	if (!s)
		return (NULL);
	res = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			res[i] = mallocpy_word(&s, c);
			if (!res[i])
				return (ft_free(res, i));
			i++;
		}
		else
		{
			s++;
		}
	}
	res[i] = NULL;
	return (res);
}
