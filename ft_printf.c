/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:08:46 by psantos-          #+#    #+#             */
/*   Updated: 2025/05/08 14:46:01 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	add_len(int count, int *total_len)
{
	if (count < 0)
		return (-1);
	*total_len += count;
	return (*total_len);
}

int	ft_printarg(char c, va_list args)
{
	if (c == '%')
		return (write(1, "%", 1));
	if (c == 'c')
		return (write(1, (char[1]){(char)va_arg(args, int)}, 1));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'p')
		return (ft_putptr(va_arg(args, void *)));
	return (-1);
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		total_len;
	int		count;
	int		i;
	
	count = 0;
	total_len = 0;
	i = 0;
	va_start(args, string);
	if (!string)
		return (-1);
	while(string[i])
	{
		if (string[i] != '%')
			count = write(1, &string[i], 1);
		if (string[i] == '%')
			count = ft_printarg(string[++i], args);
		if (add_len(count, &total_len) < 0)
			return (-1);
		i++;
	}
	va_end(args);
	return (total_len);
}

int main (void)
{
	ft_printf("Hello my name is %% Pedro %c %s %p", 'c', "Borrega", (void *) "str");
}