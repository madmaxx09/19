/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdor <mdor@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:15:07 by mdor              #+#    #+#             */
/*   Updated: 2023/10/03 12:46:05 by mdor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

list_init *createNode(int *i)
{
	list_init *newNode;
	
	newNode = malloc(sizeof(list_init));
	if (!newNode)
		return (0);
	newNode->number = i;
	newNode->prev = NULL;
	newNode->next = NULL;
	return(newNode);
}

void free_list(list_diff *list)
{
	list_init	*placeholderA;
	list_init	*placeholderB;
	list_init	*temp;
	
	if(list->stackA)
		placeholderA = list->stackA;
	if(list->stackB)
		placeholderB = list->stackB;
	while(placeholderA)
	{
		if(placeholderA->number)
			free(placeholderA->number);
		temp = placeholderA->next;
		free(placeholderA);
		placeholderA = temp;
	}
	while (placeholderB)
	{
		if(placeholderB->number)
			free(placeholderB->number);
		temp = placeholderB->next;
		free(placeholderB);
		placeholderB = temp;
	}	
}

void add_node_top(list_init **top, list_init *newNode)
{
	if(top && newNode)
	{
		newNode->next = *top;
		newNode->prev = NULL;
		if (*top)
			(*top)->prev = newNode;
		*top = newNode; 
	}
}


void	ft_lst_add_back(list_init **address_lst, list_init *new_node)
{
	list_init	*tmp;

	if (address_lst && new_node)
	{
		if (!*address_lst)
		{
			*address_lst = new_node;
			new_node->prev = NULL;
		}
		else
		{
			tmp = ft_lstlast(*address_lst);
			tmp->next = new_node;
			new_node->prev = tmp;
		}
		new_node->next = NULL;
	}
}

list_init	*ft_lstlast(list_init *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
		lst->next = NULL;
	}
	return (lst);
}

int	list_size(list_init *list)
{
	int	i;

	i = 1;
	while(list->next)
	{
		list = list->next;
		i++;
	}
	return (i);
}

int list_max(list_init *list)
{
	int	i; 

	i = *(int *)list->number;
	while(list->next)
	{
		if(i < *(int *)list->next->number)
			i = *(int *)list->next->number;
		list = list->next;		
	}
	return (i);
} 

int list_min(list_init *list)
{
	int	i;

	i = *(int *)list->number;
	while(list->next)
	{
		if(i > *(int *)list->next->number)
			i = *(int *)list->next->number;
		list = list->next;		
	}
	return (i);
}