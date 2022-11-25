/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdor <mdor@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:53:11 by mdor              #+#    #+#             */
/*   Updated: 2022/11/25 17:32:38 by mdor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int strncmp(const char *first, const char *second, size_t n)
{
    int i;

    i = 0;
    if (n == 0)
        return (0);
    while (i <= n && first[i] != '\0' && second[i] != '\0')
    {
        if (first[i] != second[i])
            return (first[i] - second[i]);
        i++;
    }
    return (0);
}