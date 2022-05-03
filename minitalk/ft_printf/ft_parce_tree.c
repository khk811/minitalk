/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parce_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkkim <hyunkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:07:44 by hyunkkim          #+#    #+#             */
/*   Updated: 2022/02/16 20:11:18 by hyunkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parce_tree(const char **s, va_list list)
{
	int	ret;

	ret = -1;
	if (ft_get_func(**s))
	{
		ret = ft_get_func(**s)(list);
		*s += 1;
	}
	return (ret);
}
