/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <grigaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:23:02 by grigaux           #+#    #+#             */
/*   Updated: 2020/09/17 17:41:04 by grigaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_c_convers2(t_flags *flags, char c)
{
	int	count;

	count = 0;
	while (count < flags->wide - 1)
	{
		count += 1;
		write(1, &" ", 1);
	}
	write(1, &c, 1);
	count += 1;
	return (count);
}

char	*ft_c_convers(char c, t_flags *flags)
{
	int count;

	count = 0;
	if (flags->wide != 0)
	{
		if (flags->left_justified)
		{
			count += 1;
			write(1, &c, 1);
			while (count < flags->wide)
			{
				write(1, &" ", 1);
				count += 1;
			}
		}
		else
			count += ft_c_convers2(flags, c);
	}
	else
	{
		write(1, &c, 1);
		count += 1;
	}
	return (ft_itoa(count));
}
