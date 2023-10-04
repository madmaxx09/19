/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdor <mdor@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:52:35 by mdor              #+#    #+#             */
/*   Updated: 2023/10/03 12:37:37 by mdor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct linked_list
{
	int index;
	void *number;
	struct linked_list *prev;
	struct linked_list *next;
} list_init;


typedef struct push_swap
{
	list_init *stackA;
	list_init *stackB;
}	list_diff;

//utils 

int	ft_atoi(const char *str);
int is_sorted(list_init *list);
int	ft_strlen(char *str);
void	ft_putstr_fd(char *str, int fd);
void free_list(list_diff *list);

//arguments verification

int check_args(char **argv);

//operations//

void sort(int op, list_diff *list);
void swap(list_init **front);
void 	rotate(list_init **list);
void 	push(list_init **src, list_init **dest);
void 	reverse_rotate(list_init **list);

//listops

void add_node_top(list_init **top, list_init *newNode);
void add_node_bottom(list_init **list, list_init *newNode);
void	ft_lst_add_back(list_init **address_lst, list_init *new_node);
list_init *createNode(int *i);
list_init	*ft_lstlast(list_init *lst);
int	list_size(list_init *list);
int list_min(list_init *list);
int list_max(list_init *list);

//algo setup 

void 	execute_sort(list_diff *list);
void do_radix(list_diff *list);
void quick_sort3(list_diff *list);
void quick_sort4_5(list_diff *list);
int bits_management(list_diff *list, int maxBits);
int findIndex(list_init *stackA, int i);

#endif