/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillaume <Guillaume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:23:02 by grigaux           #+#    #+#             */
/*   Updated: 2020/04/21 19:07:01 by Guillaume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*fill_wide(char *res, int i)
{
	int	j;

	j = 0;
	while (j < i)
		res[j++] = ' ';
	return (res);
}

char	*ft_c_convers(int c, t_flags *flags, char ***str)
{
	char	*res;

	if (c == 0)
		**str = NULL;
	if (flags->wide != 0)
	{
		if (!(res = malloc(sizeof(char) * (flags->wide + 1))))
			return (NULL);
		res[flags->wide] = '\0';
		res = fill_wide(res, flags->wide);
		if (flags->wide != 0 && flags->left_justified != 1)
			res[flags->wide - 1] = c;
		else
			res[0] = c;
	}
	else
	{
		if (!(res = malloc(sizeof(char) * (2))))
			return (NULL);
		res[0] = c;
		res[1] = '\0';
	}
	return (res);
}
