/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 01:29:41 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/12 06:54:46 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	get_flags(const char *str, t_pf *opt)
{
	int	i;
	int	n;

	i = 0;
	while ((n = ft_strchr_index("0-", str[i])) != -1)
	{
		opt->flags |= 1 << n;
		i++;
	}
	return (i);
}

int	get_width(const char *str, va_list *ap, t_pf *opt)
{
	int i;

	i = 0;
	if (str[i] == '*')
	{
		opt->width = va_arg(*ap, int);
		if (opt->width < 0)
		{
			opt->flags |= F_MINUS;
			opt->width *= -1;
		}
		i++;
	}
	else
	{
		while (ft_isdigit(str[i]))
		{
			opt->width = opt->width * 10 + str[i] - '0';
			i++;
		}
	}
	return (i);
}

int	get_prec(const char *str,va_list *ap, t_pf *opt)
{
	int	i;
	
	i = 0;
	opt->prec = -1;
	if (str[i++] != '.')
		return (0);
	opt->prec = 0;
	if (str[i] == '*')
	{
		opt->prec = va_arg(*ap, int);
		i++;
	}
	else
	{
		while (ft_isdigit(str[i]))
		{
			opt->prec = opt->prec * 10 + str[i] - '0';
			i++;
		}
	}
	return (i);
}	

int	get_optionals(const char *str, va_list *ap, t_pf *opt)
{
	static t_pf	zero;
	int		i;

	*opt = zero;
	i = get_flags(str, opt);
	i += get_width(&str[i], ap, opt);	
	i += get_prec(&str[i], ap, opt);
	return (i);
}

int	put_space(int len)
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

int	print_char(va_list *ap, t_pf *opt)
{
	int	out;
	char	c;

	*opt = *opt;
	c = va_arg(*ap, int);
	if (opt->flags & F_MINUS)
	{
		ft_putchar(c);
		out = put_space(opt->width - 1);
	}
	else
	{
		out = put_space(opt->width - 1);
		ft_putchar(c);
	}
	return (out + 1);
}

int	print_percent(va_list *ap, t_pf *opt)
{
	int	out;

	*opt = *opt;
	(void)*ap;
	out = write(1, "%", 1);
	return (out);
}

int	put_zero(int len)
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

int	print_string(va_list *ap, t_pf *opt)
{
	int	out;
	char	*str;
	int	len;

	str = va_arg(*ap, char *);
	len = ft_strlen(str);
	if (opt->prec >= 0 && opt->prec < len)
		len = opt->prec;
	if (opt->width > len)
	{
		if (opt->flags & F_MINUS)
		{
			out = write(1, str, len);
			out += put_space(opt->width - len);
		}
		else
		{
			out = put_space(opt->width - len);
			out += write(1, str, len);
		}
	}
	else
		out = write(1, str, len);
	return (out);
}

int	put_zero_or_space(t_pf *opt, int len)
{
	if (opt->flags & F_ZERO)
		len = put_zero(len);
	else
		len = put_space(len);
	return (len);
}

void	put_uint(int nb)
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
		put_uint(n / 10);
		putchar(n % 10 + '0');
	}
}

int	print_decimal(va_list *ap, t_pf *opt)
{
	int		nb;
	int		out;
	int		len;

	nb = va_arg(*ap, int);
	len = ft_intlen(nb);
	out = len;
	if (opt->width < out && opt->prec < out)
	{
		ft_putnbr(nb);
		return (out);
	}
	if (opt->flags & F_MINUS)
	{
		if (opt->prec >= 0)
		{
			if (nb < 0 && len <= opt->prec)
			{
				write(1, "-", 1);
				out += put_zero(opt->prec - (len - 1));
				put_uint(nb);
				if (opt->width > opt->prec + 1)
					out += put_space(opt->width - (opt->prec - (len - 1)) - len);
			}
			else
			{
				opt->prec = opt->prec < len ? len : opt->prec;
				out += put_zero(opt->prec - len);
				ft_putnbr(nb);
				out += put_space(opt->width - opt->prec);
			}
		}
		else
		{
			ft_putnbr(nb);
			out += put_space(opt->width - out);
		}
	}
	else
	{
		if (opt->prec >= 0)
		{
			if (nb < 0 && len <= opt->prec)
			{
				if (opt->width > opt->prec + 1)
					out += put_space(opt->width - (opt->prec - (len - 1)) - len);
				write(1, "-", 1);
				out += put_zero(opt->prec - (len - 1));
				put_uint(nb);
			}
			else
			{
				opt->prec = opt->prec < len ? len : opt->prec;
				out += put_space(opt->width - opt->prec);
				out += put_zero(opt->prec - len);
				ft_putnbr(nb);
			}
		}
		else
		{
			out += put_zero_or_space(opt, opt->width - len);
			ft_putnbr(nb);
		}
	}
	return (out);
}

int	do_conversion(int c, va_list *ap, t_pf *opt)
{
	int			out;
	int			i;
	/*static int		(*fptr[128])(va_list *, t_pf *) = {print_char, 
	print_str, print_pointer, print_decimal, print_decimal, print_unsigned, 
	print_hex, print_hex, print_percent};
	static const char	*conversions = "cspdiuxX%";*/
	static int		(*fptr[5])(va_list *, t_pf *) = {print_char, 
		print_string, print_decimal, print_decimal, print_percent};
	static const char	*conversions = "csdi%";

	out = 0;
	if ((i = ft_strchr_index(conversions, c)) != -1)
		out = fptr[i](ap, opt);
	return (out);
}

void	parse_fmt(const char *str, va_list *ap, int *out)
{
	char	*tmp;
	t_pf	opt;

	while (*str)
	{
		if (!(tmp = ft_strchr(str, '%')))
		{
			*out += write(1, str, ft_strlen(str));
			break;
		}
		else
		{
			*out += write(1, str, tmp - str);
			str = tmp;
			str++;
			str += get_optionals(str, ap, &opt);
			*out += do_conversion(*str, ap, &opt); 
		}
		str++;
	}
}

int		ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int	out;

	out = 0;
	va_start(ap, fmt);
	parse_fmt(fmt, &ap, &out);
	va_end(ap);
	return (out);
}
