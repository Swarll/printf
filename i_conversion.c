/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillaume <Guillaume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:50:33 by grigaux           #+#    #+#             */
/*   Updated: 2020/09/09 11:34:09 by Guillaume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*i_fill_res_left(char *res, char *conv, t_flags *flags, int size)
{
	int i;
	int j;
	int neg;

	if (conv[0] == '-')
		neg = 1;
	j = 0;
	if (flags->precision != 0)
		i = flags->precision - size + (neg * 2);
	else
		i = 0;
	if (i < 0)
		i = 0;
	while (conv[j])
		if (conv[j] == '-' && (flags->precision != 0
			|| flags->zero_filled == 1))
		{
			j++;
			if (res[i] == '-')
				i++;
		}
		else
			res[i++] = conv[j++];
	return (res);
}

char	*i_fill_precision(char *res, int i, int neg, t_flags *flags)
{
	int j;
	int wide;

	wide = flags->wide + neg;
	if (flags->wide > flags->precision && flags->wide !=
		wide && flags->left_justified == 0)
	{
		i = flags->wide - i - neg;
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

char	*ft_i_convers3(char *res, t_flags *flags, int size, char *conv)
{
	int neg;

	neg = conv[0] == '-' ? 1 : 0;
	res = iu_fill_with_char(res, flags);
	if (!(flags->precision_defined == 1 && flags->precision == 0
		&& conv[0] == '0'))
	{
		if (flags->precision != 0)
			res = i_fill_precision(res, flags->precision, neg, flags);
		if (neg == 1 && (flags->wide <= flags->precision ||
			flags->left_justified == 1 ||
			(flags->zero_filled == 1 && flags->precision_defined == 0)))
			res[0] = '-';
		if (flags->left_justified == 1)
			res = i_fill_res_left(res, conv, flags, size);
		else
			res = i_fill_res(res, conv, flags, size);
	}
	return (res);
}

char	*ft_i_convers2(char *conv, t_flags *flags, int neg)
{
	char *res;

	if (conv && conv[0] == '-' && (flags->precision != 0
		|| flags->zero_filled == 1))
		neg = 1;
	if ((flags->wide) && (flags->wide > flags->precision))
	{
		if (!(res = malloc(sizeof(char) * (flags->wide) + 1)))
			return (ft_free(&conv));
		res[flags->wide] = '\0';
	}
	else
	{
		if (!(res = malloc(sizeof(char) * (flags->precision + neg) + 1)))
			return (ft_free(&conv));
		res[flags->precision + neg] = '\0';
	}
	return (res);
}

char	*ft_i_convers(int i, t_flags *flags)
{
	char	*conv;
	char	*res;
	int		size;
	int		neg;

	if (!(conv = ft_itoa(i)))
		return (NULL);
	size = iu_size(i);
	neg = 0;
	if (flags && (flags->wide || flags->precision) &&
		(size <= flags->wide || size <= flags->precision))
	{
		if (!(res = ft_i_convers2(conv, flags, neg)))
			return (NULL);
		res = ft_i_convers3(res, flags, size, conv);
		ft_free(&conv);
	}
	else if (!(flags->precision_defined == 1 && flags->precision == 0) || (flags
->precision == 0 && (flags->left_justified == 1 || flags->zero_filled == 1)))
		res = conv;
	else
		res = ft_strdup("");
	return (res);
}
