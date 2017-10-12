/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 18:43:39 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/10 01:11:22 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

char	*changes(char *s)
{
	char **t;
	int i;
	char *y;


	y = "";
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\t')
			s[i] = ' ';
		i++;
	}
	t = ft_strsplit(s, ' ');
	i = 0;
	while (t[i] != NULL)
	{
		y = ft_strjoin(y, t[i]);
		if (t[i + 1] != NULL)
			y = ft_strjoin(y, " ");
		i++;
	}
	//printf("y =%s\n", y);
	return (y);	
}
