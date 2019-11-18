/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 20:48:48 by mbutt             #+#    #+#             */
/*   Updated: 2019/11/17 22:22:16 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Passed examshell
*/

#include <stdio.h>

int find_pivot(int *arr, int n)
{
	int left_total;
	int right_total;
	int i;
	
	left_total = 0;
	right_total = 0;
	i = 1;
	while(i < n)
		right_total = right_total + arr[i++];
	i = 0;
	while(i < n)
	{
		if(left_total == right_total)
			return(i);
		right_total = right_total - arr[i + 1];
		left_total = left_total + arr[i];
		i++;
	}
	return(-1);
}

/*
int main(void)
{
	int pivot_index;
	pivot_index = 0;

//	int arr[4] = {1, 2, 2, 3};
//	pivot_index = find_pivot(arr, 4);

//	int arr[6] = {1, 2, 3, 4, 0, 6};
//	pivot_index = find_pivot(arr, 6);

//	int arr[4] = {-5, 10, 2, 5};
//	pivot_index = find_pivot(arr, 4);

//	int arr[3] = {7, 9, 8};
//	pivot_index = find_pivot(arr, 3);

//	int arr[5] = {1, 100, 0, 0, 1};
//	pivot_index = find_pivot(arr, 5);

	printf("%d\n", pivot_index);
}
*/
