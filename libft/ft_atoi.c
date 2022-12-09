/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdor <mdor@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:05:14 by mdor              #+#    #+#             */
/*   Updated: 2022/12/08 17:52:05 by mdor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int     ft_atoi(char *str)
{
        int     famoso;
        int     neg;

        famoso = 0;
        neg = 1;
        while (*str == 32 || (*str >= 9 && *str <= 13))
                str++;
        if (*str == '-')
                neg *= -1;
        str++;
        while (*str >= '0' && *str <= '9')
        {
                famoso = famoso * 10 + (*str - 48);
                str++;
        }
        return (famoso * neg);
}
int main ()
{
        char test[] = "    \t\v\n\r\f    -1234ab567";
        printf("%d\n", atoi(test));
        printf("%d\n", ft_atoi(test));
}