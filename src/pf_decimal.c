/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 05:38:55 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/14 06:43:02 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	put_unsigned(int nb)
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
		put_unsigned(n / 10);
		putchar(n % 10 + '0');
	}
}

static int	print_minus_first(int nb, int len)
{
	write(1, "-", 1);
	pf_put_zero(len);
	put_unsigned(nb);
	return (len);
}

static int	print_left(int nb, int len, int out, t_pf *opt)
{
	if (opt->prec < 0)
	{
		ft_putnbr(nb);
		out += pf_put_space(opt->width - out);
		return (out);
	}
	if (nb < 0 && len <= opt->prec)
	{
		out += print_minus_first(nb, opt->prec - (len - 1));
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
	return (out);
}

static int	print_right(int nb, int len, int out, t_pf *opt)
{
	if (opt->prec < 0)
	{
		if (nb < 0 && (opt->flags & F_ZERO) && opt->width > len)
			out += print_minus_first(nb, opt->width - len);
		else
		{
			out += pf_put_zero_or_space(opt, opt->width - len);
			ft_putnbr(nb);
		}
		return (out);
	}
	if (nb < 0 && len <= opt->prec)
	{
		if (opt->width > opt->prec + 1)
			out += pf_put_space(opt->width - 
					(opt->prec - (len - 1)) - len);
		out += print_minus_first(nb, opt->prec - (len - 1));
		return (out);
	}
	opt->prec = opt->prec < len ? len : opt->prec;
	out += pf_put_space(opt->width - opt->prec);
	out += pf_put_zero(opt->prec - len);
	ft_putnbr(nb);
	return (out);
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
		out = print_left(nb, len, out, opt);
	else
		out = print_right(nb, len, out, opt);
	return (out);
}
