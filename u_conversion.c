/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillaume <Guillaume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:23:34 by grigaux           #+#    #+#             */
/*   Updated: 2020/09/09 11:30:55 by Guillaume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*u_fill_res_left(char *res, char *conv, t_flags *flags, int size)
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
		if (conv[j] == '-' && (flags->precision != 0 ||
			flags->zero_filled == 1))
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

char	*u_fill_precision(char *res, int i, int wide, t_flags *flags)
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

char	*ft_u_convers3(char *res, t_flags *flags, int size, char *conv)
{
	res = iu_fill_with_char(res, flags);
	if (!(flags->precision_defined == 1 &&
		flags->precision == 0 && conv[0] == '0'))
	{
		if (flags->precision != 0)
			res = u_fill_precision(res, flags->precision, flags->wide, flags);
		if (flags->left_justified == 1)
			res = u_fill_res_left(res, conv, flags, size);
		else if (flags->wide != 0 && flags->wide > flags->precision)
			res = u_fill_res(res, conv, (flags->wide - size), flags);
		else
			res = u_fill_res(res, conv, (flags->precision - size), flags);
	}
	ft_free(&conv);
	return (res);
}

char	*ft_u_convers2(t_flags *flags, int size, char *conv)
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
	res = ft_u_convers3(res, flags, size, conv);
	return (res);
}

char	*ft_u_convers(unsigned int nbr, t_flags *flags)
{
	char	*conv;
	char	*res;
	int		size;

	size = iu_size(nbr);
	if (nbr == 0)
	{
		size = 1;
		if (!(conv = ft_strdup("0")))
			return (NULL);
	}
	else if (!(conv = ft_utoa(nbr)))
		return (NULL);
	if (flags && (flags->wide || flags->precision) &&
		(size < flags->wide || size < flags->precision))
	{
		if (!(res = ft_u_convers2(flags, size, conv)))
			return (NULL);
	}
	else if (!(flags->precision_defined == 1 && flags->precision == 0) || (flags
->precision == 0 && (flags->left_justified == 1 || flags->zero_filled == 1)))
		res = conv;
	else
		res = ft_strdup("");
	return (res);
}
