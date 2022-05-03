/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkkim <hyunkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:10:24 by hyunkkim          #+#    #+#             */
/*   Updated: 2022/04/29 21:46:05 by hyunkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_char(va_list list)
{
	char	arg_char;
	int		ret;

	arg_char = va_arg(list, int);
	ret = write(1, &arg_char, 1);
	if (ret < 1)
		ret = -1;
	return (ret);
}
