/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 05:38:55 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/13 09:05:45 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	pf_put_unbr(int nb)
{
	unsigned int n;

	if (nb < 0)
		n = nb * -1;
	else
		n = nb;
	if (n < 10)
		ft_putchar(n + '0');
	else
	{
		pf_put_unbr(n / 10);
		putchar(n % 10 + '0');
	}
}

/*
** This funcion deals with the case when the number is negative
** and precision or '0' flag are ON so we have to print
** the '-' first then zero's then the number
*/

static int	pf_put_minus_zero_unbr(int nb, int len)
{
	write(1, "-", 1);
	pf_put_zero(len);
	pf_put_unbr(nb);
	return (len);
}

static int	pf_decimal_left(int nb, int len, t_pf *opt)
{
	int out;

	out = len;
	if (opt->prec >= 0)
	{
		if (nb < 0 && len <= opt->prec)
		{
			out += pf_put_minus_zero_unbr(nb, opt->prec - (len - 1));
			if (opt->width > opt->prec + 1)
				out += pf_put_space(opt->width - 
						(opt->prec - (len - 1)) - len);
		}
		else
		{
			opt->prec = opt->prec < len ? len : opt->prec;
			out += pf_put_zero(opt->prec - len);
			ft_putnbr(nb);
			out += pf_put_space(opt->width - opt->prec);
		}
	}
	else
	{
		ft_putnbr(nb);
		out += pf_put_space(opt->width - out);
	}
	return (out - len);
}

static int	pf_decimal_right(int nb, int len, t_pf *opt)
{
	int out;

	out = len;
	if (opt->prec >= 0)
	{
		if (nb < 0 && len <= opt->prec)
		{
			if (opt->width > opt->prec + 1)
				out += pf_put_space(opt->width - (opt->prec - (len - 1)) - len);
			out += pf_put_minus_zero_unbr(nb, opt->prec - (len - 1));
		}
		else
		{
			opt->prec = opt->prec < len ? len : opt->prec;
			out += pf_put_space(opt->width - opt->prec);
			out += pf_put_zero(opt->prec - len);
			ft_putnbr(nb);
		}
	}
	else
	{
		if (nb < 0 && (opt->flags & F_ZERO) && opt->width > len)
			out += pf_put_minus_zero_unbr(nb, opt->width - len);
		else
		{
			out += pf_put_zero_or_space(opt, opt->width - len);
			ft_putnbr(nb);
		}
	}
	return (out - len);
}

int		pf_decimal(va_list *ap, t_pf *opt)
{
	int		nb;
	int		out;
	int		len;

	nb = va_arg(*ap, int);
	len = ft_intlen(nb);
	out = len;
	if (opt->prec == 0 && nb == 0)
		return (pf_put_space(opt->width - (len - 1)));
	if (opt->width < len && opt->prec < len)
	{
		ft_putnbr(nb);
		return (out);
	}
	if (opt->flags & F_MINUS)
		out += pf_decimal_left(nb, len, opt);
	else
		out += pf_decimal_right(nb, len, opt);
	return (out);
}
