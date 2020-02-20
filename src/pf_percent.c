/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 11:52:41 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/20 12:45:19 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	pf_percent(va_list *ap, t_printf *s, int count)
{
	(void)ap;
	if (s->flags & F_LEFT)
	{
		pf_putchar('%');
		count += pf_put_space(s->width - 1);
	}
	else
	{
		count = pf_put_space(s->width - 1);
		pf_putchar('%');
	}
	return (count + 1);
}
