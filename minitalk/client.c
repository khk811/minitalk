/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkkim <hyunkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:44:16 by hyunkkim          #+#    #+#             */
/*   Updated: 2022/05/03 19:34:07 by hyunkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_error(void)
{
	ft_printf("Error\n");
	ft_printf("too few argument: need pid and string\n");
	exit(1);
}

void	send_bit(int pid, int bit)
{
	if (!bit)
	{
		kill(pid, SIGUSR1);
		usleep(150);
	}
	else
	{
		kill(pid, SIGUSR2);
		usleep(150);
	}
}

void	send_char(int pid, char c)
{
	send_bit(pid, c & 1<<7);
	send_bit(pid, c & 1<<6);
	send_bit(pid, c & 1<<5);
	send_bit(pid, c & 1<<4);
	send_bit(pid, c & 1<<3);
	send_bit(pid, c & 1<<2);
	send_bit(pid, c & 1<<1);
	send_bit(pid, c & 1<<0);
}

int	main(int argc, char **argv)
{
	int		server_pid;
	char	*target_str;

	if (argc < 3)
		print_error();
	server_pid = ft_atoi(argv[1]);
	target_str = argv[2];
	ft_printf("target-> %s\n", target_str);
	while (*target_str)
		send_char(server_pid, *(target_str++));
	return (0);
}
