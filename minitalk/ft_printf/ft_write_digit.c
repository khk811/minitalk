/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkkim <hyunkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:10:27 by hyunkkim          #+#    #+#             */
/*   Updated: 2022/04/29 21:46:20 by hyunkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_digit(va_list list)
{
	int		arg_num;
	char	*ret_str;
	int		ret;

	ret = 0;
	arg_num = va_arg(list, int);
	ret_str = ft_itoa(arg_num);
	ret = ft_write_n_free(&ret_str);
	return (ret);
}
