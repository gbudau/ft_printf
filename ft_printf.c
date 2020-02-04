#include "ft_printf.h"

static int	get_flags(const char *str, t_pf *opt)
{
	int i;

	i = 0;
	while (ft_strchr("0-", str[i]))
	{
		str[i] == '0' ? (opt->flags |= F_ZERO) : (opt->flags |= F_MINUS);
		i++;
	}
	return (i);
}

static int	get_width(const char *str, t_pf *opt, va_list *ap)
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

static int	get_optionals(const char *str, va_list *ap, t_pf *opt)
{
	static t_pf	zero;
	int		i;

	*opt = zero;
	i = 0;
	i += get_flags(str, opt);
	i += get_width(&str[i], opt, ap);	
	//i += get_precision(str, opt, ap);
	return (i);
}

static int	do_conversion(char c, t_pf *opt, va_list *ap)
{
	int	out;
	static t_pf	zero;//delete later;

	*opt = zero;//delete later;
	out = 0;
	if (c == 'd')
		out += printf("%d", va_arg(*ap, int));
	return (out);
}

static void	parse_fmt(const char *str, va_list *ap, int *out)
{
	char	*tmp;
	t_pf	flags;

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
			str += get_optionals(str, ap, &flags);
			*out += do_conversion(*str, &flags, ap); 
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
