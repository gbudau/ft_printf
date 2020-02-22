/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:45:49 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/22 09:05:26 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	pf_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	pf_putstrn(const char *str, int len)
{
	write(1, str, len);
	return (len);
}

int		pf_put_space(int len)
{
	int	i;

	i = 0;
	while (len >= PF_FILL_SIZE)
	{
		write(1, PF_SPACE_FILL, PF_FILL_SIZE);
		i += PF_FILL_SIZE;
		len -= PF_FILL_SIZE;
	}
	while (len > 0)
	{
		write(1, " ", 1);
		i++;
		len--;
	}
	return (i);
}

int		pf_put_zero(int len)
{
	int	i;

	i = 0;
	while (len >= PF_FILL_SIZE)
	{
		write(1, PF_ZERO_FILL, PF_FILL_SIZE);
		i += PF_FILL_SIZE;
		len -= PF_FILL_SIZE;
	}
	while (len > 0)
	{
		write(1, "0", 1);
		i++;
		len--;
	}
	return (i);
}

int		pf_put_zero_or_space(t_printf *opt, int len)
{
	if (opt->flags & PF_FLAG_ZERO && opt->prec < 0)
		return (pf_put_zero(len));
	return (pf_put_space(len));
}
