/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkkim <hyunkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:26:29 by hyunkkim          #+#    #+#             */
/*   Updated: 2022/02/15 16:06:26 by hyunkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

# define HEX    1
# define UPCASE 2

typedef int	(*t_func)(va_list list);
int		ft_printf(const char *format, ...);
int		ft_parce_tree(const char **s, va_list list);
t_func	ft_get_func(char c);
int		ft_write_char(va_list list);
int		ft_write_str(va_list list);
int		ft_write_addr(va_list list);
int		ft_write_digit(va_list list);
int		ft_write_uns_int(va_list list);
int		ft_write_hex_lo(va_list list);
int		ft_write_hex_up(va_list list);
int		ft_write_percent(va_list list);
int		ft_isspecifier(char c);
char	*ft_uns_itoa(unsigned int n, int flag);
char	*ft_addrtoa(unsigned long long n);
void	ft_free_str(char **str);
int		ft_write_n_free(char **str);
int		ft_write_other(const char *str);

#endif
