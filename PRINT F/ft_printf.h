/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdor <mdor@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:01:44 by mdor              #+#    #+#             */
/*   Updated: 2023/04/24 18:33:21 by mdor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <starg.h>
#include <stdlib.h>
#include <stdio.h>

int		ft_putstring(char *str);
int		ft_putchr(char c);
int 	ft_putint(int n);
int 	ft_putpourcent(void);
int		ft_manage(char prefix, va_list arguments);
int		ft_printf(const char *str, ...);
int 	ft_prefixcheck(char c);
char	*ft_itoa(int n);

#endif