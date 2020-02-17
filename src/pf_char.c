/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 02:38:18 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/17 09:01:05 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	pf_char(va_list *ap, t_printf *list)
{
	int		count;
	unsigned char	c;

	c = va_arg(*ap, int);
	if (list->flags & F_MINUS)
	{
		pf_putchar(c);
		count = pf_put_space(list->width - 1);
	}
	else
	{
		count = pf_put_space(list->width - 1);
		pf_putchar(c);
	}
	return (count + 1);
}
