/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:53:48 by psantos-          #+#    #+#             */
/*   Updated: 2025/05/08 14:43:04 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putstr(char *str)
{
	int	i;
	int	count;
	int	total_len;

	i = 0;
	total_len = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		count = write(1, &str[i], 1);
		if (add_len(count, &total_len) < 0)
			return (-1);
		i++;
	}
	return (total_len);
}

int	ft_putptr(void *ptr)
{
	char	*number;
	int 	count;
	int 	total_len;

	if (!ptr)
		return (ft_putstr("(nil)"));
	total_len = 0;
	number = ft_itoa_base((uintptr_t)ptr, "0123456789abcdef");
	if (!number)
		return (-1);
	count = write(1, "0x", 2);
	if (add_len(count, &total_len) < 0)
		return (-1);
	count = ft_putstr(number);
	free(number);
	number = NULL;
	return (add_len(count, &total_len));
}
