/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogura <nogura@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:22:13 by nogura            #+#    #+#             */
/*   Updated: 2025/01/31 22:51:57 by nogura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*shrink_stash(char **stash, size_t *stash_len, size_t i);
char	*create_line(char *stash, size_t len);
char	*update_stash(char *stash, size_t *stash_len, size_t len);

#endif
