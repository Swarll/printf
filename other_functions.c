/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <grigaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:53:41 by grigaux           #+#    #+#             */
/*   Updated: 2020/09/15 10:59:46 by grigaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		put_str(char **str, int choice)
{
	int count;

	count = 0;
	while (choice == 0 && **str && **str != '%')
	{
		write(1, &**str, 1);
		++*str;
		count++;
	}
	while (choice == 1 && **str)
	{
		write(1, &**str, 1);
		++*str;
		count++;
	}
	if (choice == 1 && ++**str)
	{
		count = put_str(str, choice);
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
}
