/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_looping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 22:16:38 by mbutt             #+#    #+#             */
/*   Updated: 2019/12/15 22:35:56 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Passes examshell.
** Also known as Linked List cycle and floyd cycle
** Memory address of the pointers get compared
*/

#include <stdio.h>
#include <stdlib.h>

struct		s_node
{
	int				value;
	struct s_node	*next;
};

typedef struct s_node t_node;

int is_looping(t_node *node)
{
	t_node *slow;
	t_node *fast;

	slow = node;
	fast = node;

	while(slow && fast)
	{
		slow = slow->next;
		fast = fast->next;
		if(fast)
			fast = fast->next;
		if(fast && slow && fast == slow)
			return(1);
	}
	return(0);
}

/*
t_node *create_node()
{
	t_node *new_node;

	new_node = malloc(sizeof(t_node));
	new_node->next = NULL;
	return(new_node);
}

int main(void)
{
	t_node *a;
	
	a = create_node();
	a->next = create_node(); 
	printf("|%d|\n", is_looping(a));
	a->next->next = create_node();
	printf("|%d|\n", is_looping(a));
	a->next->next->next = create_node();
	printf("|%d|\n", is_looping(a));
	a->next->next->next->next = create_node();
	printf("|%d|\n", is_looping(a));
	a->next->next->next->next->next = a;
	printf("|%d|\n", is_looping(a));
}
*/
