/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdor <mdor@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 10:14:37 by mdor              #+#    #+#             */
/*   Updated: 2022/12/09 10:22:08 by mdor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *new;
    int i;

    new = malloc(sizeof(char) * len);
    i = 0;

    while(i < len)
    {
        new[i] = s[start + i];
        i++;
    }
    new[i] = '\0';
    return (new);    
}