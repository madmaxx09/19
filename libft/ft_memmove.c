/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdor <mdor@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:51:30 by mdor              #+#    #+#             */
/*   Updated: 2022/12/11 12:39:34 by mdor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    *ft_memmove(void *destination, const void *source, int n)
{
    char *dest;
    char *src;

    dest = (char *)destination;
    src = (char *)source;
    
    if (!source)
        return (0);
    if (destination == source)
        return (destination);
    while (n != 0)
    {
        dest[n] = src[n];
        n--;
    }
    return (destination);   
}