#include "../includes/ft_printf.h"

int	ft_putnbr_base(unsigned long nbr, char *base)
{
	int				size;
	unsigned long	base_len;

	size = 0;
	base_len = 0;
	while (base[base_len])
		base_len++;
	if (nbr >= base_len)
		size += ft_putnbr_base(nbr / base_len, base);
	size += ft_putchar(base[nbr % base_len]);
	return (size);
}