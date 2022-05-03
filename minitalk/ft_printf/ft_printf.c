/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkkim <hyunkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:29:15 by hyunkkim          #+#    #+#             */
/*   Updated: 2022/04/29 21:44:23 by hyunkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		ret;
	int		ret_before;

	va_start(list, format);
	ret = 0;
	while (*format)
	{
		ret_before = ret;
		if (*format == '%')
		{
			format++;
			ret += ft_parce_tree(&format, list);
		}
		else
			ret += ft_write_other(format++);
		if (ret_before > ret)
		{
			ret = -1;
			break ;
		}
	}
	va_end(list);
	return (ret);
}
