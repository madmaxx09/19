/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdor <mdor@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:50:57 by mdor              #+#    #+#             */
/*   Updated: 2022/11/25 13:53:42 by mdor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isascii (int c)
{
    if (c > 0 && c < 128)
        return (c);
    else
        return (0);
}

/*#include <stdio.h>
int main()
{
    char a;

    a = 'a';
    printf ("%d\n", ft_isascii(a));
}*/