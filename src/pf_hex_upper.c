/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_hex_upper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 12:51:40 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/19 11:53:06 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

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
			buffer[i++] = 'A' + (r - 10);
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
		i++;
	return (i);
}

int		pf_hex_upper(va_list *ap, t_printf *l)
{
	unsigned int	n;
	int		len;
	int		out;

	n = va_arg(*ap, int);
	if (l->prec == 0 && n == 0)
		return (pf_put_space(l->width));
	len = hex_len(n);
	if (l->prec < len && l->width < len)
		return (put_hex(n));
	if (l->flags & F_MINUS)
	{
		out = pf_put_zero(l->prec - len);
		out += put_hex(n);
		out += pf_put_space(l->width - (l->prec < len ? len : l->prec));
	}
	else
	{
		out = pf_put_zero_or_space(l, l->width - 
				(l->prec < len ? len : l->prec));
		out += pf_put_zero(l->prec - len);
		out += put_hex(n);
	}
	return (out);
}
