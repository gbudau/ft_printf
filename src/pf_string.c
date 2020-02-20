/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:08:11 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/20 13:04:03 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	pf_string(va_list *ap, t_printf *s, int count)
{
	int	len;
	char	*str;

	str = va_arg(*ap, char *);
	if (!str)
		str = (s->prec < 6 && s->prec > 0) ? "" : "(null)";
	len = ft_strlen(str);
	if (s->prec >= 0 && s->prec < len)
		len = s->prec;
	if (s->width < len)
		return (count = pf_putstrn(str, len));
	if (s->flags & F_LEFT)
	{
		count = pf_putstrn(str, len);
		count += pf_put_space(s->width - len);
	}
	else
	{
		count = pf_put_space(s->width - len);
		count += pf_putstrn(str, len);
	}
	return (count);
}
