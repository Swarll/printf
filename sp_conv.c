/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <grigaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 14:46:25 by Guillaume         #+#    #+#             */
/*   Updated: 2020/09/17 17:01:01 by grigaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*sp_fill_left(char *res, char *conv, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		res[i] = conv[i];
		i++;
	}
	return (res);
}

char	*sp_fill_right(char *res, char *conv, t_flags *flags, int size)
{
	int i;
	int j;

	i = 0;
	j = flags->wide - size;
	if (j < 0)
		j = 0;
	while (i < size)
		res[j++] = conv[i++];
	return (res);
}

char	*sp_fill_wide(char *res, t_flags *flags)
{
	int i;

	i = 0;
	while (i < flags->wide)
		res[i++] = ' ';
	return (res);
}
