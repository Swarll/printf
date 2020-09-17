/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <grigaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:53:41 by grigaux           #+#    #+#             */
/*   Updated: 2020/09/17 17:23:43 by grigaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		put_str(char **str, int choice)
{
	int count;

	count = 0;
	while (choice == 0 && *str && **str && **str != '%')
	{
		write(1, &**str, 1);
		++*str;
		count++;
	}
	while (choice == 1 && *str && **str)
	{
		write(1, &**str, 1);
		++*str;
		count++;
	}
	return (count);
}

int		get_numbers(const char **str)
{
	int res;

	res = 0;
	while (**str && **str >= '0' && **str <= '9')
	{
		res *= 10;
		res += **str - 48;
		++*str;
	}
	return (res);
}

void	*ft_free(char **to_free)
{
	free(*to_free);
	*to_free = NULL;
	return (NULL);
}

void	initialize_flags(t_flags *flags)
{
	flags->wide = 0;
	flags->left_justified = 0;
	flags->zero_filled = 0;
	flags->precision = 0;
	flags->precision_defined = 0;
	flags->precision_star = 0;
	flags->precision_written = 0;
	flags->count = 0;
}

char	*other_conv(t_flags *flags, char *conv)
{
	char	*res;

	if (conv[0] == '0' && flags->precision_defined == 1)
	{
		ft_free(&conv);
		res = ft_strdup("");
	}
	else
		res = conv;
	return (res);
}
