/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillaume <Guillaume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 15:48:39 by Guillaume         #+#    #+#             */
/*   Updated: 2020/04/21 19:01:36 by Guillaume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_c_handler3(va_list vl, const char **str, t_flags *flags)
{
	if (*str && **str && **str == 'x' && ++*str)
	{
		if (flags->precision_star == 1 && flags->precision < 0
			&& flags->precision_defined == 1)
		{
			flags->precision_defined = 0;
			flags->precision = 0;
		}
		return (ft_tx_convers(va_arg(vl, unsigned int), flags));
	}
	else if (*str && **str && **str == 'X' && ++*str)
	{
		if (flags->precision_star == 1 && flags->precision < 0
			&& flags->precision_defined == 1)
		{
			flags->precision_defined = 0;
			flags->precision = 0;
		}
		return (ft_ux_convers(va_arg(vl, unsigned int), flags));
	}
	else if (*str && **str && **str == '%' && ++*str)
		return (ft_percent_convers(flags));
	else
		return (NULL);
}

char	*ft_c_handler2(va_list vl, const char **str, t_flags *flags)
{
	if (*str && **str && (**str == 'd' || **str == 'i') && ++*str)
	{
		if (flags->precision_star == 1 && flags->precision < 0
			&& flags->precision_defined == 1)
		{
			flags->precision_defined = 0;
			flags->precision = 0;
		}
		return (ft_i_convers(va_arg(vl, int), flags));
	}
	else if (*str && **str && **str == 'u' && ++*str)
	{
		if (flags->precision_star == 1 && flags->precision < 0
			&& flags->precision_defined == 1)
		{
			flags->precision_defined = 0;
			flags->precision = 0;
		}
		return (ft_u_convers(va_arg(vl, unsigned int), flags));
	}
	else
		return (ft_c_handler3(vl, str, flags));
}

char	*c_handler(va_list vl, const char **str, t_flags *flags)
{
	if (*str && **str && **str == 'c' && ++*str)
		return (ft_c_convers(va_arg(vl, int), flags, (char ***)&str));
	else if (*str && **str && **str == 's' && ++*str)
	{
		if (flags->precision_star == 1 && flags->precision < 0
			&& flags->precision_defined == 1)
		{
			if (flags->precision < 0)
				flags->precision_defined = 0;
			flags->precision = 0;
		}
		return (ft_s_convers(va_arg(vl, char *), flags));
	}
	else if (*str && **str && **str == 'p' && ++*str)
		return (ft_p_convers((void *)va_arg(vl, unsigned long long), flags));
	else
		return (ft_c_handler2(vl, str, flags));
}
