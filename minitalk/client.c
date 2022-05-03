/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkkim <hyunkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:44:16 by hyunkkim          #+#    #+#             */
/*   Updated: 2022/05/03 19:04:16 by hyunkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	ft_printf("argc => %d\n", argc);
	ft_printf("-> input pid: %s\n", argv[1]);
	ft_printf("-> input string: %s\n", argv[2]);
	return (0);
}
