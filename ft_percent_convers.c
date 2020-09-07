/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_convers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillaume <Guillaume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 10:01:45 by Guillaume         #+#    #+#             */
/*   Updated: 2020/04/21 18:55:17 by Guillaume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*put_percent(t_flags *flags, char *res)
{
	if (flags->left_justified)
		res[0] = '%';
	else
		res[flags->wide - 1] = '%';
	return (res);
}

char	*fill_result(t_flags *flags, char *res, char c)
{
	int	i;

	i = 0;
	while (i < flags->wide)
		res[i++] = c;
	return (res);
}

char	*ft_percent_convers(t_flags *flags)
{
	char	*res;

	if (flags->wide != 0)
	{
		if (!(res = malloc(sizeof(char) * (flags->wide + 1))))
			return (NULL);
		res[flags->wide] = '\0';
		if (flags->zero_filled == 1 && flags->left_justified == 0)
			res = fill_result(flags, res, '0');
		else
			res = fill_result(flags, res, ' ');
		res = put_percent(flags, res);
	}
	else if (!(res = ft_strdup("%")))
		return (NULL);
	return (res);
}
