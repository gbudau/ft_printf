/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnrevn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 07:20:06 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/17 07:29:58 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strnrevn(char *buffer, int start, int end)
{
	char	c;

	while (start < end)
	{
		c = buffer[start];
		buffer[start++] = buffer[end];
		buffer[end--] = c;
	}
}
