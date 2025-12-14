/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:48:21 by yuonishi          #+#    #+#             */
/*   Updated: 2025/12/14 16:53:52 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FT_PRINTF_H"

int	ft_convert_and_print(va_list ap, const char fmt)
{
	int	total_len;

	ret = 0;
	if (fmt == 'c')
		total_len += ft_putchar(va_arg(ap, int));
	else if (fmt == 's')
		total_len += ft_putstr(va_arg(ap, char *));
	else if (fmt == 'p')
		total_len += ft_putpoint(va_arg(ap, void *));
	else if (fmt == 'd' || fmt == 'i')
		total_len += ft_putnbr(va_arg(ap, int));
	else if (fmt == 'u')
		total_len += ft_putnbr_unsigned(va_arg(ap, unsigned int));
	else if (fmt == 'x')
		total_len += ft_putnbr_hex_low(va_arg(ap, unsigned int));
	else if (fmt == 'X')
		total_len += ft_putnbr_hex_up(va_arg(ap, unsigned int));
	else if (fmt == '%')
		total_len += ft_printf_percent();
	return (total_len);
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

int main()
{
	int	i;

	i = 12;
	foo("Hello%d", i);
	return	(0);
}