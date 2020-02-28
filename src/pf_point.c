/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 16:29:54 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/28 15:05:09 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	pointer_special_case(t_printf *s)
{
	int			count;

	if (s->flags & PF_FLAG_LEFT)
	{
		count = pf_putstrn("0x", 2);
		count += pf_put_space(s->width - 2);
	}
	else
	{
		count = pf_put_space(s->width - 2);
		count += pf_putstrn("0x", 2);
	}
	return (count);
}

int			pf_point(va_list *ap, t_printf *s, int count)
{
	long		n;
	int			len;
	char		buffer[13];

	n = (long)va_arg(*ap, void *);
	if (n == 0 && s->prec == 0)
		return (pointer_special_case(s));
	len = pf_ltoa_base_len(n, buffer, 16, 0);
	if (s->flags & PF_FLAG_LEFT)
	{
		count = pf_putstrn("0x", 2);
		count += pf_putstrn(buffer, len);
		count += pf_put_space(s->width - count);
	}
	else
	{
		count = pf_put_space(s->width - (len + 2));
		count += pf_putstrn("0x", 2);
		count += pf_putstrn(buffer, len);
	}
	return (count);
}
