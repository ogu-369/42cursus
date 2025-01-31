/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogura <nogura@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:03:48 by nogura            #+#    #+#             */
/*   Updated: 2024/11/22 21:40:59 by nogura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (c == '\0')
		return ((char *)(s + slen));
	while (slen >= 0)
	{
		if (s[slen] == (char)c)
			return ((char *)(s + slen));
		slen--;
	}
	return (NULL);
}
