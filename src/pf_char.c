/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 02:38:18 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/14 07:42:50 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	pf_char(va_list *ap, t_pf *opt)
{
	int		out;
	unsigned char	c;

	c = va_arg(*ap, int);
	if (opt->flags & F_MINUS)
	{
		write(1, &c, 1);
		out = pf_put_space(opt->width - 1);
	}
	else
	{
		out = pf_put_space(opt->width - 1);
		write(1, &c, 1);
	}
	return (out + 1);
}
