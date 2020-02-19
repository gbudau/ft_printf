/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_optionals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:58:10 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/19 12:00:54 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	pf_get_flags(const char *str, t_printf *var)
{
	int			i;
	int			n;

	i = 0;
	while ((n = ft_strchr_index(PF_FLAGS, str[i])) != -1)
	{
		var->flags |= 1 << n;
		i++;
	}
	return (i);
}

static int	pf_get_width(const char *str, va_list *ap, t_printf *var)
{
	int i;

	i = 0;
	if (str[i] == '*')
	{
		var->width = va_arg(*ap, int);
		if (var->width < 0)
		{
			var->flags |= F_MINUS;
			var->width *= -1;
		}
		i++;
	}
	else
	{
		while (ft_isdigit(str[i]))
		{
			var->width = var->width * 10 + str[i] - '0';
			i++;
		}
	}
	return (i);
}

static int	pf_get_prec(const char *str,va_list *ap, t_printf *var)
{
	int	i;
	
	i = 0;
	var->prec = -1;
	if (str[i++] != '.')
		return (0);
	var->prec = 0;
	if (str[i] == '*')
	{
		var->prec = va_arg(*ap, int);
		i++;
	}
	else
	{
		while (ft_isdigit(str[i]))
		{
			var->prec = var->prec * 10 + str[i] - '0';
			i++;
		}
	}
	return (i);
}	

int		pf_get_optionals(const char *str, va_list *ap, t_printf *var)
{
	static t_printf	zero;
	int		i;

	*var = zero;
	i = pf_get_flags(str, var);
	i += pf_get_width(&str[i], ap, var);	
	i += pf_get_prec(&str[i], ap, var);
	return (i);
}
