/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkkim <hyunkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:07:21 by hyunkkim          #+#    #+#             */
/*   Updated: 2022/04/29 21:44:06 by hyunkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_func	ft_get_func(char c)
{
	t_func	func_arr[9];
	char	*format_specifiers;
	int		i;

	format_specifiers = "cspdiuxX%";
	func_arr[0] = ft_write_char;
	func_arr[1] = ft_write_str;
	func_arr[2] = ft_write_addr;
	func_arr[3] = ft_write_digit;
	func_arr[4] = ft_write_digit;
	func_arr[5] = ft_write_uns_int;
	func_arr[6] = ft_write_hex_lo;
	func_arr[7] = ft_write_hex_up;
	func_arr[8] = ft_write_percent;
	i = 0;
	while (format_specifiers[i])
	{
		if (c == format_specifiers[i])
			return (func_arr[i]);
		i++;
	}
	return (NULL);
}
