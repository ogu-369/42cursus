/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogura <nogura@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:22:43 by nogura            #+#    #+#             */
/*   Updated: 2025/02/07 19:11:07 by nogura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*src = (const unsigned char *)s;

	while (n--)
	{
		if (*src == (unsigned char)c)
			return ((void *)src);
		src++;
	}
	return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dest);
}

char	*create_line(char *stash, size_t len)
{
	char	*line;

	line = malloc(len + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, stash, len);
	line[len] = '\0';
	return (line);
}

char	*update_stash(char *stash, size_t *stash_len, size_t len)
{
	char	*new_stash;
	size_t	new_len;

	new_len = *stash_len - len;
	if (new_len > 0)
	{
		new_stash = malloc(new_len + 1);
		if (!new_stash)
			return (NULL);
		ft_memcpy(new_stash, stash + len, new_len);
		new_stash[new_len] = '\0';
	}
	else
		new_stash = NULL;
	free(stash);
	*stash_len = new_len;
	return (new_stash);
}

char	*shrink_stash(char **stash, size_t *stash_len, size_t len)
{
	char	*line;
	char	*new_stash;

	if (!*stash || *stash_len == 0)
		return (NULL);
	line = create_line(*stash, len);
	if (!line)
	{
		free(*stash);
		*stash = NULL;
		*stash_len = 0;
		return (NULL);
	}
	new_stash = update_stash(*stash, stash_len, len);
	if (!new_stash && *stash_len > 0)
	{
		free(line);
		free(*stash);
		*stash = NULL;
		*stash_len = 0;
		return (NULL);
	}
	*stash = new_stash;
	return (line);
}
