/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:33:50 by grigaux           #+#    #+#             */
/*   Updated: 2019/10/19 10:37:12 by grigaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int i;
	int size;

	if (s)
	{
		size = ft_strlen((s));
		i = 0;
		while (i < size)
			write(fd, &s[i++], 1);
	}
}
