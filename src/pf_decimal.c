/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:38:55 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/20 12:45:17 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	minus_zero_n(int len, char *buffer, int zero)
{
	int	count;

	count = pf_putchar(buffer[0]);
	count += pf_put_zero(zero);
	count += pf_putstrn(&buffer[1], len - 1);
	return (count);
}

static int	print_minus_first(char *buffer, int len, t_printf *s)
{
	int	count;
	int	total_precision;

	total_precision = s->prec >= len ? s->prec + 1 : len;
	if (s->flags & F_LEFT)
	{
		count = minus_zero_n(len, buffer, s->prec - len + 1);
		count += pf_put_space(s->width - total_precision);
	}
	else if (s->prec >= 0)
	{
		count = pf_put_space(s->width - total_precision);
		count += minus_zero_n(len, buffer, s->prec - len + 1);
	}
	else
		count = minus_zero_n(len, buffer, s->width - len);
	return (count);
}

static int	print_normal(char *buffer, int len, t_printf *s)
{
	int	count;
	int	total_precision;

	total_precision = s->prec > len ? s->prec : len;
	if (s->flags & F_LEFT)
	{
		count = pf_put_zero(s->prec - len);
		count += pf_putstrn(buffer, len);
		count += pf_put_space(s->width - total_precision);
	}
	else
	{
		count = pf_put_zero_or_space(s, s->width - total_precision);
		count += pf_put_zero(s->prec - len);
		count += pf_putstrn(buffer, len);
	}
	return (count);
}

int		pf_decimal(va_list *ap, t_printf *s, int n)
{
	int		count;
	int		len;
	char		buffer[12];

	n = va_arg(*ap, int);
	if (s->prec == 0 && n == 0)
		return (pf_put_space(s->width));
	len = pf_ltoa_base_len(n, buffer, 10, 0);
	if (s->width < len && s->prec < len)
		return (pf_putstrn(buffer, len));
	if (n < 0 && (s->prec >= len || (s->width > len && s->flags & F_ZERO)))
		count = print_minus_first(buffer, len, s);
	else
		count = print_normal(buffer, len, s);
	return (count);
}
