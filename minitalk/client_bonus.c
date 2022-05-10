/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkkim <hyunkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:24:13 by hyunkkim          #+#    #+#             */
/*   Updated: 2022/05/10 18:28:29 by hyunkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_bit(int pid, int bit)
{
	if (!bit)
		safe_kill(pid, SIGUSR1);
	else
		safe_kill(pid, SIGUSR2);
	usleep(150);
}

void	send_char(int pid, char c)
{
	int	n;

	n = 8;
	while (n--)
		send_bit(pid, c & (1 << n));
}

void	recieve_server_sig(int sig, siginfo_t *info, void *ucontext)
{
	if (sig == SIGUSR1)
		ft_printf("Server has been answered\n");
	if (sig == SIGUSR2)
	{
		ft_printf("Connection end. Goodbye\n");
		exit(0);
	}
	usleep(100);
	info->si_signo = 0;
	ucontext = NULL;
}

void	send_sig_to_server(int server_pid, char *target_str)
{
	safe_kill(server_pid, SIGUSR1);
	usleep(150);
	while (*target_str)
		send_char(server_pid, *(target_str++));
	if (*target_str == 0)
		send_char(server_pid, 0);
}

int	main(int argc, char **argv)
{
	int					server_pid;
	char				*target_str;
	struct sigaction	recieve_sig;

	if (argc != 3)
		print_error(FEW_ARG);
	server_pid = is_str_valid_pid(argv[1]);
	target_str = argv[2];
	sigemptyset(&recieve_sig.sa_mask);
	sigaddset(&recieve_sig.sa_mask, SIGUSR1);
	sigaddset(&recieve_sig.sa_mask, SIGUSR2);
	recieve_sig.sa_sigaction = recieve_server_sig;
	recieve_sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &recieve_sig, NULL);
	sigaction(SIGUSR2, &recieve_sig, NULL);
	send_sig_to_server(server_pid, target_str);
	while (1)
		pause();
	return (0);
}
