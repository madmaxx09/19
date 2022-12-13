/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdor <mdor@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:54:24 by mdor              #+#    #+#             */
/*   Updated: 2022/12/13 12:51:59 by mdor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int digit)
{
	if (digit >= 97 && digit <= 122)
	{
		digit -= 32;
		return (digit);
	}
	else
		return (digit);
}
