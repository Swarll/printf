/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <grigaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:23:02 by grigaux           #+#    #+#             */
/*   Updated: 2020/09/17 16:32:47 by grigaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_c_convers(char c, t_flags *flags, char ***str)
{
	int count;

	count = 0;
	(void)str;
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
		{
			while (count < flags->wide - 1)
			{
				count += 1;
				write(1, &" ", 1);
			}
			write(1, &c, 1);
			count += 1;
		}
	}
	else
	{
		write(1, &c, 1);
		count += 1;
	}
	return (ft_itoa(count));
}
