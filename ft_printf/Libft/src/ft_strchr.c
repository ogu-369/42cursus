/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogura <nogura@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:39:41 by nogura            #+#    #+#             */
/*   Updated: 2024/11/22 21:43:52 by nogura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const unsigned char	*str;
	unsigned char		chr;

	if (!s)
		return (NULL);
	str = (const unsigned char *)s;
	chr = (unsigned char)c;
	while (*str != '\0')
	{
		if (*str == chr)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (NULL);
}
