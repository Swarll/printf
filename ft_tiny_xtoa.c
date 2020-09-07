/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tiny_xtoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillaume <Guillaume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 17:23:59 by Guillaume         #+#    #+#             */
/*   Updated: 2020/04/21 19:19:08 by Guillaume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		t_xtoa_int_size(unsigned long long n)
{
	int size;

	size = 1;
	while (n / 16)
	{
		size++;
		n /= 16;
	}
	return (size);
}

void	xtoa_rec(char *res, unsigned long long n, int i)
{
	if (n > 15)
	{
		xtoa_rec(res, n / 16, --i);
		if (n % 16 < 10)
			res[i] = (n % 16) + 48;
		else
		{
			res[i] = (n % 16) + 87;
		}
	}
	else
	{
		if (n % 16 < 10)
			res[--i] = n + 48;
		else
		{
			res[--i] = n + 87;
		}
	}
}

char	*ft_tiny_xtoa(unsigned long long nbr)
{
	char		*res;
	int			size;

	size = t_xtoa_int_size(nbr);
	if (!(res = malloc(size * sizeof(char) + 1)))
		return (NULL);
	res[size] = '\0';
	xtoa_rec(res, nbr, size);
	return (res);
}
