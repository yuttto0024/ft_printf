/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 19:53:31 by yuonishi          #+#    #+#             */
/*   Updated: 2025/12/14 20:20:26 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr_recursive(unsigned long long n, char *base)
{
	int	len;

	len = 0;
	if (n >= 16)
		ft_putptr_recursive(n / 16, base);
	len += write(1, &base[n % 16], 1);
	return (len);
}

int	ft_putptr(va_list ap)
{
	unsigned long long	ptr;
	int					len;

	ptr = (unsigned long long)va_arg(nb, void *);
	len = 0;
	if (ptr == NULL)
	{
		len += write(1, "nil", 5);
		return (len);
	}
	len += write (1, "0x", 2);
	len = ft_putptr_recursive(ptr, "0123456789abcdef");
	return (len);
}