/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogura <nogura@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:22:43 by nogura            #+#    #+#             */
/*   Updated: 2025/01/31 22:52:52 by nogura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*src = (const unsigned char *)s;
	unsigned char		uc;

	uc = (unsigned char)c;
	while (n >= sizeof(size_t))
	{
		if (*(const size_t *)src & uc)
			break ;
		src += sizeof(size_t);
		n -= sizeof(size_t);
	}
	while (n--)
	{
		if (*src == uc)
			return ((void *)src);
		src++;
	}
	return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				*i_dest;
	const size_t		*i_src;
	unsigned char		*c_dest;
	const unsigned char	*c_src;

	i_dest = (size_t *)dest;
	i_src = (const size_t *)src;
	while (n >= sizeof(size_t))
	{
		*i_dest++ = *i_src++;
		n -= sizeof(size_t);
	}
	c_dest = (unsigned char *)i_dest;
	c_src = (const unsigned char *)i_src;
	while (n--)
		*c_dest++ = *c_src++;
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
