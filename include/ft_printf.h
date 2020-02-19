/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 11:29:47 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/19 11:58:06 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"
# define F_ZERO 1
# define F_MINUS 2
# define PF_FLAGS "0-"
# define CONVERSIONS "cspdixXu"

typedef struct s_pf
{
	unsigned int	flags;
	int		prec;
	int		width;
}	t_printf;

int	ft_printf(const char *fmt, ...);
int	pf_char(va_list *ap, t_printf *var, int count);
int	pf_string(va_list *ap, t_printf *var, int count);
int	pf_point(va_list *ap, t_printf *s, int count);
int	pf_decimal(va_list *ap, t_printf *var, int count);
int	pf_hex(va_list *ap, t_printf *out, int letter);
int	pf_uint(va_list *ap, t_printf *s, int count);
int	pf_get_optionals(const char *str, va_list *ap, t_printf *var);
int	pf_ltoa_base_len(long n, char buffer[], int base, int c);
int	pf_ultoa_base_len(unsigned long u, char buffer[], int base, int c);
int	pf_put_zero(int len);
int	pf_put_space(int len);
int	pf_put_zero_or_space(t_printf *var, int len);
size_t	pf_putstrn(const char *s, int len);
size_t	pf_putchar(char c);

#endif
