/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:32:19 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/19 11:58:33 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		pf_hex(va_list *ap, t_printf *l, int c)
{
	unsigned int	n;
	int		len;
	int		out;
	char		buffer[9];

	n = va_arg(*ap, int);
	if (l->prec == 0 && n == 0)
		return (pf_put_space(l->width));
	len = pf_ultoa_base_len(n, buffer, 16, c);
	if (l->width < len && l->prec < len)
		return (pf_putstrn(buffer, len));
	c = l->prec > len ? l->prec : len;
	if (l->flags & F_MINUS)
	{
		out = pf_put_zero(l->prec - len);
		out += pf_putstrn(buffer, len);
		out += pf_put_space(l->width - c);
	}
	else
	{
		out = pf_put_zero_or_space(l, l->width - c);
		out += pf_put_zero(l->prec - len);
		out += pf_putstrn(buffer, len);
	}
	return (out);
}
