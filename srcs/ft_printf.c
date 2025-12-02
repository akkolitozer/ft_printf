#include "../includes/ft_printf.h"

int	handle_format(va_list *args, char format)
{
	int	size;

	size = 0;
	if (format == 'c')
		size += ft_putchar(va_arg(*args, int));
	else if (format == 's')
		size += ft_putstr(va_arg(*args, char *));
	else if (format == 'd' || format == 'i')
		size += ft_putnbr(va_arg(*args, int));
	else if (format == 'u')
		size += ft_putnbr_unsigned(va_arg(*args, unsigned int));
	else if (format == 'x')
		size += ft_putnbr_base(va_arg(*args, unsigned int), "0123456789abcdef");
	else if (format == 'X')
		size += ft_putnbr_base(va_arg(*args, unsigned int), "0123456789ABCDEF");
	else if (format == 'p')
	{
		size += ft_putstr("0x");
		size += ft_putnbr_base(va_arg(*args, unsigned long), "0123456789abcdef");
	}
	else if (format == '%')
		size += ft_putchar('%');
	return (size);
}



int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		size;

	size = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			size += handle_format(&args, *str);
		}
		else
			size += ft_putchar(*str);
		str++;
	}
	va_end(args);
	return (size);
}

// int	main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		ft_printf("3endi %s fi dem %% %s %u %p\n", argv[1], "", 3000000000, argv);
// 		printf("3endi %s fi dem %% %s %u %p\n", argv[1], "", 3000000000, argv);
// 	}
// 	return (0);
// }