/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printft_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:53:48 by psantos-          #+#    #+#             */
/*   Updated: 2025/05/02 18:18:16 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putptr(va_list *args)
{
	uintptr_t address;
	char *hex_digits;
	char buffer[16];
	int i;

	address = (uintptr_t)va_arg(*args, void *);
	*hex_digits = "0123456789abcdef";
	i = 15;
	while (i >= 0)
	{
		buffer[i] = hex_digits[address % 16];
		address /= 16;
		i--;
	}
	write(1, "0x", 2);
	write(1, buffer, 16);
	return (18);
}
