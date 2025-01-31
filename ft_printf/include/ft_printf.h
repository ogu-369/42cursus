/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogura <nogura@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:45:12 by nogura            #+#    #+#             */
/*   Updated: 2024/12/22 17:06:49 by nogura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);

// sub func
int	ft_puthex(uintptr_t num, const char *hex);
int	ft_numlen_unsigned(unsigned int num);

// formatter func
int	ft_putpointer(uintptr_t num);
int	ft_putdecimal(int num);
int	ft_putunsigned(unsigned int num);
int	ft_puthex_lower(unsigned int num);
int	ft_puthex_upper(unsigned int num);

#endif