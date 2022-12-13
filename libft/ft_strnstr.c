/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdor <mdor@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:54:14 by mdor              #+#    #+#             */
/*   Updated: 2022/12/13 12:54:16 by mdor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(const char *big, const char *little, unsigned int len)
{
	int	i;
	int	j;

	i = 0;
	if (!little || little[0] == '\0')
		return ((char *)big);
	while (len != 0)
	{
		j = 0;
		while (big[i + j] && (big[i + j] == little[j]))
		{
			if (little[j + 1] == '\0')
				return ((char *)little + i + j);
			j++;
		}
		len--;
		i++;
	}
	return (0);
}
