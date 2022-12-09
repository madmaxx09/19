/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdor <mdor@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:46:30 by mdor              #+#    #+#             */
/*   Updated: 2022/12/09 10:12:59 by mdor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
    int i;
    int j;
    char *new;

    i = ft_strlen(s1);
    j = ft_strlen(s2);

    new = malloc(sizeof(char) * (i + j + 1));
    if (!new)
        return (NULL);
    i = 0;
    j = 0;

    while (s1[i])
    {
        new[j++] = s1[i];
        i++;
    }
    i = 0;
    while (s2[i])
    {
        new[j++] = s2[i];
        i++;
    }
    new[j] = '\0';
    return (new);    
}