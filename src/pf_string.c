/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 02:08:11 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/15 00:37:07 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	pf_string(va_list *ap, t_pf *opt)
{
	int	out;
	int	len;
	char	*str;

	str = va_arg(*ap, char *);
	if (!str)
		str = (opt->prec < 6 && opt->prec > 0) ? "" : "(null)";
	len = ft_strlen(str);
	if (opt->prec >= 0 && opt->prec < len)
		len = opt->prec;
	if (opt->width < len)
		return (out = write(1, str, len));
	if (opt->flags & F_MINUS)
	{
		out = write(1, str, len);
		out += pf_put_space(opt->width - len);
	}
	else
	{
		out = pf_put_space(opt->width - len);
		out += write(1, str, len);
	}
	return (out);
}
