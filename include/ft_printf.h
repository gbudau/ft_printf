/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 11:29:47 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/28 14:55:23 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"
# define PF_FLAG_ZERO 1
# define PF_FLAG_LEFT 2
# define PF_FLAGS "0-"
# define PF_CONVERSIONS "cspdixXu%n"
# define PF_SPACE_FILL "        "
# define PF_ZERO_FILL "00000000"
# define PF_FILL_SIZE 8

typedef struct		s_printf
{
	unsigned int	flags;
	int				prec;
	int				width;
}					t_printf;

int					ft_printf(const char *fmt, ...);
int					pf_char(va_list *ap, t_printf *s, int count);
int					pf_string(va_list *ap, t_printf *s, int count);
int					pf_point(va_list *ap, t_printf *s, int count);
int					pf_decimal(va_list *ap, t_printf *s, int count);
int					pf_hex(va_list *ap, t_printf *s, int letter);
int					pf_uint(va_list *ap, t_printf *s, int count);
int					pf_percent(va_list *ap, t_printf *s, int count);
int					pf_count_n(va_list *ap, t_printf *s, int count);
int					pf_get_optionals(const char *fmt, va_list *ap, t_printf *s);
int					pf_ltoa_base_len(long n, char *buffer, int base, int ch);
int					pf_put_zero(int len);
int					pf_put_space(int len);
int					pf_put_zero_or_space(t_printf *s, int len);
size_t				pf_putstrn(const char *str, int len);
size_t				pf_putchar(char c);

#endif
