/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdor <mdor@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:47:38 by mdor              #+#    #+#             */
/*   Updated: 2022/12/11 12:17:39 by mdor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
void    ft_bzero(void *s, size_t n)
{
    int i;
    char *vo;

    i = 0;
    vo = (char *)s;
    while(i < n)
    {
        vo[i] = '\0';
        i++;
    }
}

/*int main ()
{
    char test;
    test [] = 'test';
    printf("%s\n", ft_bzero(test));
}*/
