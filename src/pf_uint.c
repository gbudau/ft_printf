/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_uint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 14:01:48 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/19 12:50:51 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		pf_uint(va_list *ap, t_printf *s, int out)
{
	unsigned int	n;
	int		len;
	char		buffer[11];

	n = va_arg(*ap, int);
	if (s->prec == 0 && n == 0)
		return (pf_put_space(s->width));
	len = pf_ultoa_base_len(n, buffer, 10, 0);
	if (s->prec < len && s->width < len)
		return (pf_putstrn(buffer, len));
	if (s->flags & F_MINUS)
	{
		out = pf_put_zero(s->prec - len);
		out += pf_putstrn(buffer, len);
		out += pf_put_space(s->width - (s->prec < len ? len : s->prec));
	}
	else
	{
		out = pf_put_zero_or_space(s, s->width - (s->prec < len ? len : s->prec));
		out += pf_put_zero(s->prec - len);
		out += pf_putstrn(buffer, len);
	}
	return (out);
}
