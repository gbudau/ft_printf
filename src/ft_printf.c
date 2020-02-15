/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 01:29:41 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/15 02:56:28 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	pf_do_conversion(int c, va_list *ap, t_pf *opt)
{
	int			out;
	int			i;
	static int		(*fptr[6])(va_list *, t_pf *) = 
	{pf_char, pf_string, pf_decimal, pf_decimal, pf_hex, pf_hex_upper};
	static const char	conversions[7] = 
	{'c', 's', 'd', 'i', 'x', 'X', '\0'};

	if (c == '%')
		return (write(1, &c, 1));
	out = 0;
	if ((i = ft_strchr_index(conversions, c)) != -1)
		out = fptr[i](ap, opt);
	return (out);
}

static int	pf_parse_fmt(const char *str, va_list *ap)
{
	char	*tmp;
	t_pf	opt;
	int	out;

	out = 0;
	while (*str)
	{
		if ((tmp = ft_strchr(str, '%')) == NULL)
		{
			out += write(1, str, ft_strlen(str));
			break;
		}
		else
		{
			out += write(1, str, tmp - str);
			str = tmp;
			str++;
			str += pf_get_optionals(str, ap, &opt);
			out += pf_do_conversion(*str, ap, &opt); 
		}
		str++;
	}
	return (out);
}

int		ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int	out;

	va_start(ap, fmt);
	out = pf_parse_fmt(fmt, &ap);
	va_end(ap);
	return (out);
}
