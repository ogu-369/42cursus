/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogura <nogura@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:02:38 by nogura            #+#    #+#             */
/*   Updated: 2024/11/22 22:27:58 by nogura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	nl;

	if (!s)
		return ;
	nl = '\n';
	ft_putstr_fd(s, fd);
	write(fd, &nl, 1);
}
