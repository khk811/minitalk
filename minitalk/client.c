/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkkim <hyunkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:44:16 by hyunkkim          #+#    #+#             */
/*   Updated: 2022/05/10 16:56:41 by hyunkkim         ###   ########seoul.kr  */
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
	if (pid < 100 || pid > 99998)
		print_error(PID_INVAL);
	return (pid);
}

void	send_bit(int pid, int bit)
{
	if (!bit)
	{
		if (kill(pid, SIGUSR1) == -1)
			print_error(KILL_FAIL);
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
			print_error(KILL_FAIL);
	}
	usleep(150);
}

void	send_char(int pid, char c)
{
	int	n;

	n = 8;
	while (n--)
		send_bit(pid, c & (1 << n));
}

int	main(int argc, char **argv)
{
	int		server_pid;
	char	*target_str;

	if (argc < 3)
		print_error(FEW_ARG);
	server_pid = is_str_valid_pid(argv[1]);
	target_str = argv[2];
	while (*target_str)
		send_char(server_pid, *(target_str++));
	return (0);
}
