/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdor <mdor@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 10:29:29 by mdor              #+#    #+#             */
/*   Updated: 2022/12/13 12:32:39 by mdor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_isinset(char c, char const *set)
{
	int	k;

	k = 0;
	while (set)
	{
		if (set[k] == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		l;
	char	*new;
	int		finallen;

	i = 0;
	j = ft_strlen((char *)s1);
	l = 0;
	while (ft_isinset(s1[i], set) == 1)
		i++;
	while (ft_isinset(s1[j], set) == 1)
		j--;
	finallen = j - i;
	new = malloc(sizeof(char) * (finallen + 1));
	while (i++ < j)
	{
		new[l++] = s1[i];
	}
	return (new);
}
