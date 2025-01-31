/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogura <nogura@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:09:35 by nogura            #+#    #+#             */
/*   Updated: 2024/11/22 21:07:59 by nogura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*p_dest;
	const unsigned char	*p_src;

	if (n == 0)
		return (dest);
	if (!dest || !src)
		return (NULL);
	p_dest = (unsigned char *)dest;
	p_src = (const unsigned char *)src;
	while (n--)
	{
		*p_dest++ = *p_src++;
	}
	return (dest);
}
