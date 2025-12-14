/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 16:55:18 by yuonishi          #+#    #+#             */
/*   Updated: 2025/12/14 17:50:51 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	size_t	i;

	if (!str)
	{
		write(1, "(NULL)", 6);
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

int	ft_printf_percent(void)
{
	write(1, "%", 1);
	return (1);
}