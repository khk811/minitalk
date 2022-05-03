/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uns_itoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkkim <hyunkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:10:00 by hyunkkim          #+#    #+#             */
/*   Updated: 2022/04/29 21:45:05 by hyunkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_digits(unsigned int n, int flag)
{
	int	ret;

	ret = 0;
	if (flag & HEX)
	{
		while (n > 15)
		{
			n /= 16;
			ret++;
		}
	}
	else
	{
		while (n > 9)
		{
			n /= 10;
			ret++;
		}
	}
	ret++;
	return (ret);
}

static unsigned int	ft_make_divisor(unsigned int n, int flag)
{
	int				i;
	unsigned int	ret;

	ret = 1;
	i = ft_count_digits(n, flag);
	if (flag & HEX)
	{
		while (--i > 0)
			ret *= 16;
	}
	else
	{
		while (--i > 0)
			ret *= 10;
	}
	return (ret);
}

static char	*ft_str_hex(char *arr, unsigned int n, int flag)
{
	unsigned int	divisor;
	int				i;

	i = 0;
	divisor = ft_make_divisor(n, flag);
	while (divisor > 0)
	{
		if (n / divisor > 9 && flag & UPCASE)
			arr[i++] = (n / divisor) + 55;
		else if (n / divisor > 9)
			arr[i++] = (n / divisor) + 87;
		else
			arr[i++] = (n / divisor) + '0';
		n %= divisor;
		divisor /= 16;
	}
	arr[i] = '\0';
	return (arr);
}

char	*ft_uns_itoa(unsigned int n, int flag)
{
	char			*ret;
	int				i;
	unsigned int	divisor;

	i = 0;
	ret = (char *)malloc(sizeof(char) * (ft_count_digits(n, flag) + 1));
	if (!ret)
		return (NULL);
	if (flag & HEX)
		ret = ft_str_hex(ret, n, flag);
	else
	{
		divisor = ft_make_divisor(n, flag);
		while (divisor > 0)
		{
			ret[i++] = (n / divisor) + '0';
			n %= divisor;
			divisor /= 10;
		}
		ret[i] = '\0';
	}
	return (ret);
}
