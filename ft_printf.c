/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:08:46 by psantos-          #+#    #+#             */
/*   Updated: 2025/05/11 13:13:15 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	add_len(int count, int *total_len)
{
	if (count < 0)
		return (-1);
	*total_len += count;
	return (*total_len);
}

int	ft_printarg(char c, va_list *args)
{
	if (c == '%')
		return (write(1, "%", 1));
	if (c == 'c')
		return (ft_putchar(va_arg(*args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(*args, char *)));
	if (c == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	if (c == 'u')
		return (ft_putunbr(va_arg(*args, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(*args, unsigned int), c));
	return (-1);
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		total_len;
	int		count;
	int		i;

	if (!string)
		return (-1);
	total_len = 0;
	i = 0;
	va_start(args, string);
	while (string[i])
	{
		if (string[i] == '%')
			count = ft_printarg(string[++i], &args);
		else
			count = write(1, &string[i], 1);
		if (add_len(count, &total_len) < 0)
			return (-1);
		i++;
	}
	va_end(args);
	return (total_len);
}

/*int main (void)
{
	char *str = NULL;
	void *ptr = NULL;
	int ft;
	int lc;

	printf("Percent\n");
	ft = ft_printf("Normal ft: %%\n");
	lc = printf("Normal lc: %%\n");
	printf("%i %i\n", ft, lc);
	printf("-------------------------\n");

	printf("Char\n");
	ft = ft_printf("Normal ft: %c\n", 'A');
	lc = printf("Normal lc: %c\n", 'A');
	printf("%i %i\n", ft, lc);
	printf("-------------------------\n");

	printf("String\n");
	ft = ft_printf("Normal ft: %s\n", "Hello");
	lc = printf("Normal lc: %s\n", "Hello");
	printf("%i %i\n\n", ft, lc);

	ft = ft_printf("Empty ft: %s\n", "");
	lc = printf("Empty lc: %s\n", "");
	printf("%i %i\n\n", ft, lc);

	ft = ft_printf("NULL ft: %s\n", str);
	lc = printf("NULL lc: %s\n", str);
	printf("%i %i\n", ft, lc);
	printf("-------------------------\n");

	printf("Int & Decimal\n");
	ft = ft_printf("Int ft: %i %i %i\n", 0, INT_MAX, INT_MIN);
	lc = printf("Int lc: %i %i %i\n", 0, INT_MAX, INT_MIN);
	printf("%i %i\n\n", ft, lc);

	ft = ft_printf("Decimal ft: %d %d %d\n", 0, -100, 100);
	lc = printf("Decimal lc: %d %d %d\n", 0, -100, 100);
	printf("%i %i\n", ft, lc);
	printf("-------------------------\n");

	printf("Unsigned\n");
	ft = ft_printf("Max ft: %u %u\n", 0, UINT_MAX);
	lc = printf("Max lc: %u %u\n", 0, UINT_MAX);
	printf("%i %i\n\n", ft, lc);

	ft = ft_printf("Wrap ft: %u\n", -1);
	lc = printf("Wrap lc: %u\n", -1);
	printf("%i %i\n", ft, lc);
	printf("-------------------------\n");

	printf("Hexadecimal\n");
	ft = ft_printf("Hex ft: %x %X\n", 140, 140);
	lc = printf("Hex lc: %x %X\n", 140, 140);
	printf("%i %i\n\n", ft, lc);

	ft = ft_printf("NULL Pointer ft: %x %X\n", 0, 0);
	lc = printf("NULL Pointer lc: %x %X\n", 0, 0);
	printf("%i %i\n", ft, lc);
	printf("-------------------------\n");

	printf("Pointer\n");
	ft = ft_printf("Pointer ft: %p\n", (void *)"Hello");
	lc = printf("Pointer lc: %p\n", (void *)"Hello");
	printf("%i %i\n\n", ft, lc);

	ft = ft_printf("NULL Pointer ft: %p\n", ptr);
	lc = printf("NULL Pointer lc: %p\n", ptr);
	printf("%i %i\n", ft, lc);
	printf("-------------------------\n");

	printf("Mixed\n");
	ft = ft_printf("Mixed ft: %% %c %s %p %i %d %u %x %X\n", 'A', 
	"Hello", (void *)"Hello", 0, 100, -1, 140, 140);
	lc = printf("Mixed lc: %% %c %s %p %i %d %u %x %X\n", 'A', 
	"Hello", (void *)"Hello", 0, 100, -1, 140, 140);
	printf("%i %i\n", ft, lc);
	printf("-------------------------\n");
}*/