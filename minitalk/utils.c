/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkkim <hyunkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:09:32 by hyunkkim          #+#    #+#             */
/*   Updated: 2022/05/10 17:09:56 by hyunkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_error(int err_num)
{
	ft_printf("Error\n");
	if (err_num == FEW_ARG)
		ft_printf("Too Few Argument: need pid and string\n");
	else if (err_num == PID_INVAL)
		ft_printf("PID is invalid\n");
	else if (err_num == KILL_FAIL)
		ft_printf("Kill failed\n");
	else if (err_num == SIG_INVAL)
		ft_printf("Detect Wrong Signal\n");
	exit(1);
}
