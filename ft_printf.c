/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:48:21 by yuonishi          #+#    #+#             */
/*   Updated: 2025/12/14 14:59:14 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FT_PRINTF_H"

int	ft_convert_and_print(va_list ap, const char fmt)
{
	int	ret;

	ret = 0;
	if (fmt == 'c')
		ret += ft_putchar();
	else if (fmt == 's')
		ret += ft_putstr();
	else if (fmt == 'p')
		ret += ft_putpoint();
	else if (fmt == 'd' || fmt == 'i')
		ret += ft_putnbr();
	else if (fmt == 'u')
		ret += ft_putnbr_unsigned();
	else if (fmt == 'u')
		ret += ft_putnbr_unsigned();
	else if (fmt == 'x' || fmt == 'X')
		ret += ft_putnbr_hex();
}

int ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		ret;
	size_t	i;

	i = 0;
	ret = 0;
	va_start(ap, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			if (fmt[i + 1] == '\0')
				break ;
			ret += ft_convert_and_print(ap, fmt[i + 1]);
			i++;
		}
		else
			ret += write(1, &fmt[i], 1);
		i++;
	}
	va_end(ap);
	return (ret);
}

int main()
{
	int	i;

	i = 12;
	foo("Hello%d", i);
	return	(0);
}