/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdor <mdor@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:50:32 by mdor              #+#    #+#             */
/*   Updated: 2022/12/08 18:03:36 by mdor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isalpha(char c)
{
    if (c >= 65 && c <= 90)
        return (1);
    if (c >= 97 && c <= 122)
        return (1);
    else
        return (0);
}

#include <stdio.h>
int main ()
{
    char a;
    a = '1';
    printf ("%d\n",(ft_isalpha(a)));
}