/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdor <mdor@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:12:17 by mdor              #+#    #+#             */
/*   Updated: 2023/09/28 18:21:06 by mdor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

static void do_the_thing(list_diff *list, int i)
{
	int	j;
	int	maxBits;
	int	bigNUM;
	int	size;
	
	size = list_size(list->stackA);
	maxBits = 0;
	maxBits = bits_management(list, maxBits);
	while(i < maxBits)
	{
		j = 0;
		while(j < size)
		{
			bigNUM = *(int *)list->stackA->number;
			if (((bigNUM >> i) & 1) == 1)
				sort(6, list); //RA
			else
				sort(5, list); //PB
			j++;
		}
		while(list->stackB)
			sort(4, list); //PA
		i++;
	}
}

void do_radix(list_diff *list)
{
	list_init	*node;
	int			i;

	i = 0;
	node = list->stackA;
	while (node)
	{
		node->index = findIndex(list->stackA, *(int *)node->number);
		node = node->next;
	}
	node = list->stackA;
	while (node)
	{
		*(int *)node->number = node->index;
		node = node->next;
	}
	do_the_thing(list, i);
}

int findIndex(list_init *stackA, int i)
{
	list_init	*node;
	int			index;

	node = stackA;
	index = 0;
	while(node != NULL)
	{
		if (*(int *)node->number < i)
			index++;
		node = node->next;
	}
	return (index);
}

int bits_management(list_diff *list, int maxBits)
{
	int size; 
	int num_max;

	size = list_size(list->stackA);
	num_max = size - 1;
	while ((num_max >> maxBits) != 0)
		maxBits++;
	return(maxBits);
}
