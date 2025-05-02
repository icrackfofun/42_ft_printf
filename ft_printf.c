/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:08:46 by psantos-          #+#    #+#             */
/*   Updated: 2025/05/02 18:23:18 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*int	ft_strlen(char *str)
{
	while (*str)
		str++;
	return (str);
}*/

int	ft_putstr(va_list *args)
{
	char	*ptr;
	int		i;
	
	ptr = va_arg(*args, char *);
	i = 0;
	while (ptr[i])
	{
		write (1, &ptr[i], 1);
		i++;
	}
	return (i);
}

int	ft_printarg(char c, va_list *args)
{
	if (c == '%')
		return (write(1, "%", 1));
	if (c == 'c')
		return (write(1, (char[1]){(char)va_arg(*args, int)}, 1));
	if (c == 's')
		return (ft_putstr(args));
	if (c == 'p')
		return (ft_putptr(args));
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		count;
	
	count = 0;
	va_start(args, string);
	while(*string)
	{
		if (*string != '%')
		{
			write(1, string, 1);
			count++;
			string++;
		}
		if (*string == '%')
		{
			count += ft_printarg(*(string + 1), &args);
			string += 2;
		}
	}
	va_end(args);
	return (count);
}

int main (void)
{
	//char *ptr = "A";

	ft_printf("Hello my name is %% Pedro %c %s", 'c', "Borrega");
}