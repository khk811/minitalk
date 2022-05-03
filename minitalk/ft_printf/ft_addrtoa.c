/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addrtoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkkim <hyunkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:09:34 by hyunkkim          #+#    #+#             */
/*   Updated: 2022/04/29 21:43:47 by hyunkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_digits_hex(unsigned long long n)
{
	int	ret;

	ret = 0;
	while (n > 15)
	{
		n /= 16;
		ret++;
	}
	ret++;
	return (ret);
}

static unsigned long long	ft_make_divisor_hex(unsigned long long n)
{
	int					i;
	unsigned long long	ret;

	ret = 1;
	i = ft_count_digits_hex(n);
	while (--i > 0)
		ret *= 16;
	return (ret);
}

char	*ft_addrtoa(unsigned long long n)
{
	char				*ret;
	int					i;
	unsigned long long	divisor;

	i = 0;
	divisor = ft_make_divisor_hex(n);
	ret = (char *)malloc(sizeof(char) * (ft_count_digits_hex(n) + 1));
	if (!ret)
		return (NULL);
	while (divisor > 0)
	{
		if (n / divisor > 9)
			ret[i++] = (n / divisor) + 87;
		else
			ret[i++] = (n / divisor) + '0';
		n %= divisor;
		divisor /= 16;
	}
	ret[i] = '\0';
	return (ret);
}
