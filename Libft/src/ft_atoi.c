/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogura <nogura@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:21:36 by nogura            #+#    #+#             */
/*   Updated: 2024/11/24 15:43:34 by nogura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	skip_whitespace(const char **nptr)
{
	while (**nptr == ' ' || **nptr == '\t' || **nptr == '\n' || **nptr == '\v'
		|| **nptr == '\f' || **nptr == '\r')
	{
		(*nptr)++;
	}
}

static int	get_sign(const char **nptr)
{
	int	sign;

	sign = 1;
	if (**nptr == '+')
	{
		(*nptr)++;
	}
	else if (**nptr == '-')
	{
		sign = -1;
		(*nptr)++;
	}
	return (sign);
}

int	ft_atoi(const char *nptr)
{
	long	num;
	int		sign;

	if (!nptr)
		return (0);
	num = 0;
	skip_whitespace(&nptr);
	sign = get_sign(&nptr);
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (num > (LONG_MAX - (*nptr - '0')) / 10)
		{
			if (sign == 1)
				return ((int)LONG_MAX);
			else
				return ((int)LONG_MIN);
		}
		num = 10 * num + (long)(*nptr - '0');
		nptr++;
	}
	return ((int)(num * sign));
}
