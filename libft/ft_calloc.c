/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdor <mdor@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:47:38 by mdor              #+#    #+#             */
/*   Updated: 2022/12/13 12:34:26 by mdor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(int elemCount, int elemSize)
{
	void	*a;

	a = malloc(elemCount * elemSize);
	if (!a)
		return (NULL);
	ft_bzero(a, elemCount);
	return (a);
}
