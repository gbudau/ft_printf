/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 01:29:47 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/12 05:01:47 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include "../libft/libft.h"
# define F_ZERO 1
# define F_MINUS 2

typedef struct s_pf
{
	unsigned int	flags;
	int		prec;
	int		width;
}	t_pf;

int	ft_printf(const char *fmt, ...);

#endif
