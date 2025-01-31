/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogura <nogura@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:37:09 by nogura            #+#    #+#             */
/*   Updated: 2024/12/22 17:04:02 by nogura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_formatter(va_list ap, const char *format);

int	ft_printf(const char *format, ...)
{
	int		ret;
	va_list	ap;

	if (!format)
		return (-1);
	ret = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			ret += ft_formatter(ap, format);
		}
		else
			ret += ft_putchar(*format);
		format++;
	}
	va_end(ap);
	return (ret);
}

int	ft_formatter(va_list ap, const char *format)
{
	int	ret;

	ret = 0;
	if (*format == 'c')
		ret += ft_putchar(va_arg(ap, int));
	else if (*format == 's')
		ret += ft_putstr(va_arg(ap, char *));
	else if (*format == 'p')
		ret += ft_putpointer(va_arg(ap, uintptr_t));
	else if (*format == 'd' || *format == 'i')
		ret += ft_putdecimal(va_arg(ap, int));
	else if (*format == 'u')
		ret += ft_putunsigned(va_arg(ap, unsigned int));
	else if (*format == 'x')
		ret += ft_puthex_lower(va_arg(ap, unsigned int));
	else if (*format == 'X')
		ret += ft_puthex_upper(va_arg(ap, unsigned int));
	else if (*format == '%')
		ret += ft_putchar('%');
	return (ret);
}
