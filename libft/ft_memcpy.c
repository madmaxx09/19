/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdor <mdor@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:51:27 by mdor              #+#    #+#             */
/*   Updated: 2022/12/07 13:44:36 by mdor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    *ft_memcpy(void *destination, const void *source, size_t n)
{
    char    *dst;
    const char *src;
    size_t  i;

    i = 0;
    if (n == 0 || destination == source)
        return (destination);
    dst = (char *)destination;
    src = (char *)source; 
    while (i < n)
    {
        dst[i] == src[i];
        i++;
    }
    return (destination);
}