/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 07:32:19 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/15 04:19:43 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <string.h>

static void	swap_str(char *x, char *y)
{
	char t;

	t = *x;
	*x = *y;
	*y = t;
}

static char	*rev_str(char *str, int i, int j)
{
	while (i < j)
		swap_str(&str[i++], &str[j--]);
	return (str);
}

static int	put_hex(unsigned int n)
{
	unsigned int	r;
	int		i;
	char		buffer[9];

	i = 0;
	while (n)
	{
		r = n % 16;
		if (r >= 10)
			buffer[i++] = 'a' + (r - 10);
		else
			buffer[i++] = r + '0';
		n /= 16;
	}
	if (i == 0)
		buffer[i++] = '0';
	buffer[i] = '\0';
	rev_str(buffer, 0, i - 1);
	ft_putstr(buffer);
	return (i);
}

static int	hex_len(unsigned int n)
{
	int	i;

	i = 0;
	while (n)
	{
		n /= 16;
		i++;
	}
	if (i == 0)
		i = 1;
	return (i);
}

int		pf_hex(va_list *ap, t_pf *s)
{
	unsigned int	n;
	int		len;
	int		out;

	n = va_arg(*ap, unsigned int);
	len = hex_len(n);
	if (s->prec == 0 && n == 0)
		return (pf_put_space(s->width - len + 1));
	if (s->width < len && s->prec < len)
		return (put_hex(n));
	if (s->flags & F_MINUS)
	{
		out = pf_put_zero(s->prec - len);
		out += put_hex(n);
		out += pf_put_space(s->width - (s->prec > len ? s->prec : len));
	}
	else
	{
		out = pf_put_zero_or_space(s, s->width - 
				(s->prec > len ? s->prec : len));
		out += pf_put_zero(s->prec - len);
		out += put_hex(n);
	}
	return (out);
}
