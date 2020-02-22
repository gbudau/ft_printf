/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 11:29:41 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/22 09:07:59 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	do_conversion(va_list *ap, t_printf *s, int c, int len)
{
	int				count;
	int				i;
	static int		(*fptr[10])(va_list *, t_printf *, int c) =
	{pf_char, pf_string, pf_point, pf_decimal, pf_decimal, pf_hex,
	pf_hex, pf_uint, pf_percent, pf_count_n};

	count = 0;
	if ((i = ft_strchr_index(PF_CONVERSIONS, c)) != -1)
	{
		if (c == 'n')
			c = len;
		count = fptr[i](ap, s, c);
	}
	return (count);
}

static int	pf_parse_fmt(const char *fmt, va_list *ap)
{
	char		*found;
	t_printf	s;
	int			count;

	count = 0;
	while (*fmt)
	{
		if ((found = ft_strchr(fmt, '%')) == NULL)
			return (count += pf_putstrn(fmt, ft_strlen(fmt)));
		count += pf_putstrn(fmt, found - fmt);
		fmt = ++found;
		if (*fmt)
		{
			fmt += pf_get_optionals(fmt, ap, &s);
			count += do_conversion(ap, &s, *fmt, count);
		}
		if (*fmt)
			fmt++;
	}
	return (count);
}

int			ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, fmt);
	count = pf_parse_fmt(fmt, &ap);
	va_end(ap);
	return (count);
}
