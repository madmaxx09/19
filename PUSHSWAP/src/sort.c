/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdor <mdor@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:26:49 by mdor              #+#    #+#             */
/*   Updated: 2023/09/30 11:57:17 by mdor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void sort(int op, list_diff *list)
{
	//SA SS
	if (op == 1 || op == 3)
	{
		swap(&list->stackA);
		if(op == 3)
			write(1, "ss\n", 3);
		else
			write(1, "sa\n", 3);
	}
	//SB SS
	if (op == 2 || op == 3)
	{
		swap(&list->stackB);
		if (op == 2)	
			write(1, "sb\n", 3);
	}
	//PA
	if (op == 4)
	{
		push(&list->stackB, &list->stackA);	
		write(1, "pa\n", 3);	
	}
	//PB
	if (op == 5)
	{
		push(&list->stackA, &list->stackB);		
		write(1, "pb\n", 3);		
	}
	//RA RR
	if (op == 6 || op == 8)
	{
		rotate(&list->stackA);
		if (op == 8)
			write(1, "rr\n", 3);
		else	
			write(1, "ra\n", 3);	
	}
	//RB RR
	if (op == 7 || op == 8)
	{
		rotate(&list->stackB);
		if (op == 7)
			write(1, "rb\n", 3);		
	}
	//RRA RRR
	if (op == 9 || op == 11)
	{
		reverse_rotate(&list->stackA);
		if (op == 11)
			write(1, "rrr\n", 4);
		else
			write(1, "rra\n", 4);	
	}
	//RRB RRR
	if (op == 10 || op == 11)
	{
		reverse_rotate(&list->stackB);	
		if (op == 10)	
			write(1, "rrb\n", 4);
	}
}