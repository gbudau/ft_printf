/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 05:38:55 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/17 09:30:35 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	print_number(int n)
{
	unsigned	u;
	int		i;
	char		buffer[12];

	i = 0;
	if (n < 0)
		u = n * -1;
	else
		u = n;
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

static void	print_unsigned(unsigned n)
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
}

static int	print_minus_first(int n, int len)
{
	ft_putchar('-');
	pf_put_zero(len);
	print_unsigned(-n);
	return (len);
}

static int	print_left(int n, int len, int count, t_printf *v)
{
	if (v->prec < 0)
	{
		print_number(n);
		count += pf_put_space(v->width - count);
		return (count);
	}
	if (n < 0 && len <= v->prec)
	{
		count += print_minus_first(n, v->prec - (len - 1));
		if (v->width > v->prec + 1)
			count += pf_put_space(v->width - 
					(v->prec - (len - 1)) - len);
	}
	else
	{
		v->prec = v->prec < len ? len : v->prec;
		count += pf_put_zero(v->prec - len);
		print_number(n);
		count += pf_put_space(v->width - v->prec);
	}
	return (count);
}

static int	print_right(int n, int len, int count, t_printf *v)
{
	if (v->prec < 0)
	{
		if (n < 0 && (v->flags & F_ZERO) && v->width > len)
			count += print_minus_first(n, v->width - len);
		else
		{
			count += pf_put_zero_or_space(v, v->width - len);
			print_number(n);
		}
		return (count);
	}
	if (n < 0 && len <= v->prec)
	{
		if (v->width > v->prec + 1)
			count += pf_put_space(v->width - 
					(v->prec - (len - 1)) - len);
		count += print_minus_first(n, v->prec - (len - 1));
		return (count);
	}
	v->prec = v->prec < len ? len : v->prec;
	count += pf_put_space(v->width - v->prec);
	count += pf_put_zero(v->prec - len);
	print_number(n);
	return (count);
}

int		pf_decimal(va_list *ap, t_printf *v)
{
	int		n;
	int		count;
	int		len;

	n = va_arg(*ap, int);
	if (v->prec == 0 && n == 0)
		return (pf_put_space(v->width));
	len = ft_intlen(n);
	if (v->width < len && v->prec < len)
		return (print_number(n));
	count = len;
	if (v->flags & F_MINUS)
		count = print_left(n, len, count, v);
	else
		count = print_right(n, len, count, v);
	return (count);
}
