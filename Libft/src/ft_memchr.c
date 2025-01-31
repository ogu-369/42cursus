/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogura <nogura@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:50:17 by nogura            #+#    #+#             */
/*   Updated: 2024/11/22 21:31:13 by nogura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*src;
	unsigned char		chr;

	if (!s)
		return (NULL);
	src = (const unsigned char *)s;
	chr = (unsigned char)c;
	while (n > 0)
	{
		if (*src == chr)
			return ((void *)src);
		src++;
		n--;
	}
	return (NULL);
}
