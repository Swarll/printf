/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <grigaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 17:02:00 by Guillaume         #+#    #+#             */
/*   Updated: 2020/09/17 16:35:24 by grigaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf2(t_flags *flags, const char *str, va_list vl)
{
	char	*res;
	char	*res_cpy;
	int		count;

	count = 0;
	while (str && *str)
	{
		initialize_flags(flags);
		if (*str)
			count += put_str((char **)&str, 0);
		if (*str)
			++str;
		if (*str)
			flags_handler(&str, flags, vl);
		if (*str)
		{
			if (*str == 'c')
				flags->count = 1;
			if ((res = c_handler(vl, &str, flags)))
			{
				if (flags->count == 0) 
				{
					res_cpy = res;
					count += put_str(&res, 1);
					ft_free(&res_cpy);
				}
				else 
				{
					count += ft_atoi(res);
					ft_free(&res);
				}
			}
		}
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list		vl;
	t_flags		*flags;
	int			count;

	if (!(flags = malloc(sizeof(int) * 8)))
		return (0);
	va_start(vl, str);
	count = ft_printf2(flags, str, vl);
	va_end(vl);
	free(flags);
	flags = NULL;
	return (count);
}
