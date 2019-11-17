/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 19:59:37 by mbutt             #+#    #+#             */
/*   Updated: 2019/11/16 21:35:23 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Passes ecamshell
*/
#include <stdio.h>
#include <stdlib.h>

/*
** LIFO - Last in, first out -- Like a stack of plates.
** +----------------------+
** |       Last           |
** +----------------------+
** |       Fourth         |
** +----------------------+
** | 	   Third          |
** +----------------------+
** |       Second         |
** +----------------------+
** |       First          |
** +----------------------+
*/
/*
typedef struct		s_node
{
	void			*content;
	struct s_node	*next;
}					t_node;

typedef struct		s_stack
{
	t_node			*top;
}					t_stack;
*/


struct				s_node
{
	void			*content;
	struct s_node	*next;
};

struct 				s_stack
{
	struct s_node	*top;
};

/*
** init - Initialize the stack.
** The top pointer is set to NULL.
*/

struct s_stack *init(void)
{
	struct s_stack *stack;

	stack = malloc(sizeof(struct s_stack));
	stack->top = NULL;
	return(stack);
}

/*
** | Need to spend more time to understand pop |
** pop(stack) : Remove the top item from the stack and return it.
** If the stack is empty, the function returns NULL.
*/

void *pop(struct s_stack *stack)
{
	struct s_node	*node;
	void			*content;

	if(stack == NULL || stack->top == NULL)
		return(NULL);
	node = stack->top;
	stack->top = stack->top->next;
	content = node->content;
	node->next = NULL;
	free(node);
	return(content);
}

/*
** | Need to spend more time to understand push|
** push(stack, item): Add an item to the top of the stack.
*/
void push(struct s_stack *stack, void *content)
{
	struct s_node *new_node;

	new_node = malloc(sizeof(struct s_node));
	if(new_node == NULL)
		return;
	new_node->content = content;
	new_node->next = stack->top;
	stack->top = new_node;
}


/*
** peek(stack) : Return the top of the stack.
** If the stack is empty, the function returns NULL;
*/

void *peek(struct s_stack *stack)
{
	if(stack == NULL || stack->top == NULL)
		return(NULL);
	return(stack->top->content);
}

/*
** isEmpty(stack): Returns 1 if the stack is empty, 0 otherwise;
*/

int isEmpty(struct s_stack *stack)
{
	if(stack == NULL || stack->top == NULL)
		return(1);
	return(0);
}

/*
int main(void)
{
	struct s_stack *stack_test;
	stack_test = init();
	printf("%s\n", (char *)stack_test->top);
	printf("%d\n", isEmpty(stack_test));
}
*/
