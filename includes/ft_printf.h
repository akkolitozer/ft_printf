#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_printf(const char *str, ...);
int		ft_putnbr(int n);
int		ft_putnbr_unsigned(unsigned int n);
int		ft_putnbr_base(unsigned long nbr, char *base);
int		handle_format(va_list *args, char format);

#endif