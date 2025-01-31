/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogura <nogura@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:09:31 by nogura            #+#    #+#             */
/*   Updated: 2024/11/29 17:02:23 by nogura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*res;
	int				len;
	unsigned int	num;

	len = ft_numlen(n);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (n < 0)
		num = -n;
	else
		num = n;
	while (len--)
	{
		res[len] = (num % 10) + '0';
		num /= 10;
		if (len == 0 && n < 0)
			res[len] = '-';
	}
	return (res);
}
