/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdor <mdor@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:49:09 by mdor              #+#    #+#             */
/*   Updated: 2022/12/11 12:51:45 by mdor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char *ft_strdup(const char *source)
{
    void *a;
    int i;

    i = 0;
    while (source[i])
        i++;
    a = malloc(sizeof(char)*(i + 1));
    if (!a)
        return (NULL);
    
}