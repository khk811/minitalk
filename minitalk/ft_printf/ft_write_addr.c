/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkkim <hyunkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:10:19 by hyunkkim          #+#    #+#             */
/*   Updated: 2022/04/29 21:45:39 by hyunkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_apply_alter(char **arr)
{
	char	*ret;

	if (!(*arr))
		return (NULL);
	ret = "0x";
	ret = ft_strjoin(ret, *arr);
	ft_free_str(arr);
	return (ret);
}

int	ft_write_addr(va_list list)
{
	unsigned long long	addr;
	char				*ret_str;
	int					ret;

	addr = (unsigned long long)(va_arg(list, void *));
	ret_str = ft_addrtoa(addr);
	ret_str = ft_apply_alter(&ret_str);
	ret = ft_write_n_free(&ret_str);
	return (ret);
}
