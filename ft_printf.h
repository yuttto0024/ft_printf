/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 11:41:26 by yuonishi          #+#    #+#             */
/*   Updated: 2025/12/14 18:40:48 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#typedef (* t_convert_formatter)(va_list);

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_printf(const char *, ...);

#endif