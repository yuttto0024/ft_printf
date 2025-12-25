/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 17:33:10 by yuonishi          #+#    #+#             */
/*   Updated: 2025/12/25 12:55:09 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex_recursive(unsigned int n, char *base)
{
	int	len;
	int	ret;

	len = 0;
	ret = 0;
	if (n >= 16)
	{
		len += ft_puthex_recursive(n / 16, base);
		if (ret == -1)
			return (-1);
		len += ret;
	}
	if (write(1, &base[n % 16], 1) == -1)
		return (-1);
	len++;
	return (len);
}

int	ft_puthex_low(va_list ap)
{
	return (ft_puthex_recursive(va_arg(ap, unsigned int), "0123456789abcdef"));
}

int	ft_puthex_up(va_list ap)
{
	return (ft_puthex_recursive(va_arg(ap, unsigned int), "0123456789ABCDEF"));
}
