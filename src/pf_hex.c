/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:32:19 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/28 14:51:14 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		pf_hex(va_list *ap, t_printf *s, int c)
{
	unsigned int	n;
	int				len;
	int				count;
	char			buffer[9];

	n = va_arg(*ap, int);
	if (s->prec == 0 && n == 0)
		return (pf_put_space(s->width));
	len = pf_ltoa_base_len(n, buffer, 16, c);
	if (s->width < len && s->prec < len)
		return (pf_putstrn(buffer, len));
	c = s->prec > len ? s->prec : len;
	if (s->flags & PF_FLAG_LEFT)
	{
		count = pf_put_zero(s->prec - len);
		count += pf_putstrn(buffer, len);
		count += pf_put_space(s->width - c);
	}
	else
	{
		count = pf_put_zero_or_space(s, s->width - c);
		count += pf_put_zero(s->prec - len);
		count += pf_putstrn(buffer, len);
	}
	return (count);
}
