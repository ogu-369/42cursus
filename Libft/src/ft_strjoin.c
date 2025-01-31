/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogura <nogura@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:29:04 by nogura            #+#    #+#             */
/*   Updated: 2024/11/24 16:04:10 by nogura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dst, const char *src)
{
	char	*dst_ptr;

	dst_ptr = dst;
	while (*src)
	{
		*dst_ptr++ = *src++;
	}
	*dst_ptr = '\0';
	return (dst);
}

static char	*ft_strcat(char *dst, const char *src)
{
	char	*dst_ptr;

	dst_ptr = dst;
	while (*dst_ptr)
	{
		dst_ptr++;
	}
	while (*src)
	{
		*dst_ptr++ = *src++;
	}
	*dst_ptr = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	len1;
	size_t	len2;
	size_t	total_len;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 > SIZE_MAX - len2 - 1)
		return (NULL);
	total_len = len1 + len2 + 1;
	dst = (char *)malloc(total_len);
	if (!dst)
		return (NULL);
	ft_strcpy(dst, s1);
	ft_strcat(dst, s2);
	return (dst);
}
