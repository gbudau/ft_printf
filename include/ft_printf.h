/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 01:29:47 by gbudau            #+#    #+#             */
/*   Updated: 2020/02/13 05:58:57 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
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
int	pf_string(va_list *ap, t_pf *opt);
int	pf_decimal(va_list *ap, t_pf *opt);
int	pf_char(va_list *ap, t_pf *opt);
int	pf_get_optionals(const char *str, va_list *ap, t_pf *opt);
int	pf_put_zero(int len);
int	pf_put_space(int len);
int	pf_put_zero_or_space(t_pf *opt, int len);

#endif
