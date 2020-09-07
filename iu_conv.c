/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iu_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillaume <Guillaume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 12:07:04 by Guillaume         #+#    #+#             */
/*   Updated: 2020/04/22 12:30:05 by Guillaume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		iu_size(long long n)
{
	int size;

	size = 0;
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	while (n > 9)
	{
		size++;
		n /= 10;
	}
	return (size + 1);
}

char	*iu_fill_with_char(char *res, t_flags *flags)
{
	int		i;
	int		size;
	char	c;

	if (flags->zero_filled == 1 && flags->precision_defined == 0)
		c = '0';
	else
		c = ' ';
	i = 0;
	size = flags->wide;
	while (i < size)
		res[i++] = c;
	return (res);
}
