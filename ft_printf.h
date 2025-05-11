/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:00:11 by psantos-          #+#    #+#             */
/*   Updated: 2025/05/11 13:14:01 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *string, ...);
int		ft_printarg(char c, va_list *args);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putptr(void *ptr);
int		ft_putnbr(int n);
int		ft_putunbr(unsigned int n);
int		ft_puthex(unsigned int n, char c);
size_t	ft_strlen(const char *str);
int		add_len(int count, int *total_len);
char	*ft_itoa_base(uintptr_t n, char *baseset);
int		ft_numlen(uintptr_t n, size_t base);

#endif