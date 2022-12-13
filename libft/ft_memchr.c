/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdor <mdor@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:51:19 by mdor              #+#    #+#             */
/*   Updated: 2022/12/13 12:52:58 by mdor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *blc, int c, int t)
{
	const char	*str;
	int			i;

	str = (const char *)blc;
	i = 0;
	while (i < t)
	{
		if (str[i] == c)
			return ((void *)(blc + i));
		i++;
	}
	return (0);
}

/*int main()
{
	char *blc;


}*/