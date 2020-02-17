/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 02:38:18 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/17 09:23:37 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	pf_char(va_list *ap, t_printf *var)
{
	int		count;
	unsigned char	c;

	c = va_arg(*ap, int);
	if (var->flags & F_MINUS)
	{
		pf_putchar(c);
		count = pf_put_space(var->width - 1);
	}
	else
	{
		count = pf_put_space(var->width - 1);
		pf_putchar(c);
	}
	return (count + 1);
}
