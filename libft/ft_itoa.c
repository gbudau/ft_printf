/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 18:37:09 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/28 15:43:11 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	unsigned	u;
	char		*ret;
	size_t		i;

	i = 0;
	if (!(ret = malloc(ft_nblen(n) + 1)))
		return (NULL);
	u = n < 0 ? -n : n;
	while (u)
	{
		ret[i++] = u % 10 + '0';
		u /= 10;
	}
	if (i == 0)
		ret[i++] = '0';
	if (n < 0)
		ret[i++] = '-';
	ret[i] = '\0';
	ft_strnrevn(ret, 0, i - 1);
	return (ret);
}
