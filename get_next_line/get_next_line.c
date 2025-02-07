/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogura <nogura@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:22:21 by nogura            #+#    #+#             */
/*   Updated: 2025/02/07 19:39:58 by nogura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char **stash, size_t *stash_len);
static int	append_to_stash(int fd, char **stash, size_t *stash_len);
static char	*expand_stash(char *stash, size_t *stash_len, char *buf,
				ssize_t bytes);

char	*get_next_line(int fd)
{
	static char		*stash = NULL;
	static size_t	stash_len = 0;
	int				result;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (stash)
		{
			free(stash);
			stash = NULL;
		}
		stash_len = 0;
		return (NULL);
	}
	result = append_to_stash(fd, &stash, &stash_len);
	if (result < 0)
	{
		free(stash);
		stash = NULL;
		stash_len = 0;
		return (NULL);
	}
	return (extract_line(&stash, &stash_len));
}

static int	append_to_stash(int fd, char **stash, size_t *stash_len)
{
	char	*buf;
	ssize_t	bytes;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	bytes = read(fd, buf, BUFFER_SIZE);
	while (bytes > 0)
	{
		buf[bytes] = '\0';
		*stash = expand_stash(*stash, stash_len, buf, bytes);
		if (!*stash)
		{
			free(buf);
			return (-1);
		}
		if (ft_memchr(buf, '\n', bytes) != NULL)
			break ;
		bytes = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	if (bytes < 0 || (bytes == 0 && *stash_len == 0))
		return (-1);
	return (0);
}

static char	*expand_stash(char *stash, size_t *stash_len, char *buf,
		ssize_t bytes)
{
	size_t	new_size;
	char	*new_ptr;

	if (*stash_len == 0)
		new_size = (size_t)(bytes + 1);
	else
		new_size = *stash_len + (size_t)bytes + 1;
	new_ptr = malloc(new_size);
	if (!new_ptr)
	{
		free(stash);
		return (NULL);
	}
	if (stash)
		ft_memcpy(new_ptr, stash, *stash_len);
	ft_memcpy(new_ptr + *stash_len, buf, bytes);
	new_ptr[*stash_len + bytes] = '\0';
	free(stash);
	*stash_len += bytes;
	return (new_ptr);
}

static char	*extract_line(char **stash, size_t *stash_len)
{
	size_t	i;
	char	*line;

	if (!*stash || *stash_len == 0)
		return (NULL);
	i = 0;
	while (i < *stash_len && (*stash)[i] != '\n')
		i++;
	if (i < *stash_len)
		i++;
	line = shrink_stash(stash, stash_len, i);
	return (line);
}
