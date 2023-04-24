/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdor <mdor@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:52:45 by mdor              #+#    #+#             */
/*   Updated: 2023/04/24 18:34:12 by mdor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putstring(char *str)
{
	int	i;

	if (!str)
		return ;
	while (str[i])
	{
		ft_putchr(str[i]);
		i++;
	}
	return (i);
}

int	ft_putchr(char c)
{
	write(1, &c, 1);
	return(1);
}
