/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillaume <Guillaume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:27:17 by grigaux           #+#    #+#             */
/*   Updated: 2020/04/21 19:21:52 by Guillaume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		utoa_int_size(long long n)
{
	int i;

	i = 0;
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

void	utoi_rec(long long n, char *res, int i)
{
	if (n > 9)
	{
		utoi_rec(n / 10, res, --i);
		res[i] = (n % 10) + 48;
	}
	else
		res[--i] = n + 48;
}

char	*ft_utoa(unsigned int nbr)
{
	long long	n;
	char		*res;
	int			size;

	n = nbr;
	size = utoa_int_size(n);
	if (!(res = malloc(sizeof(char) * (size))))
		return (0);
	utoi_rec(n, res, size);
	res[size] = '\0';
	return (res);
}
