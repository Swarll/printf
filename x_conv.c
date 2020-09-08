/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <grigaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 11:37:03 by Guillaume         #+#    #+#             */
/*   Updated: 2020/09/08 18:32:42 by grigaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*x_fill_res_left(char *res, char *conv, t_flags *flags, int size)
{
	int i;
	int j;

	j = 0;
	if (flags->precision != 0)
		i = flags->precision - size;
	else
		i = 0;
	if (i < 0)
		i = 0;
	while (conv[j] && res[i])
	{
		if (conv[j] == '-' && (flags->precision != 0
			|| flags->zero_filled == 1))
		{
			j++;
			if (flags->precision < flags->wide && size > flags->precision)
				i++;
		}
		else if (res[i])
			res[i++] = conv[j++];
	}
	return (res);
}

char	*x_fill_with_char(char *res, char c, t_flags *flags)
{
	int i;
	int size;

	i = 0;
	size = flags->wide;
	while (i < size)
		res[i++] = c;
	return (res);
}

char	*x_fill_precision(char *res, int i, int wide, t_flags *flags)
{
	int j;

	if (flags->wide > flags->precision && flags->wide != wide
		&& flags->left_justified == 0)
	{
		wide -= 2;
		while (i < wide)
			res[i++] = '0';
	}
	else if (wide > i && flags->left_justified == 0)
	{
		i = wide - i;
		while (i < wide)
			res[i++] = '0';
	}
	else
	{
		j = 0;
		while (j < i)
			res[j++] = '0';
	}
	return (res);
}

char	*common_x_conv2(t_flags *flags, char *conv)
{
	char *res;

	if ((flags->wide) && (flags->wide > flags->precision))
	{
		if (!(res = malloc(sizeof(char) * (flags->wide + 1))))
			return (ft_free(&conv));
		res[flags->wide] = '\0';
	}
	else
	{
		if (!(res = malloc(sizeof(char) * (flags->precision + 1))))
			return (ft_free(&conv));
		res[flags->precision] = '\0';
	}
	return (res);
}

char	*common_x_conv(t_flags *flags, int size, char *conv)
{
	char *res;

	if (!(res = common_x_conv2(flags, conv)))
		return (NULL);
	if (flags->zero_filled == 1 && (flags->precision == 0
		&& flags->precision_defined == 0))
		res = x_fill_with_char(res, '0', flags);
	else
		res = x_fill_with_char(res, ' ', flags);
	if (!(flags->precision_defined == 1 &&
		flags->precision == 0 && conv[0] == '0'))
	{
		if (flags->precision != 0)
			res = x_fill_precision(res, flags->precision, flags->wide, flags);
		if (flags->left_justified == 1)
			res = x_fill_res_left(res, conv, flags, size);
		else if (flags->wide != 0 && flags->wide > flags->precision)
			res = x_fill_res(res, conv, (flags->wide - size), flags);
		else
			res = x_fill_res(res, conv, (flags->precision - size), flags);
	}
	ft_free(&conv);
	return (res);
}
