/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_optionals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:58:10 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/22 09:09:21 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	pf_get_flags(const char *fmt, t_printf *s)
{
	int			i;
	int			n;

	i = 0;
	while ((n = ft_strchr_index(PF_FLAGS, fmt[i])) != -1)
	{
		s->flags |= 1 << n;
		i++;
	}
	return (i);
}

static int	pf_get_width(const char *fmt, va_list *ap, t_printf *s)
{
	int i;

	i = 0;
	if (fmt[i] == '*')
	{
		s->width = va_arg(*ap, int);
		if (s->width < 0)
		{
			s->flags |= PF_FLAG_LEFT;
			s->width *= -1;
		}
		i++;
	}
	else
	{
		while (ft_isdigit(fmt[i]))
		{
			s->width = s->width * 10 + fmt[i] - '0';
			i++;
		}
	}
	return (i);
}

static int	pf_get_prec(const char *fmt, va_list *ap, t_printf *s)
{
	int	i;

	i = 0;
	s->prec = -1;
	if (fmt[i++] != '.')
		return (0);
	s->prec = 0;
	if (fmt[i] == '*')
	{
		s->prec = va_arg(*ap, int);
		i++;
	}
	else
	{
		while (ft_isdigit(fmt[i]))
		{
			s->prec = s->prec * 10 + fmt[i] - '0';
			i++;
		}
	}
	return (i);
}

int			pf_get_optionals(const char *fmt, va_list *ap, t_printf *s)
{
	static t_printf		zero;
	int					i;

	*s = zero;
	i = pf_get_flags(fmt, s);
	i += pf_get_width(&fmt[i], ap, s);
	i += pf_get_prec(&fmt[i], ap, s);
	return (i);
}
