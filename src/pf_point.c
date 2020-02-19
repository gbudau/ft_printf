/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 16:29:54 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/19 11:53:33 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	pf_null_pointer(long n, t_printf *l)
{
	if (l->flags & F_MINUS)
		n += pf_putstrn("(nil)", 5);
	n += pf_put_space(l->width - 5);
	if (!(l->flags & F_MINUS))
		n += pf_putstrn("(nil)", 5);
	return (n);
}

int		pf_point(va_list *ap, t_printf *l, int count)
{
	long		n;
	int		len;
	char		buffer[15];
	
	n = (long)va_arg(*ap, void *);
	if (n == 0)
		return (n += pf_null_pointer(n, l));
	count = 0;
	ft_strcpy(buffer, "0x");
	len = pf_ultoa_base_len(n, &buffer[2], 16, 0) + 2;
	if (l->flags & F_MINUS)
		count += pf_putstrn(buffer, len);
	count += pf_put_space(l->width - len);
	if (!(l->flags & F_MINUS))
		count += pf_putstrn(buffer, len);
	return (count);	
}
