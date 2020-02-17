/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 07:32:19 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/17 09:01:27 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <string.h>

static int	put_hex(unsigned int n)
{
	unsigned int	r;
	int		i;
	char		buffer[9];

	i = 0;
	while (n)
	{
		r = n % 16;
		if (r >= 10)
			buffer[i++] = 'a' + (r - 10);
		else
			buffer[i++] = r + '0';
		n /= 16;
	}
	if (i == 0)
		buffer[i++] = '0';
	buffer[i] = '\0';
	ft_strnrevn(buffer, 0, i - 1);
	pf_putstrn(buffer, i);
	return (i);
}

static int	hex_len(unsigned int n)
{
	int	i;

	i = 0;
	while (n)
	{
		n /= 16;
		i++;
	}
	if (i == 0)
		i = 1;
	return (i);
}

int		pf_hex(va_list *ap, t_printf *l)
{
	unsigned int	n;
	int		len;
	int		out;

	n = va_arg(*ap, int);
	if (l->prec == 0 && n == 0)
		return (pf_put_space(l->width));
	len = hex_len(n);
	if (l->width < len && l->prec < len)
		return (put_hex(n));
	if (l->flags & F_MINUS)
	{
		out = pf_put_zero(l->prec - len);
		out += put_hex(n);
		out += pf_put_space(l->width - (l->prec > len ? l->prec : len));
	}
	else
	{
		out = pf_put_zero_or_space(l, l->width - 
				(l->prec > len ? l->prec : len));
		out += pf_put_zero(l->prec - len);
		out += put_hex(n);
	}
	return (out);
}