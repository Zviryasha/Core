/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 14:55:10 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/12 13:54:16 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

int		one_operation_per_line(char *s)
{
	int i;
	char **str;
	int k;

	i = 2;
	str = ft_strsplit(s, '\n');
	while (str[i] != NULL)
	{
		k = check_operation(str[i]);
		if (k == -1)
			return (-1);
		i++;
	}
	return (1);
}

int		check_operation(char *str)
{
	char *u;
	char **s;
	int i;
	int j;
	char **t;
	int count;

	u = "live,lldi,ldi,lld,ld,sti,st,add,sub,and,xor,or,zjmp,lfork,fork";
	s = ft_strsplit(u, ','); // nada ybraty bsi komu
	t = ft_strsplit(str, ' ');
	i = 0;
	count = 0;
	while (s[i] != NULL)
	{
		j = 0;
		while (t[j] != NULL)
		{
			if (ft_strstr(t[j], s[i]) != NULL && ft_strlen(t[j]) == ft_strlen(s[i]))
				count++;
			j++;
		}
		i++;
	}
	printf("count = %d\n", count);
	if (count > 1)
		return (-1);
	else
		return (1);
}
