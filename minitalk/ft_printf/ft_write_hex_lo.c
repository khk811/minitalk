/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hex_lo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkkim <hyunkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:10:31 by hyunkkim          #+#    #+#             */
/*   Updated: 2022/04/29 21:46:45 by hyunkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_hex_lo(va_list list)
{
	unsigned int	arg_num;
	char			*ret_str;
	int				ret;

	arg_num = va_arg(list, unsigned int);
	ret_str = ft_uns_itoa(arg_num, 1);
	ret = ft_write_n_free(&ret_str);
	return (ret);
}
