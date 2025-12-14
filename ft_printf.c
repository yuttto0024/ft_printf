/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:48:21 by yuonishi          #+#    #+#             */
/*   Updated: 2025/12/14 20:33:50 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_convert_and_print(va_list ap, const char fmt)
{
	static t_convert_formatter 	print_table[256];
	static int					:whileis_inittable;

	if (!is_inittable)
	{
		print_table['c'] = ft_putchar;
		print_table['s'] = ft_putstr;
		print_table['p'] = ft_putptr;
		print_table['d'] = ft_putnbr;
		print_table['i'] = ft_putnbr;
		print_table['u'] = ft_putnbr_unsigned;
		print_table['x'] = ft_puthex_low;
		print_table['X'] = ft_puthex_up;
		print_table['%'] = ft_printf_percent;
		is_inittable = 1;
	}
	if (print_table[(unsigned char)fmt])
		return (print_table[(unsigned char)fmt](ap));
	return (0);
}

int ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		total_len;
	size_t	i;

	i = 0;
	total_len = 0;
	va_start(ap, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			if (fmt[i + 1] == '\0')
				break ;
			total_len += ft_convert_and_print(ap, fmt[i + 1]);
			i++;
		}
		else
			total_len += write(1, &fmt[i], 1);
		i++;
	}
	va_end(ap);
	return (total_len);
}