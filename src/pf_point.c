/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 16:29:54 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/21 11:03:36 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	pf_null_pointer(long n, t_printf *s)
{
	if (s->flags & PF_FLAG_LEFT)
	{
		n = pf_putstrn("(nil)", 5);
		n += pf_put_space(s->width - 5);
	}
	else
	{
		n = pf_put_space(s->width - 5);
		n += pf_putstrn("(nil)", 5);
	}
	return (n);
}

int		pf_point(va_list *ap, t_printf *s, int count)
{
	long		n;
	int		len;
	char		buffer[15];
	
	n = (long)va_arg(*ap, void *);
	if (n == 0)
		return (n += pf_null_pointer(n, s));
	len = pf_ultoa_base_len(n, buffer, 16, count);
	if (s->flags & PF_FLAG_LEFT)
	{
		count = pf_putstrn(buffer, len);
		count += pf_put_space(s->width - len);
	}
	else
	{
		count = pf_put_space(s->width - len);
		count += pf_putstrn(buffer, len);
	}
	return (count);	
}
