/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 05:38:55 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/18 11:47:46 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	print_number(int n)
{
	unsigned	u;
	int		i;
	char		buffer[12];

	i = 0;
	u = n < 0 ? -n : n;
	while(u)
	{
		buffer[i++] = u % 10 + '0';
		u /= 10;
	}
	if (i == 0)
		buffer[i++] = '0';
	if (n < 0)
		buffer[i++] = '-';
	buffer[i] = '\0';
	ft_strnrevn(buffer, 0, i - 1);
	pf_putstrn(buffer, i);
	return (i);
}

static int	print_unsigned(unsigned n)
{
	char		buffer[12];
	int		i;

	i = 0;
	while (n)
	{
		buffer[i++] = n % 10 + '0';
		n /= 10;
	}
	if (i == 0)
		buffer[i++] = '0';
	buffer[i] = '\0';
	ft_strnrevn(buffer, 0, i - 1);
	pf_putstrn(buffer, i);
	return (i);
}

static int	minus_zero_n(int n, int len)
{
	int	i;

	i = pf_putchar('-');
	i += pf_put_zero(len);
	i += print_unsigned(-n);
	return (i);
}

static int	print_minus_first(int n, int len, t_printf *v)
{
	int	i;

	if (v->flags & F_MINUS)
	{
		i = minus_zero_n(n, v->prec >= len ? v->prec - len + 1 : 0);
		i += pf_put_space(v->width - (v->prec >= len ? v->prec + 1 : len));
	}
	else if (v->prec >= 0)
	{
		i = pf_put_space(v->width - (v->prec >=  len ? v->prec + 1 : len));
		i += minus_zero_n(n, v->prec - len + 1);
	}
	else
		i = minus_zero_n(n, v->width - len);
	return (i);
}

static int	print_normal(int n, int len, t_printf *v)
{
	int	i;

	if (v->flags & F_MINUS)
	{
		i = pf_put_zero(v->prec - len);
		i += n < 0 ? print_number(n) : print_unsigned(n);
		i += pf_put_space(v->width - (v->prec > len ? v->prec : len));
	}
	else
	{
		i = pf_put_zero_or_space(v, v->width - (v->prec > len ? v->prec : len));
		i += pf_put_zero(v->prec - len);
		i += n < 0 ? print_number(n) : print_unsigned(n);
	}
	return (i);
}

int		pf_decimal(va_list *ap, t_printf *v)
{
	int		n;
	int		i;
	int		len;

	n = va_arg(*ap, int);
	if (v->prec == 0 && n == 0)
		return (pf_put_space(v->width));
	len = ft_intlen(n);
	if (v->width < len && v->prec < len)
		return (print_number(n));
	if (n < 0 && (v->prec >= len || (v->width > len && v->flags & F_ZERO)))
		i = print_minus_first(n, len, v);
	else
		i = print_normal(n, len, v);
	return (i);
}
