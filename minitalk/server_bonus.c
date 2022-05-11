/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkkim <hyunkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:46:00 by hyunkkim          #+#    #+#             */
/*   Updated: 2022/05/11 20:52:38 by hyunkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	handler(int n)
{
	static char	input = 0;
	static int	index = 0;

	if (n == SIGUSR1 || n == SIGUSR2)
	{
		input <<= 1;
		if (n == SIGUSR2)
			input++;
		index++;
	}
	if (index >= 8)
	{
		index = 0;
		if (input == 0)
		{
			ft_printf("\n");
			return (0);
		}
		ft_printf("%c", input);
		input = 0;
	}
	return (1);
}

void	send_sig_to_client(int sig, siginfo_t *info, void *ucontext)
{
	static int	client_pid = INIT_PID;
	int			handler_result;

	if (client_pid == INIT_PID)
	{
		client_pid = info->si_pid;
		safe_kill(client_pid, SIGUSR1);
	}
	else
	{
		handler_result = handler(sig);
		if (handler_result)
			safe_kill(client_pid, SIGUSR1);
		else
		{
			safe_kill(client_pid, SIGUSR2);
			client_pid = INIT_PID;
		}
	}
	ucontext = NULL;
}

int	main(void)
{
	int					pid;
	struct sigaction	recieve_bit;

	recieve_bit.sa_sigaction = send_sig_to_client;
	recieve_bit.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &recieve_bit, NULL);
	sigaction(SIGUSR2, &recieve_bit, NULL);
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	while (1)
		pause();
	return (0);
}
