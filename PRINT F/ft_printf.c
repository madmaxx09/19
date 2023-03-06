/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdor <mdor@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 11:53:05 by mdor              #+#    #+#             */
/*   Updated: 2023/03/02 17:25:29 by mdor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int	ft_printf(const char *str, ...)
{
	int	i;
	va_list	arguments;
	
	va_start(arguments, *str)
	while(str[i])
	{
		ft_form(str[i])
	}
	return ();
}

int main()
{
	ft_printf("%d\n",)
}

