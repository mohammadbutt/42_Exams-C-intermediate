/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 20:00:11 by mbutt             #+#    #+#             */
/*   Updated: 2019/12/15 21:44:31 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Passes examshell
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct		s_node
{
	int				value;
	struct s_node 	**nodes;
}					t_node;

void update_max(int current_value, int *max)
{
	if(current_value > *max)
		*max = current_value;
}


void find_height_recursively(t_node *root, int height, int *max)
{
	int i;

	i = 0;
	if(root != NULL)
	{
		update_max(height, max);
		while(root->nodes[i])
			find_height_recursively(root->nodes[i++], height + 1, max);
	}
}

int height_tree(t_node *root)
{
	int max;

	max = 0;
	if(root == NULL)
		return(-1);
	find_height_recursively(root, 0, &max);
	return(max);

}

/*
t_node	*create_node(int val)
{
	t_node	*new;
	int				i;

	new = malloc(sizeof(*new));
	new->value = val;
	new->nodes = malloc(sizeof(*new->nodes) * 3);
	i = 0;
	while (i < 4)
		new->nodes[i++] = 0;
	new->nodes[i] = NULL;
	return (new);
}

int	main()
{
	t_node	*root;
	int				i;
	int				val;
	root = create_node(1);
	val = 2;
	i = 0;
	while (i < 2)
		root->nodes[i++] = create_node(val++);
	root->nodes[0]->nodes[0] = create_node(10);
	root->nodes[1]->nodes[0] = create_node(20);
	root->nodes[1]->nodes[0]->nodes[0] = create_node(30);
	printf("%i\n", height_tree(root));
}
*/
