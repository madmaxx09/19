/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdor <mdor@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:21:54 by mdor              #+#    #+#             */
/*   Updated: 2022/12/13 13:37:21 by mdor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;
	int	len;

	len = ft_strlen(s);
	i = 0;
	if (!s || !f)
		return ;
	while (i < len)
	{
		(*f)(i, s);
		s++;
		i++;
	}
	return ;
}
