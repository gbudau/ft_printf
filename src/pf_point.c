/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 16:29:54 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/22 09:53:38 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			pf_point(va_list *ap, t_printf *s, int count)
{
	long		n;
	int			len;
	char		buffer[15];

	n = (long)va_arg(*ap, void *);
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
