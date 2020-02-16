/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 02:38:18 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/16 06:53:08 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	pf_char(va_list *ap, t_pf_list *list)
{
	int		count;
	unsigned char	c;

	c = va_arg(*ap, int);
	if (list->flags & F_MINUS)
	{
		write(1, &c, 1);
		count = pf_put_space(list->width - 1);
	}
	else
	{
		count = pf_put_space(list->width - 1);
		write(1, &c, 1);
	}
	return (count + 1);
}
