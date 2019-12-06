/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 13:39:17 by mbutt             #+#    #+#             */
/*   Updated: 2019/12/06 14:31:54 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>

void fill_dispatch_table(char *str, int table[127])
{
	int i;
	int ascii;

	i = 0;
	ascii = 0;
	if(str)
		while(str[i])
		{
			if(str[i] >= 'a' && str[i] <= 'z')
			{
				ascii = str[i];
				table[ascii]++;
			}
			else if(str[i] >= 'A' && str[i] <= 'Z')
			{
				ascii = str[i] + 32;
				table[ascii]++;
			}
			i++;
		}
}

int main(int argc, char **argv)
{
	char *str = argv[1];
	int table[127] = {0};
	int i = 0;
	int index = 0;
	bool first_print = true;

	fill_dispatch_table(str, table);
	if(argc != 2)
	{
		printf("\n");
		return(0);
	}
	while(str[i])
	{
		if(str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		if(str[i] >= 'a' && str[i] <= 'z')
		{
			index = (int)str[i];
			if(table[index] > 0)
			{
				if(first_print == true)
				{
					printf("%d%c", table[index], index);
					first_print = false;
				}
				else
					printf(", %d%c", table[index], index);
				table[index] = 0;
			}
		}
		i++;
	}
	printf("\n");

}
