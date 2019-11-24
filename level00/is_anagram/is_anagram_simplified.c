/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_anagram_simplified.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 21:51:00 by mbutt             #+#    #+#             */
/*   Updated: 2019/11/23 21:59:51 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void fill_hashtable(char *str, char *hashtable)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if(str)
		while(str[i])
		{
			j = str[i];
			hashtable[j]++;
			i++;
		}
}

int is_anagram(char *a, char *b)
{
	int i;
	char a_hashtable[127] = {0};
	char b_hashtable[127] = {0};

	i = 32;
	fill_hashtable(a, a_hashtable);
	fill_hashtable(b, b_hashtable);
	while(i < 127)
	{
		if(a_hashtable[i] != b_hashtable[i])
			return(0);
		i++;
	}
	return(1);
}

/*
int main(void)
{
	char *str1 = "aabbcc";
	char *str2 = "aabbcc";

	printf("%d\n", is_anagram(str1, str2));
}
*/
