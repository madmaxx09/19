/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdor <mdor@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:50:17 by mdor              #+#    #+#             */
/*   Updated: 2022/12/08 18:03:10 by mdor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_isalnum(int digit)
{
    if (digit >= 48 && digit <= 57)
        return (1);
    if (digit >= 65 && digit <= 90)
        return (1);
    if (digit >= 97 && digit <= 122)
        return (1);
    else
        return (0);   
}

int main ()
{
    char c;
    c = 'a';
    printf("%d\n", ft_isalnum(c));
}