/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_optionals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 05:58:10 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/13 06:00:25 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	pf_get_flags(const char *str, t_pf *opt)
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

static int	pf_get_width(const char *str, va_list *ap, t_pf *opt)
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

static int	pf_get_prec(const char *str,va_list *ap, t_pf *opt)
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

int		pf_get_optionals(const char *str, va_list *ap, t_pf *opt)
{
	static t_pf	zero;
	int		i;

	*opt = zero;
	i = pf_get_flags(str, opt);
	i += pf_get_width(&str[i], ap, opt);	
	i += pf_get_prec(&str[i], ap, opt);
	return (i);
}
