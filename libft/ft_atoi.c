/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 02:04:46 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/11 08:19:18 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	unsigned int					nbr;
	int						pon;

	while (ft_isspace(*s))
		s++;
	nbr = 0;
	pon = 1;
	if (*s == '-' || *s == '+')
		pon = (*s++ == '+') ? 1 : -1;
	while (ft_isdigit(*s))
		nbr = *s++ - '0' + nbr * 10;
	return ((int)nbr * pon);
}
