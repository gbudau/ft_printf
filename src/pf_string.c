/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 02:08:11 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/17 09:01:09 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	pf_string(va_list *ap, t_printf *list)
{
	int	count;
	int	len;
	char	*str;

	str = va_arg(*ap, char *);
	if (!str)
		str = (list->prec < 6 && list->prec > 0) ? "" : "(null)";
	len = ft_strlen(str);
	if (list->prec >= 0 && list->prec < len)
		len = list->prec;
	if (list->width < len)
		return (count = pf_putstrn(str, len));
	if (list->flags & F_MINUS)
	{
		count = pf_putstrn(str, len);
		count += pf_put_space(list->width - len);
	}
	else
	{
		count = pf_put_space(list->width - len);
		count += pf_putstrn(str, len);
	}
	return (count);
}
