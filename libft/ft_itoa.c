/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdor <mdor@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:33:27 by mdor              #+#    #+#             */
/*   Updated: 2022/12/13 12:52:42 by mdor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_length(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= 1)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_do(char *new, int len, long nbr, int neg)
{
	new[len] = '\0';
	if (neg == 0)
		nbr = -nbr;
	while (--len >= 0)
	{
		new[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (neg == 0)
		new[0] = '-';
	return (new);
}

char	*ft_itoa(int n)
{
	char	*new;
	int		len;
	int		neg;
	long	nbr;

	nbr = n;
	neg = 1;
	if (n < 0)
		neg = 0;
	len = ft_length(nbr);
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	return (new = ft_do(new, len, nbr, neg));
}

/*#include <stdio.h>

int main()
{
	printf("%s\n", ft_itoa(10));
}*/