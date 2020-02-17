/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 05:45:49 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/17 08:56:37 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	pf_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	pf_putstrn(const char *s, int len)
{
	write(1, s, len);
	return (len);
}

int	pf_put_space(int len)
{
	int i;
	
	i = 0;
	while (i < len)
	{
		write(1, " ", 1);
		i++;
	}
	return (i);
}

int	pf_put_zero(int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		write(1, "0", 1);
		i++;
	}
	return (i);
}

int	pf_put_zero_or_space(t_printf *opt, int len)
{
	if (opt->flags & F_ZERO && opt->prec < 0)
		return (pf_put_zero(len));
	return (pf_put_space(len));
}
