/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 06:29:54 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/17 09:01:18 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	put_long_hex(unsigned long n)
{
	int		i;
	unsigned long	t;

	i = 1;
	if (n == 0)
		return (0);
	i += put_long_hex(n / 16);
	t = n % 16;
	if (t >= 10)
		ft_putchar('a' + (t - 10));
	else
		ft_putchar('0' + t);
	return (i);
}

static int	long_hex_len(unsigned long n)
{
	int	i;

	i = 0;
	while (n)
	{
		n /= 16;
		i++;
	}
	if (i == 0)
		i++;
	return (i);
}

static	int	combine_prefix(unsigned long n)
{
	int	count;

	count = pf_putstrn("0x", 2);
	count += put_long_hex(n);
	return (count);
}

int		pf_point(va_list *ap, t_printf *l)
{
	long		n;
	int		count;
	int		len;
	
	n = (long)va_arg(*ap, void *);
	if (n == 0)
	{
		n += pf_put_space(l->width - 5);
		return (n += pf_putstrn("(nil)", 5));
	}
	len = long_hex_len(n) + 2;
	if (l->flags & F_MINUS)
	{
		count = combine_prefix(n);
		count += pf_put_space(l->width - len);
	}
	else
	{
		count = pf_put_space(l->width - len);
		count += combine_prefix(n);
	}
	return (count);	
}
