#include "../includes/ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return (ft_putstr("(null)"));
	i = 0;
	while (str[i])
		i += ft_putchar(str[i]);
	return (i);
}

int	ft_putnbr(int n)
{
	int		size;

	size = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		size += ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
		size += ft_putnbr(n / 10);
	size += ft_putchar((n % 10) + '0');
	return (size);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int		size;

	size = 0;
	if (n >= 10)
		size += ft_putnbr_unsigned(n / 10);
	size += ft_putchar((n % 10) + '0');
	return (size);
}

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