/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argscheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdor <mdor@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:20:46 by mdor              #+#    #+#             */
/*   Updated: 2023/09/28 18:19:55 by mdor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	ft_atoi(const char *str)
{
	long int	famoso;
	int			neg;
	long int	prot;

	famoso = 0;
	neg = 1;
	prot = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		neg *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		famoso = famoso * 10 + (*str - 48);
		if (neg == -1 && prot > famoso)
			return (0);
		if (neg == 1 && prot > famoso)
			return (-1);
		prot = famoso;
		str++;
	}
	return (famoso * neg);
}

static int is_digit(char *arg)
{
	int	i;
	
	i = 0;
	if (arg[i] == 45 && arg[i + 1])
			i++;
	while(arg[i])
	{
		if (arg[i] >= 48 && arg[i] <= 57)
			i++;
		else
			return(1);
	}
	return (0);	
}
static int double_num (char **argv)
{
	int	i;
	int	j;
	int num;
	int	num1;
	
	i = 1;
	j = 2;
	while(argv[i])
	{
		num = ft_atoi(argv[i]);
		j = i + 1;
;		while(argv[j])
		{
			num1 = ft_atoi(argv[j]);
			if (num == num1)
				return(1);
			j++;
		}
		i++;
	}
	return (0);
}

static int digit_check(char **argv)
{
	int	i;
	
	i = 1;
	while(argv[i])
	{
		if(is_digit(argv[i]) == 0)
			i++;
		else
			return(1);
	}
	return (0);
}

int check_args(char **argv)
{
	if (argv[1] == NULL)
		return (0);
	if (double_num(argv) == 1)
		return (0);
	if (digit_check(argv) == 1)
		return (0);
	else
		return (1);
}
	