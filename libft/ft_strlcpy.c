/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdor <mdor@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:53:04 by mdor              #+#    #+#             */
/*   Updated: 2022/11/24 18:53:58 by mdor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char* strcpy(char* destination, char* source)
{
    int i;

    i = 0; 
    while (source[i])
    {
        destination[i] = source[i];
        i++;
    }
    return (destination);
}