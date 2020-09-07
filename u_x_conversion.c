/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_x_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillaume <Guillaume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:22:56 by grigaux           #+#    #+#             */
/*   Updated: 2020/04/21 20:00:58 by Guillaume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		x_size(long long n)
{
	int	size;

	size = 1;
	while (n / 16)
	{
		size++;
		n /= 16;
	}
	return (size);
}

char	*ft_ux_convers(unsigned long long nbr, t_flags *flags)
{
	char		*conv;
	char		*res;
	int			size;

	size = x_size(nbr);
	if (nbr == 0)
	{
		size = 1;
		if (!(conv = ft_strdup("0")))
			return (NULL);
	}
	else if (!(conv = ft_upper_xtoa(nbr)))
		return (NULL);
	if (flags && (flags->wide || flags->precision) &&
		(size < flags->wide || size < flags->precision))
	{
		if (!(res = common_x_conv(flags, size, conv)))
			return (NULL);
	}
	else if (!(flags->precision_defined == 1 &&
		flags->precision == 0) || flags->precision == 0)
		res = conv;
	else
		res = ft_strdup("");
	return (res);
}
