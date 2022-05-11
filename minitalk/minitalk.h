/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkkim <hyunkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:44:38 by hyunkkim          #+#    #+#             */
/*   Updated: 2022/05/11 20:44:21 by hyunkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"
# include "ft_printf.h"
# include <signal.h>

# define PID_INVAL	1
# define FEW_ARG	2
# define KILL_FAIL	3

void	print_error(int err_num);
int		is_str_valid_pid(char *s);
void	safe_kill(int pid, int signo);

#endif
