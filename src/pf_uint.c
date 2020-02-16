/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_uint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 04:01:48 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/16 08:23:53 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	str_rev(char *buffer, int start, int end)
{
	char	c;

	while (start < end)
	{
		c = buffer[start];
		buffer[start++] = buffer[end];
		buffer[end--] = c;
	}
}

static int	put_uint(unsigned int n)
{
	int		i;
	unsigned int	t;
	char		buffer[11];

	i = 0;
	while (n != 0)
	{
		t = n % 10;
		buffer[i++] = t  + '0';
		n /= 10;
	}
	if (i == 0)
		buffer[i++] = '0';
	buffer[i] = '\0';
	str_rev(buffer, 0, i - 1);
	ft_putstr(buffer);
	return (i);
}

static int	uint_len(unsigned int n)
{
	int	i;
	
	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	if (i == 0)
		i++;
	return (i);
}

int		pf_uint(va_list *ap, t_pf_list *s)
{
	unsigned int	n;
	int		out;
	int		len;

	n = va_arg(*ap, unsigned int);
	if (s->prec == 0 && n == 0)
		return (pf_put_space(s->width));
	len = uint_len(n);
	if (s->prec < len && s->width < len)
		return (put_uint(n));
	if (s->flags & F_MINUS)
	{
		out = pf_put_zero(s->prec - len);
		out += put_uint(n);
		out += pf_put_space(s->width - (s->prec < len ? len : s->prec));
	}
	else
	{
		out = pf_put_zero_or_space(s, s->width - (s->prec < len ? len : s->prec));
		out += pf_put_zero(s->prec - len);
		out += put_uint(n);
	}
	return (out);
}
