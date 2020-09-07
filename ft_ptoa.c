/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillaume <Guillaume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 17:59:36 by Guillaume         #+#    #+#             */
/*   Updated: 2020/04/21 19:17:56 by Guillaume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ptoa_int_size(unsigned long long n)
{
	int		i;

	i = 1;
	while (n / 16)
	{
		i++;
		n = n / 16;
	}
	return (i);
}

char	*ptoa_call(char *res, unsigned long long a, int size)
{
	char	*base;

	res[size--] = '\0';
	res[0] = '0';
	res[1] = 'x';
	base = ft_strdup("0123456789abcdef");
	while (a > 0)
	{
		res[size] = base[a % 16];
		a = a / 16;
		size--;
	}
	ft_free(&base);
	return (res);
}

char	*ft_ptoa(unsigned long long nbr)
{
	char		*res;
	int			size;

	size = ptoa_int_size(nbr);
	if (!(res = malloc(size * sizeof(char) + 3)))
		return (NULL);
	size += 2;
	ptoa_call(res, nbr, size);
	return (res);
}
