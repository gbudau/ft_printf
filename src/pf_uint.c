/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_uint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 14:01:48 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/20 13:04:37 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		pf_uint(va_list *ap, t_printf *s, int count)
{
	unsigned int	n;
	int		len;
	char		buffer[11];
	int		total_precision;

	n = va_arg(*ap, int);
	if (s->prec == 0 && n == 0)
		return (pf_put_space(s->width));
	len = pf_ultoa_base_len(n, buffer, 10, 0);
	if (s->prec < len && s->width < len)
		return (pf_putstrn(buffer, len));
	total_precision = s->prec < len ? len : s->prec;
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
