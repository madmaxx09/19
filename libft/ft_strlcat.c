/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdor <mdor@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:52:59 by mdor              #+#    #+#             */
/*   Updated: 2022/11/24 18:53:58 by mdor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strlcat(char *source, char *destination)
{
    int i;
    int j;

    i = 0;
    while (source[i])
    {
        i++;
    }
    while (destination[j])
    {
        source[i] = destination[j];
        i++;
        j++;
    }
    return (source);
}