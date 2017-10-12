/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 18:24:47 by opanchen          #+#    #+#             */
/*   Updated: 2017/09/24 14:42:15 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

void	print_data(char **data)
{
	int i;
	int y;
	int k;
	int u;

	i = 0;
	y = 1;
	k = 0;
	u = 1;
	printf("%-5d ", u);
	while ((*data)[i] != '\0')
	{
		if (k == 32)
		{
			k = 0;
			printf("\n");
			u++;
			printf("%-5d ", u);
		}
		printf("%c", (*data)[i]);
		if (y == 4)
		{
			y = 0;
			printf(" ");
		}
		i++;
		y++;
		k++;
	}
}
