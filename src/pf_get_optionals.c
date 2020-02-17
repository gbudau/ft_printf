/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_optionals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 05:58:10 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/17 09:07:23 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	pf_get_flags(const char *str, t_printf *list)
{
	int			i;
	static const char	flags[3] = {'0', '-', '\0'};
	char			*found;

	i = 0;
	while ((found = ft_strchr(flags, str[i])) != NULL)
	{
		list->flags |= 1 << (found - flags);
		i++;
	}
	return (i);
}

static int	pf_get_width(const char *str, va_list *ap, t_printf *list)
{
	int i;

	i = 0;
	if (str[i] == '*')
	{
		list->width = va_arg(*ap, int);
		if (list->width < 0)
		{
			list->flags |= F_MINUS;
			list->width *= -1;
		}
		i++;
	}
	else
	{
		while (ft_isdigit(str[i]))
		{
			list->width = list->width * 10 + str[i] - '0';
			i++;
		}
	}
	return (i);
}

static int	pf_get_prec(const char *str,va_list *ap, t_printf *list)
{
	int	i;
	
	i = 0;
	list->prec = -1;
	if (str[i++] != '.')
		return (0);
	list->prec = 0;
	if (str[i] == '*')
	{
		list->prec = va_arg(*ap, int);
		i++;
	}
	else
	{
		while (ft_isdigit(str[i]))
		{
			list->prec = list->prec * 10 + str[i] - '0';
			i++;
		}
	}
	return (i);
}	

int		pf_get_optionals(const char *str, va_list *ap, t_printf *list)
{
	static t_printf	zero;
	int		i;

	*list = zero;
	i = pf_get_flags(str, list);
	i += pf_get_width(&str[i], ap, list);	
	i += pf_get_prec(&str[i], ap, list);
	return (i);
}
