/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkkim <hyunkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:10:14 by hyunkkim          #+#    #+#             */
/*   Updated: 2022/02/16 19:46:09 by hyunkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_free_str(char **str)
{
	if (!(*str))
		return ;
	free(*str);
	*str = NULL;
}

int	ft_write_n_free(char **str)
{
	int	ret;
	int	expected;

	if (!(*str))
		ret = -1;
	else
	{
		expected = (int)ft_strlen(*str);
		ret = write(1, *str, expected);
		if (ret < expected)
			ret = -1;
		ft_free_str(str);
	}
	return (ret);
}

int	ft_write_other(const char *str)
{
	int	ret;

	ret = write(1, str, 1);
	if (ret < 1)
		ret = -1;
	return (ret);
}
