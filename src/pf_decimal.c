/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 05:38:55 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/17 09:06:50 by gbudau           ###   ########.fr       */
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
	ft_strrev(buffer);
	pf_putstrn(buffer, i);
}

static int	print_minus_first(int n, int len)
{
	ft_putchar('-');
	pf_put_zero(len);
	print_unsigned(-n);
	return (len);
}

static int	print_left(int n, int len, int count, t_printf *l)
{
	if (l->prec < 0)
	{
		print_number(n);
		count += pf_put_space(l->width - count);
		return (count);
	}
	if (n < 0 && len <= l->prec)
	{
		count += print_minus_first(n, l->prec - (len - 1));
		if (l->width > l->prec + 1)
			count += pf_put_space(l->width - 
					(l->prec - (len - 1)) - len);
	}
	else
	{
		l->prec = l->prec < len ? len : l->prec;
		count += pf_put_zero(l->prec - len);
		print_number(n);
		count += pf_put_space(l->width - l->prec);
	}
	return (count);
}

static int	print_right(int n, int len, int count, t_printf *l)
{
	if (l->prec < 0)
	{
		if (n < 0 && (l->flags & F_ZERO) && l->width > len)
			count += print_minus_first(n, l->width - len);
		else
		{
			count += pf_put_zero_or_space(l, l->width - len);
			print_number(n);
		}
		return (count);
	}
	if (n < 0 && len <= l->prec)
	{
		if (l->width > l->prec + 1)
			count += pf_put_space(l->width - 
					(l->prec - (len - 1)) - len);
		count += print_minus_first(n, l->prec - (len - 1));
		return (count);
	}
	l->prec = l->prec < len ? len : l->prec;
	count += pf_put_space(l->width - l->prec);
	count += pf_put_zero(l->prec - len);
	print_number(n);
	return (count);
}

int		pf_decimal(va_list *ap, t_printf *l)
{
	int		n;
	int		count;
	int		len;

	n = va_arg(*ap, int);
	if (l->prec == 0 && n == 0)
		return (pf_put_space(l->width));
	len = ft_intlen(n);
	if (l->width < len && l->prec < len)
		return (print_number(n));
	count = len;
	if (l->flags & F_MINUS)
		count = print_left(n, len, count, l);
	else
		count = print_right(n, len, count, l);
	return (count);
}
