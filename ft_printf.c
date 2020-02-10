/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 01:29:41 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/10 09:55:48 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	get_precision(const char *str,va_list *ap, t_pf *opt)
{
	int	i;
	
	i = 0;
	opt->precision = -1;
	if (str[i] == '.')
	{
		i++;
		opt->precision = 0;
		if (str[i] == '*')
		{
			opt->precision = va_arg(*ap, int);
			i++;
		}
		else
		{
			while (ft_isdigit(str[i]))
			{
				opt->precision = opt->precision * 10 + str[i] - '0';
				i++;
			}
		}
	}
	return (i);
}	

int	get_optionals(const char *str, va_list *ap, t_pf *opt)
{
	static t_pf	zero;
	int		i;

	*opt = zero;
	i = 0;
	i += get_flags(str, opt);
	i += get_width(&str[i], ap, opt);	
	i += get_precision(&str[i], ap, opt);
	return (i);
}

int	print_char(va_list *ap, t_pf *opt)
{
	int	out;
	char	c;

	out = 0;
	*opt = *opt;
	c = va_arg(*ap, int);
	if (opt->flags & F_MINUS)
	{
		out += write(1, &c, 1);
		while (--opt->width > 0)
			out += write(1, " ", 1);
	}
	else
	{
		while (opt->width-- > 1)
			out += write(1, " ", 1);
		out += write(1, &c, 1);
	}
	return (out);
}

int	print_percent(va_list *ap, t_pf *opt)
{
	int	out;

	out = 0;
	*opt = *opt;
	(void)*ap;
	out += write(1, "%", 1);
	return (out);
}

int	put_space(int	len)
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

int	print_string(va_list *ap, t_pf *opt)
{
	int	out;
	char	*str;
	int	len;

	str = va_arg(*ap, char *);
	len = ft_strlen(str);
	if (opt->precision >= 0 && opt->precision < len)
		len = opt->precision;
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

int	print_decimal(va_list *ap, t_pf *opt)
{
	int	nb;
	int	len;

	*opt = *opt;
	nb = va_arg(*ap, int);
	len = ft_intlen(nb);
	ft_putnbr(nb);
	return (len);
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
