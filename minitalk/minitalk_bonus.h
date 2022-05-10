/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkkim <hyunkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:44:38 by hyunkkim          #+#    #+#             */
/*   Updated: 2022/05/10 18:27:07 by hyunkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "libft.h"
# include "ft_printf.h"
# include <signal.h>

# define PID_INVAL	1
# define FEW_ARG	2
# define KILL_FAIL	3
# define SIG_INVAL	4
# define INIT_PID	80808080

void	print_error(int err_num);
int		is_str_valid_pid(char *s);
int		is_pid_valid(int pid);
void	safe_kill(int pid, int signo);

#endif
