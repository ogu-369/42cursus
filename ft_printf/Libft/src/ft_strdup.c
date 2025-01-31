/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogura <nogura@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:19:38 by nogura            #+#    #+#             */
/*   Updated: 2024/11/22 21:35:31 by nogura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	slen;
	char	*res;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	res = (char *)malloc(slen + 1);
	if (res == NULL)
		return (NULL);
	ft_memcpy(res, s, slen);
	res[slen] = '\0';
	return (res);
}
