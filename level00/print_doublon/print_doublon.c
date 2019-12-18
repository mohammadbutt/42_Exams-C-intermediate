/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_doublon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 09:14:09 by exam              #+#    #+#             */
/*   Updated: 2019/12/17 09:39:18 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>

void print_doublon(int *a, int na, int *b, int nb)
{
	int i;
	int j;
	bool first_print;

	i = 0;
	j = 0;
	first_print = true;
	while((i < na) && (j < nb))
	{
		if(a[i] < b[j])
			i++;
		else if(a[i] > b[j])
			j++;
		else if(a[i] == b[j])
		{
			if(first_print == false)
				printf(" %d", a[i]);
			else if(first_print == true)
				printf("%d", a[i]);
			first_print = false;
			i++;
			j++;
		}
	}
	printf("\n");
}

/*
int main(void)
{
//	int a[] = {-5, 2, 10, 15, 50, 70, 100, 200, 300, 1200, 5000};
//	int na = 11;
//	int b[] = {2, 4, 5, 6, 7, 10, 40, 70};
//	int nb = 8;
//	print_doublon(a, na, b, nb);
//	int a[] = {1, 2, 10, 15};
//	int na = 4;
//	int b[] = {2, 20, 40, 70};
//	int nb = 4;
//	print_doublon(a, na, b, nb);
//	int a[] = {100, 200, 300};
//	int na = 3;
//	int b[] = {1, 2, 3, 4};
//	int nb = 4;
//	print_doublon(a, na, b, nb);
}
*/
