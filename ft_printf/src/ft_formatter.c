/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogura <nogura@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:52:01 by nogura            #+#    #+#             */
/*   Updated: 2024/12/23 16:42:45 by nogura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer(uintptr_t num)
{
	int			ret;
	const char	*hex;

	if (!num)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	hex = "0123456789abcdef";
	ret = 0;
	ret += ft_putstr("0x");
	ret += ft_puthex(num, hex);
	return (ret);
}

int	ft_putdecimal(int num)
{
	char	*n_str;

	n_str = ft_itoa(num);
	ft_putstr(n_str);
	free(n_str);
	return (ft_numlen(num));
}

int	ft_putunsigned(unsigned int num)
{
	int		ret;
	int		i;
	char	*n_str;

	ret = ft_numlen_unsigned(num);
	n_str = (char *)malloc((ret + 1) * sizeof(char));
	if (!n_str)
		return (-1);
	n_str[ret] = '\0';
	i = ret - 1;
	while (i >= 0)
	{
		n_str[i] = (num % 10) + '0';
		num /= 10;
		i--;
	}
	ft_putstr(n_str);
	free(n_str);
	return (ret);
}

int	ft_puthex_lower(unsigned int num)
{
	int			ret;
	const char	*hex;

	hex = "0123456789abcdef";
	ret = ft_puthex((uintptr_t)num, hex);
	return (ret);
}

int	ft_puthex_upper(unsigned int num)
{
	int			ret;
	const char	*hex;

	hex = "0123456789ABCDEF";
	ret = ft_puthex((uintptr_t)num, hex);
	return (ret);
}
