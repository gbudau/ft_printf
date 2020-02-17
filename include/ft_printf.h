/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 01:29:47 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/17 09:00:02 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"
# define F_ZERO 1
# define F_MINUS 2

typedef struct s_pf
{
	unsigned int	flags;
	int		prec;
	int		width;
}	t_printf;

int	ft_printf(const char *fmt, ...);
int	pf_char(va_list *ap, t_printf *list);
int	pf_string(va_list *ap, t_printf *list);
int	pf_point(va_list *ap, t_printf *s);
int	pf_decimal(va_list *ap, t_printf *list);
int	pf_hex(va_list *ap, t_printf *out);
int	pf_hex_upper(va_list *ap, t_printf *s);
int	pf_uint(va_list *ap, t_printf *s);
int	pf_get_optionals(const char *str, va_list *ap, t_printf *list);
int	pf_put_zero(int len);
int	pf_put_space(int len);
int	pf_put_zero_or_space(t_printf *list, int len);
size_t	pf_putstrn(const char *s, int len);
size_t	pf_putchar(char c);

#endif
