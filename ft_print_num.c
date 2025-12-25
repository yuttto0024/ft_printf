/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 17:33:16 by yuonishi          #+#    #+#             */
/*   Updated: 2025/12/25 10:57:17 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_recursive(long n)
{
	int		len;
	char	c;

	len = 0;
	if (n < 0)
	{
		len += write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		len += ft_putnbr_recursive(n / 10);
	c = (n % 10) + '0';
	len += write(1, &c, 1);
	return (len);
}

int	ft_putnbr(va_list ap)
{
	int	n;

	n = va_arg(ap, int);
	return (ft_putnbr_recursive((long)n));
}

static int	ft_putnbr_unsigned_recursive(unsigned int n)
{
	int		len;
	char	c;

	len = 0;
	if (n >= 10)
		len += ft_putnbr_unsigned_recursive(n / 10);
	c = (n % 10) + '0';
	len += write(1, &c, 1);
	return (len);
}

int	ft_putnbr_unsigned(va_list ap)
{
	unsigned int	n;

	n = va_arg(ap, unsigned int);
	return (ft_putnbr_unsigned_recursive(n));
}
