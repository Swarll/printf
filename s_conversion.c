/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillaume <Guillaume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:23:30 by grigaux           #+#    #+#             */
/*   Updated: 2020/04/21 19:57:52 by Guillaume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_s_convers5(t_flags *flags, char *conv, char *res, int size)
{
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

char	*ft_s_convers4(t_flags *flags, char *conv, int size)
{
	char *res;

	if (flags->precision < size)
		size = flags->precision;
	if (flags->wide > size)
	{
		if (!(res = malloc(sizeof(char) * flags->wide + 1)))
		{
			ft_free(&conv);
			return (NULL);
		}
		res[flags->wide] = '\0';
	}
	else
	{
		if (!(res = malloc(sizeof(char) * size + 1)))
		{
			ft_free(&conv);
			return (NULL);
		}
		res[size] = '\0';
	}
	return (ft_s_convers5(flags, conv, res, size));
}

char	*ft_s_convers3(t_flags *flags, char *conv, int size)
{
	char *res;

	if (flags->precision > size)
		res = conv;
	else
	{
		size = flags->precision;
		if (!(res = malloc(sizeof(char) * size + 1)))
		{
			ft_free(&conv);
			return (NULL);
		}
		res[size] = '\0';
		res = sp_fill_left(res, conv, size);
		ft_free(&conv);
	}
	return (res);
}

char	*ft_s_convers2(t_flags *flags, char *conv, int size)
{
	char *res;

	if (flags->precision_defined == 0 && flags->wide != 0)
	{
		if (flags->wide == 0 || flags->wide <= size)
			res = conv;
		else
		{
			if (!(res = malloc(sizeof(char) * (flags->wide + 1))))
			{
				ft_free(&conv);
				return (NULL);
			}
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
		return (ft_s_convers3(flags, conv, size));
}

char	*ft_s_convers(char *str, t_flags *flags)
{
	char	*res;
	char	*conv;
	int		size;

	if (!str)
		str = "(null)";
	if (!(conv = ft_strdup(str)))
		return (NULL);
	size = ft_strlen(conv);
	if ((flags->precision_defined == 0 && flags->wide != 0) ||
			(flags->wide == 0 && flags->precision_defined == 1))
	{
		if (!(res = ft_s_convers2(flags, conv, size)))
			return (NULL);
	}
	else if (flags->wide != 0 && flags->precision_defined == 1)
	{
		if (!(res = ft_s_convers4(flags, conv, size)))
			return (NULL);
		ft_free(&conv);
	}
	else
		res = conv;
	return (res);
}
