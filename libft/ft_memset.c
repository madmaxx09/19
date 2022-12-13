/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdor <mdor@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:51:32 by mdor              #+#    #+#             */
/*   Updated: 2022/12/13 12:53:18 by mdor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *pointer, int value, int count)
{
	char	*ptn;

	ptn = (char *)pointer;
	while (count >= 0)
	{
		ptn[count--] = value;
	}
	return (ptn);
}
