/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 17:33:10 by yuonishi          #+#    #+#             */
/*   Updated: 2025/12/14 19:51:45 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_puthex_recursive(unsigned int n, char *base)
{
	int	len;

	len = 0;
	while (n >= 16)
		len += ft_puthex_recursive(n / 16);
	len += write(1, &base[n % 16], 1);
	return (len);
}

int	ft_puthex_low(va_list ap)
{
	return (ft_puthex_recursive(va_arg(ap, unsigned int), "0123456789abcdef"))
}

int	ft_puthex_up(va_list ap)
{
	return (ft_puthex_recursive(va_arg(ap, unsigned int), "0123456789ABCDEF"));
}
