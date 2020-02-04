#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"
# define ALLSIGNS "-0.*123456789cspdioxX%"
# define F_ZERO 1
# define F_MINUS 2

typedef struct s_pf
{
	unsigned int	flags;
	int		precision;
	int		width;
}	t_pf;

int	ft_printf(const char *fmt, ...);

#endif
