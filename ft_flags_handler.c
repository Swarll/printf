/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillaume <Guillaume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 16:05:23 by Guillaume         #+#    #+#             */
/*   Updated: 2020/04/21 18:58:25 by Guillaume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	*flags_handler4(const char **str, t_flags *flags, va_list vl)
{
	if (*str && ((**str >= '1' && **str <= '9') ||
		(**str == '*' && !(flags->wide))))
	{
		if (**str == '*')
		{
			flags->wide = va_arg(vl, int);
			if (flags->wide < 0)
			{
				flags->wide *= -1;
				flags->left_justified = 1;
			}
			++*str;
		}
		else
			flags->wide = get_numbers(&*str);
	}
	return (flags);
}

t_flags	*flags_handler3(const char **str, t_flags *flags, va_list vl)
{
	if (*str && **str == '.')
	{
		flags->precision_defined = 1;
		if (*++*str == '*')
		{
			flags->precision = va_arg(vl, int);
			flags->precision_star = 1;
			++*str;
		}
		else
			flags->precision = get_numbers(&*str);
		if (!flags->precision)
			flags->precision = 0;
	}
	return (flags_handler4(str, flags, vl));
}

t_flags	*flags_handler2(const char **str, t_flags *flags, va_list vl)
{
	if (*str && ((**str >= '1' && **str <= '9') ||
		(**str == '*' && !(flags->wide))))
	{
		if (**str == '*')
		{
			flags->wide = va_arg(vl, int);
			if (flags->wide < 0)
			{
				flags->wide *= -1;
				flags->left_justified = 1;
				flags->zero_filled = 0;
			}
			++*str;
		}
		else
			flags->wide = get_numbers(&*str);
	}
	return (flags_handler3(str, flags, vl));
}

t_flags	*flags_handler(const char **str, t_flags *flags, va_list vl)
{
	while (*str && **str == '-')
	{
		flags->left_justified = 1;
		++*str;
	}
	while (*str && **str == '0')
	{
		flags->zero_filled = 1;
		++*str;
	}
	return (flags_handler2(str, flags, vl));
}
