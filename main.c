/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <grigaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 09:22:51 by grigaux           #+#    #+#             */
/*   Updated: 2020/09/17 17:08:08 by grigaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{	int		a = 1;
	int		b = 5;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";
// {
//     printf("PRINTF-   : %*cu5rTiqJP\n", -2, '\0');
//     ft_printf("FT_PRINTF-: %*cu5rTiqJP\n", -2, '\0');
//     printf("PRINTF   : NzgtB%cbsP7zBW0hRKZNo%-10iydBBFhX\n", '\0', -2147483647);
//     ft_printf("FT_PRINTF: NzgtB%cbsP7zBW0hRKZNo%-10iydBBFhX\n", '\0', -2147483647);
//     printf("PRINTF   : 7U3cCB75Qjv%c%0xHGl0i\n", '\0', 0);
//     ft_printf("FT_PRINTF: 7U3cCB75Qjv%c%0xHGl0i\n", '\0', 0);
//     printf("PRINTF   : {%3c}\n", '\0');
//     ft_printf("FT_PRINTF: {%3c}\n", '\0');
//     printf("PRINTF-   : {%-3c}\n", 0);
//     ft_printf("FT_PRINTF-: {%-3c}\n", 0);
//     printf("PRINTF   : {%*c}\n", 0, 0);
//     ft_printf("FT_PRINTF: {%*c}\n", 0, 0);
//     printf("PRINTF   : {%-5c}\n", '\0');
//     ft_printf("FT_PRINTF: {%-5c}\n", '\0');
// printf("PRINTF   :%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c\n", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0);
// ft_printf("FT_PRINTF:%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c\n", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0);    
// // ft_printf("%5%\n");
// // printf("%5%\n");
// printf("{%*c}\n", 0, 0);
// ft_printf("{%*c}\n", 0, 0);
printf(".pr-->|%-16.p|<--\n", NULL);
ft_printf(".ft-->|%-16.p|<--\n", NULL);
printf("pr-->|%-16p|<--\n", NULL);
ft_printf("ft-->|%-16p|<--\n", NULL);
}