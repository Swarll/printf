/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_conversion2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillaume <Guillaume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 12:30:58 by Guillaume         #+#    #+#             */
/*   Updated: 2020/04/22 12:36:36 by Guillaume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		calcul_i(t_flags *flags, int size, char *conv)
{
	int neg;

	neg = 0;
	if (conv[0] == '-')
		neg = 1;
	if (flags->wide != 0 && flags->wide > flags->precision)
		return (flags->wide - size + neg);
	else
		return (flags->precision - size + (2 * neg));
}

char	*i_fill_res(char *res, char *conv, t_flags *flags, int size)
{
	int j;
	int i;

	j = 0;
	i = calcul_i(flags, size, conv);
	if (flags->wide > flags->precision && conv[0] == '-'
		&& flags->precision_defined == 1)
	{
		if (size <= flags->precision && !(flags->precision == 0 &&
		flags->wide != 0 && flags->zero_filled == 0 && (i += 1)))
			res[flags->wide - flags->precision - 1] = conv[j++];
		else
			res[flags->wide - size] = conv[j++];
	}
	while (conv[j])
		if (conv[j] == '-' && (flags->wide <= flags->precision ||
			flags->left_justified == 1 ||
			(flags->zero_filled == 1 && flags->precision == 0)))
			j++;
		else
			res[i++] = conv[j++];
	return (res);
}
