/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdor <mdor@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:37:31 by mdor              #+#    #+#             */
/*   Updated: 2023/09/28 17:02:56 by mdor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void quick_sort3(list_diff *list)
{
	if (*(int *)list->stackA->number == list_min(list->stackA) && is_sorted(list->stackA) == 0)
	{
		sort(9, list); //RRA
		sort(1, list); //SA
	}
	else if(*(int *)list->stackA->number == list_max(list->stackA))
	{
		sort(6, list); //RA
		if (*(int *)list->stackA->number != list_min(list->stackA))
			sort(1, list); //SA
	}
	else if (*(int *)list->stackA->number != list_max(list->stackA) && *(int *)list->stackA->number != list_min(list->stackA))
	{
		if(*(int *)ft_lstlast(list->stackA)->number == list_max(list->stackA))
			sort(1, list); //SA
		else if(*(int *)ft_lstlast(list->stackA)->number == list_min(list->stackA))
			sort(9, list); //RRA
	}
}

void execute_sort(list_diff *list)
{	
	if(list->stackA == NULL)	
		return;
	if(list_size(list->stackA) <= 3)
		quick_sort3(list);
	else if (list_size(list->stackA) >= 4 && list_size(list->stackA) <= 5)
		quick_sort4_5(list);
	else
		do_radix(list);
}	

void quick_sort4_5(list_diff *list)
{
	while(list_size(list->stackA) > 3)
	{
		if(*(int*)list->stackA->number == list_min(list->stackA))
			sort(5, list); //PB
		else
			sort(6, list); //RA
	}
	quick_sort3(list);
	while(list->stackB)
		sort(4, list); //PA
}