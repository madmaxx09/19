/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdor <mdor@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:34:19 by mdor              #+#    #+#             */
/*   Updated: 2023/10/03 12:36:29 by mdor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

// Function to fill stackA with numbers
static void fillA(int argc, char **argv, list_diff *list)
{
    int			*num;
	int				i;
    list_init	*newNode;
	
	i = 1;
	while(i < argc)
	{
		num = malloc(sizeof(int));
		if(!num)
			return;
		*num = ft_atoi(argv[i]);
		newNode = createNode(num);
		if(!newNode)
		{
			free_list(list);
			return;
		}
		ft_lst_add_back(&list->stackA, newNode);
		i++;
	}
}

static void push_swap(int argc, char **argv)
{
    list_diff list;
    
	list.stackA = NULL;
    list.stackB = NULL;
	//fill stackA with given args
    fillA(argc, argv, &list);
	if(list.stackA == NULL)
		return;
	if(is_sorted(list.stackA) == 0)
		execute_sort(&list);
	free_list(&list);
}

int main (int argc, char **argv)
{
	if (argc == 1 || check_args(argv) == 0)
		{
			ft_putstr_fd("Error : the input does not respect the rules\n", 2);
			exit(1);
		}
	push_swap(argc, argv); 
	return (0);
}