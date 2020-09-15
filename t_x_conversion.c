/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_x_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <grigaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:22:51 by grigaux           #+#    #+#             */
/*   Updated: 2020/09/15 10:11:52 by grigaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_tx_convers(unsigned long long nbr, t_flags *flags)
{
	char	*conv;
	char	*res;
	int		size;

	size = x_size(nbr);
	if (nbr == 0)
	{
		size = 1;
		if (!(conv = ft_strdup("0")))
			return (NULL);
	}
	else if (!(conv = ft_tiny_xtoa(nbr)))
		return (NULL);
	if (flags && (flags->wide || flags->precision) &&
		(size < flags->wide || size < flags->precision))
	{
		if (!(res = common_x_conv(flags, size, conv)))
			return (NULL);
	}
	else if ((flags->precision_defined == 0 || flags->precision != 0 || (flags->precision_star == 1 && conv[0] != '0')) || (flags
->precision == 0 && (flags->left_justified == 1 || flags->zero_filled == 1 || flags->precision_written == 1) && conv[0] != '0'))
		res = conv;
	else
		res = ft_strdup("");
	return (res);
}
