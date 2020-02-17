/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 01:29:41 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/17 12:55:07 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	pf_do_conversion(int c, va_list *ap, t_printf *var)
{
	int			count;
	int			i;
	static int		(*fptr[8])(va_list *, t_printf *) = 
	{pf_char, pf_string, pf_point, pf_decimal, pf_decimal, pf_hex, 
	pf_hex_upper, pf_uint};
	static const char	conversions[9] = 
	{'c', 's','p', 'd', 'i', 'x', 'X', 'u', '\0'};

	if (c == '%')
		return (pf_putchar(c));
	count = 0;
	if ((i = ft_strchr_index(conversions, c)) != -1)
		count = fptr[i](ap, var);
	return (count);
}

static int	pf_parse_fmt(const char *str, va_list *ap)
{
	char		*found;
	t_printf	var;
	int		count;

	count = 0;
	while (*str)
	{
		if ((found = ft_strchr(str, '%')) == NULL)
		{
			count += pf_putstrn(str, ft_strlen(str));
			break;
		}
		count += pf_putstrn(str, found - str);
		str = ++found;
		str += pf_get_optionals(str, ap, &var);
		count += pf_do_conversion(*str, ap, &var); 
		if (*str)
			str++;
	}
	return (count);
}

int		ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int	count;

	va_start(ap, fmt);
	count = pf_parse_fmt(fmt, &ap);
	va_end(ap);
	return (count);
}
