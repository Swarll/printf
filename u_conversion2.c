/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_conversion2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillaume <Guillaume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 12:34:07 by Guillaume         #+#    #+#             */
/*   Updated: 2020/04/22 12:36:32 by Guillaume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*u_fill_res(char *res, char *conv, int i, t_flags *flags)
{
	int j;
	int size;

	size = ft_strlen(conv);
	if ((j = 0) && flags->wide > flags->precision && conv[0] == '-')
	{
		if (size < flags->precision)
			res[flags->precision - 1] = conv[j++];
		else if (flags->precision == 0 && flags->wide != 0 &&
			flags->zero_filled == 0)
		{
			res[flags->wide - size] = conv[j++];
			i++;
		}
		else
			res[flags->precision] = conv[j++];
	}
	while (conv[j] && res[i])
		if (conv[j] == '-' && (flags->wide < flags->precision ||
			flags->left_justified == 1 ||
			(flags->zero_filled == 1 && flags->precision == 0)))
			j++;
		else
			res[i++] = conv[j++];
	return (res);
}
