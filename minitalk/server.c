/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkkim <hyunkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:44:14 by hyunkkim          #+#    #+#             */
/*   Updated: 2022/05/10 14:45:04 by hyunkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int n)
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
		ft_printf("%c", input);
		input = 0;
		index = 0;
	}
}

int	main(void)
{
	int	pid;

	signal(SIGUSR1, &handler);
	signal(SIGUSR2, &handler);
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	while (1)
		pause();
}
