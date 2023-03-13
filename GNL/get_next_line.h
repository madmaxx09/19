/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdor <mdor@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:21:42 by mdor              #+#    #+#             */
/*   Updated: 2023/03/12 19:41:11 by mdor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <limits.h>

size_t		ft_strlen(const char *str);
char		*ft_strjoin(char *stock, char *buff);
char		*ft_strchr(char *s, int c);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);

#endif 