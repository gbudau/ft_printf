/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:08:11 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/19 11:53:51 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	pf_string(va_list *ap, t_printf *var, int count)
{
	int	len;
	char	*str;

	str = va_arg(*ap, char *);
	if (!str)
		str = (var->prec < 6 && var->prec > 0) ? "" : "(null)";
	len = ft_strlen(str);
	if (var->prec >= 0 && var->prec < len)
		len = var->prec;
	if (var->width < len)
		return (count = pf_putstrn(str, len));
	if (var->flags & F_MINUS)
	{
		count = pf_putstrn(str, len);
		count += pf_put_space(var->width - len);
	}
	else
	{
		count = pf_put_space(var->width - len);
		count += pf_putstrn(str, len);
	}
	return (count);
}
