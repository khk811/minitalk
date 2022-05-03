/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkkim <hyunkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:30:34 by hyunkkim          #+#    #+#             */
/*   Updated: 2022/02/15 16:02:55 by hyunkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isspecifier(char c)
{
	char	*the_specifier;

	the_specifier = "cspdiuxX%";
	while (*the_specifier)
	{
		if (*the_specifier == c)
			return (1);
		the_specifier++;
	}
	return (0);
}
