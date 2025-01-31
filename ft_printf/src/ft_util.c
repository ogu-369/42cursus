/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogura <nogura@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:46:53 by nogura            #+#    #+#             */
/*   Updated: 2024/12/23 16:40:25 by nogura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(uintptr_t num, const char *hex)
{
	int	len;

	len = 0;
	if (num >= 16)
		len += ft_puthex(num / 16, hex);
	len += ft_putchar(hex[num % 16]);
	return (len);
}

int	ft_numlen_unsigned(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num /= 10;
		len++;
	}
	return (len);
}
