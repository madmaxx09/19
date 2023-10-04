/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdor <mdor@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:07:52 by mdor              #+#    #+#             */
/*   Updated: 2023/09/28 17:02:42 by mdor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void swap(list_init **front)
{
	list_init *new_front;

	if(front && list_size(*front) > 1)
	{
		new_front = (*front)->next;
		(*front)->next = new_front->next;
		if(new_front->next)
			new_front->next->prev = (*front);
		add_node_top(front, new_front);
	}
}

void push(list_init **src, list_init **dest)
{
	list_init *newNode;

	if (src && *src && dest)
	{
		newNode = (*src)->next;
		if (newNode)
			newNode->prev = NULL;
		add_node_top(dest, *src);
		*src = newNode;
	}
}

void rotate(list_init **list)
{
	list_init *newNode;
	
	if(list && list_size(*list) > 1)
	{
		newNode = (*list)->next;
		newNode->prev = NULL;
		ft_lst_add_back(list, *list);
		*list = newNode;
	}
}

void reverse_rotate(list_init **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    list_init *lastNode = *list;
    while (lastNode->next != NULL)
    {
        lastNode = lastNode->next;
    }

    // Remove lastNode from its current position
    if (lastNode->prev)
        lastNode->prev->next = NULL;

    // Add lastNode to the front of the list
    lastNode->next = *list;
    lastNode->prev = NULL;
    (*list)->prev = lastNode;
    *list = lastNode;
}
