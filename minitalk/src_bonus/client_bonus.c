/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkkim <hyunkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:24:13 by hyunkkim          #+#    #+#             */
/*   Updated: 2022/05/11 20:36:54 by hyunkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_bit(int pid, int bit)
{
	if (!bit)
		safe_kill(pid, SIGUSR1);
	else
		safe_kill(pid, SIGUSR2);
}

void	send_char(int pid)
{
	static int	n = 7;

	if (n < 0)
	{
		(g_info.str)++;
		n = 7;
	}
	if (n >= 0)
	{
		if (*(g_info.str))
			send_bit(pid, *(g_info.str) & (1 << n));
		else
			send_bit(pid, 0 & (1 << n));
		n--;
	}
}

void	recieve_server_sig(int sig)
{
	static int	sig_count = 0;

	if (sig == SIGUSR1)
	{
		send_char(g_info.pid);
		sig_count++;
	}
	else
	{
		ft_printf("Total %d signal received.\n", sig_count);
		sig_count = 0;
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		print_error(FEW_ARG);
	g_info.pid = is_str_valid_pid(argv[1]);
	g_info.str = argv[2];
	signal(SIGUSR1, &recieve_server_sig);
	signal(SIGUSR2, &recieve_server_sig);
	safe_kill(g_info.pid, SIGUSR1);
	while (1)
		pause();
	return (0);
}
