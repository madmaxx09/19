/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdor <mdor@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:47:38 by mdor              #+#    #+#             */
/*   Updated: 2022/12/08 12:42:04 by mdor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_calloc(size_t elemCount, size_t elemSize)
{
    void *a;

    a = malloc(elemCount * elemSize);
    if (!a)
        return (NULL);
    ft_bzero(a, elemCount);
    return (a);
}