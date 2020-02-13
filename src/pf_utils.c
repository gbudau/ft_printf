/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 05:45:49 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/13 05:46:09 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	pf_put_space(int len)
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

int	pf_put_zero(int len)
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

int	pf_put_zero_or_space(t_pf *opt, int len)
{
	if (opt->flags & F_ZERO)
		len = pf_put_zero(len);
	else
		len = pf_put_space(len);
	return (len);
}
