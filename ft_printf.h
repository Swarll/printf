/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <grigaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 11:13:08 by grigaux           #+#    #+#             */
/*   Updated: 2020/09/15 10:06:02 by grigaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct	s_flags
{
	int			wide;
	int			left_justified;
	int			zero_filled;
	int			precision;
	int			precision_defined;
	int			precision_star;
	int			precision_written;
}				t_flags;

int				ft_printf(const char *str, ...);
const char		*write_begin(const char *str);
char			*c_handler(va_list vl, const char **str, t_flags *flags);
int				put_str(char **str, int choice);
char			*ft_u_convers(unsigned int nbr, t_flags *flags);
char			*ft_s_convers(char *str, t_flags *flags);
char			*ft_i_convers(int i, t_flags *flags);
char			*ft_c_convers(int c, t_flags *flags, char ***str);
char			*ft_p_convers(void *ptr, t_flags *flags);
char			*ft_tx_convers(unsigned long long nbr, t_flags *flags);
char			*ft_ux_convers(unsigned long long nbr, t_flags *flags);
int				get_numbers(const char **str);
void			initialize_flags(t_flags *flags);
void			*ft_free(char **to_free);
char			*ft_utoa(unsigned int nbr);
char			*ft_tiny_xtoa(unsigned long long nbr);
char			*ft_upper_xtoa(unsigned long long nbr);
char			*ft_ptoa(unsigned long long nbr);
char			*ft_percent_convers(t_flags *flags);
int				x_size(long long n);
int				iu_size(long long nbr);
char			*common_x_conv(t_flags *flags, int size, char *conv);
char			*iu_fill_with_char(char *res, t_flags *flags);
char			*sp_fill_left(char *res, char *conv, int size);
char			*sp_fill_right(char *res, char *conv, t_flags *flags, int size);
char			*sp_fill_wide(char *res, t_flags *flags);
char			*c_handler(va_list vl, const char **str, t_flags *flags);
t_flags			*flags_handler(const char **str, t_flags *flags, va_list vl);
int				calcul_i(t_flags *flags, int size, char *conv);
char			*i_fill_res(char *res, char *conv, t_flags *flags, int size);
char			*u_fill_res(char *res, char *conv, int i, t_flags *flags);
char			*x_fill_res(char *res, char *conv, int i, t_flags *flags);
#endif
