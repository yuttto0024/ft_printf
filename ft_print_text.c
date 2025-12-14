/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 16:55:18 by yuonishi          #+#    #+#             */
/*   Updated: 2025/12/14 20:22:42 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(va_list ap)
{
	unsigned char	c;

	c = (unsigned char)va_arg(ap, int);
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(va_list ap)
{
	char	*str;
	size_t	i;

	str = va_arg(ap, char *);
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return ((int)i);
}

int	ft_printf_percent(va_list ap)
{
	(void)ap;
	write(1, "%", 1);
	return (1);
}
