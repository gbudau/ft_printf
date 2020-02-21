/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 11:52:41 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/21 11:03:38 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/*
** TODO:Test this for MacOS
*/

/*
int	pf_percent(va_list *ap, t_printf *s, int count)
{
	(void)ap;
	if (s->flags & PF_FLAG_LEFT)
	{
		pf_putchar('%');
		count = pf_put_space(s->width - 1);
	}
	else
	{
		count = pf_put_space(s->width - 1);
		pf_putchar('%');
	}
	return (count + 1);
}
*/

int	pf_percent(va_list *ap, t_printf *s, int count)
{
	(void)ap;
	(void)s;
	(void)count;
	pf_putchar('%');
	return (1);
}
