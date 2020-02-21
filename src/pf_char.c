/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:38:18 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/21 11:03:35 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	pf_char(va_list *ap, t_printf *s, int count)
{
	unsigned char	c;

	c = va_arg(*ap, int);
	if (s->flags & PF_FLAG_LEFT)
	{
		pf_putchar(c);
		count = pf_put_space(s->width - 1);
	}
	else
	{
		count = pf_put_space(s->width - 1);
		pf_putchar(c);
	}
	return (count + 1);
}
