/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkkim <hyunkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:09:32 by hyunkkim          #+#    #+#             */
/*   Updated: 2022/05/12 14:31:09 by hyunkkim         ###   ########seoul.kr  */
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
	exit(1);
}

int	is_pid_valid(int pid)
{
	if (pid > 99 && pid < 100000)
		return (1);
	return (0);
}

int	is_str_valid_pid(char *s)
{
	char	*tmp;
	int		pid;

	tmp = s;
	while (*tmp)
	{
		if (!ft_isdigit(*tmp))
			print_error(PID_INVAL);
		tmp++;
	}
	pid = ft_atoi(s);
	if (!is_pid_valid(pid))
		print_error(PID_INVAL);
	return (pid);
}

void	safe_kill(int pid, int signo)
{
	if (kill(pid, signo) == -1)
		print_error(KILL_FAIL);
}
