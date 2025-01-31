/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogura <nogura@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 19:37:33 by nogura            #+#    #+#             */
/*   Updated: 2024/12/22 17:11:16 by nogura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *s)
{
	int	ret;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	ret = ft_strlen(s);
	write(1, s, ret);
	return (ret);
}
