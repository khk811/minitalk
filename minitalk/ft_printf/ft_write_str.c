/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkkim <hyunkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:10:39 by hyunkkim          #+#    #+#             */
/*   Updated: 2022/04/29 21:47:49 by hyunkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_str(va_list list)
{
	char	*arg_str;
	int		ret;

	arg_str = va_arg(list, char *);
	if (!arg_str)
	{
		ret = write(1, "(null)", ft_strlen("(null)"));
		if (ret < (int)ft_strlen("(null)"))
			ret = -1;
	}
	else
	{
		ret = write(1, arg_str, ft_strlen(arg_str));
		if (ret < (int)ft_strlen(arg_str))
			ret = -1;
	}
	return (ret);
}
