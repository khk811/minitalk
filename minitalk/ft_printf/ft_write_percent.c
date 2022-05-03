/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkkim <hyunkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:10:37 by hyunkkim          #+#    #+#             */
/*   Updated: 2022/02/15 17:11:06 by hyunkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_percent(va_list list)
{
	int	ret;

	list = 0;
	ret = write(1, "%", 1);
	if (ret < 1)
		ret = -1;
	return (ret);
}
