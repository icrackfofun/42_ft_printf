/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 23:30:23 by psantos-          #+#    #+#             */
/*   Updated: 2025/05/08 14:45:21 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_numlen(uintptr_t n, size_t base)
{
	int	len;

	len = (n == 0);
	while (n > 0)
	{
		len++;
		n /= base;
	}
	return (len);
}

char	*ft_itoa_base(uintptr_t n, char *baseset)
{
	char		*number;
	int			len;
	int			base;

	base = ft_strlen(baseset);
	len = ft_numlen(n, base);
	number = (char *)malloc(len + 1);
	if (!number)
		return (NULL);
	number[len] = '\0';
	while (n > 0)
	{
		len--;
		number[len] = baseset[n % base];
		n /= base;
	}
	return (number);
}
