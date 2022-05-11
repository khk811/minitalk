/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkkim <hyunkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:44:16 by hyunkkim          #+#    #+#             */
/*   Updated: 2022/05/11 20:49:06 by hyunkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	usleep(100);
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
	if (!(*target_str))
		send_char(server_pid, 0);
	return (0);
}
