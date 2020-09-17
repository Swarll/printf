/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <grigaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:23:15 by grigaux           #+#    #+#             */
/*   Updated: 2020/09/17 17:09:08 by grigaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_p_convers5(t_flags *flags, char *conv, char *res, int size)
{
	if (!ft_strncmp("0x0", conv, 3) && !ft_free(&conv))
	{
		conv = ft_strdup("0x");
		size = ft_strlen(conv);
	}
	if (flags->wide > size)
	{
		res = sp_fill_wide(res, flags);
		if (flags->left_justified == 1)
			res = sp_fill_left(res, conv, size);
		else
			res = sp_fill_right(res, conv, flags, size);
	}
	else
		res = sp_fill_right(res, conv, flags, size);
	return (res);
}

char	*ft_p_convers4(t_flags *flags, char *conv, int size)
{
	char *res;

	if (flags->precision < size && flags->precision_written == 1)
		size = flags->precision;
	if (flags->wide > size)
	{
		if (!(res = malloc(sizeof(char) * flags->wide + 1)))
			return (ft_free(&conv));
		res[flags->wide] = '\0';
	}
	else
	{
		if (!(res = malloc(sizeof(char) * size + 1)))
			return (ft_free(&conv));
		res[size] = '\0';
	}
	return (ft_p_convers5(flags, conv, res, size));
}

char	*ft_p_convers3(t_flags *flags, char *conv, int size)
{
	char *res;

	if (flags->precision > size)
		res = conv;
	// else if (flags->precision == 0 && !ft_strncmp(conv, "0x0", 3))
	// {
	// 	ft_free(&conv);
	// 	res = ft_strdup("0x");
	// }
	else
	{
		if (flags->precision)
			size = flags->precision;
		else
			size = ft_strlen(conv);
		if (!(res = malloc(sizeof(char) * size + 1)))
			return (ft_free(&conv));
		res[size] = '\0';
		res = sp_fill_left(res, conv, size);
		ft_free(&conv);
	}
	return (res);
}

char	*ft_p_convers2(t_flags *flags, char *conv, int size)
{
	char *res;

	if (flags->precision_defined == 0 && flags->wide != 0)
	{
		if (flags->wide == 0 || flags->wide <= size)
			res = conv;
		else
		{
			if (!(res = malloc(sizeof(char) * (flags->wide + 1))))
				return (ft_free(&conv));
			res[flags->wide] = '\0';
			res = sp_fill_wide(res, flags);
			if (flags->left_justified == 1)
				res = sp_fill_left(res, conv, size);
			else
				res = sp_fill_right(res, conv, flags, size);
			ft_free(&conv);
		}
		return (res);
	}
	else
		return (ft_p_convers3(flags, conv, size));
}

char	*ft_p_convers(void *ptr, t_flags *flags)
{
	char				*res;
	char				*conv;
	int					size;
	unsigned long long	nbr;

	nbr = (unsigned long long)ptr;
	if (!(conv = ft_ptoa(nbr)))
		return (NULL);
	if ((size = ft_strlen(conv)) && ((flags->precision_defined == 0 && flags->
	wide != 0) || (flags->wide == 0 && flags->precision_defined == 1)))
	{
		if (!(res = ft_p_convers2(flags, conv, size)))
			return (NULL);
	}
	else if (flags->wide != 0 && flags->precision_defined == 1)
	{
		if (!(res = ft_p_convers4(flags, conv, size)))
			return (NULL);
		ft_free(&conv);
	}
	else
		res = conv;
	return (res);
}
