/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkkim <hyunkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:44:16 by hyunkkim          #+#    #+#             */
/*   Updated: 2022/05/10 14:45:22 by hyunkkim         ###   ########seoul.kr  */
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
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
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
		print_error();
	server_pid = ft_atoi(argv[1]);
	target_str = argv[2];
	ft_printf("target-> %s\n", target_str);
	while (*target_str)
		send_char(server_pid, *(target_str++));
	return (0);
}
