/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kripto.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 01:30:23 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/12 18:08:03 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

void	kripo(char *lable, char **data, struct lol *st)
{
	int i;
	char **t;
	int j;
	char *f;
	int y;
	char **r;
	int h;
	int e;

	h = 0;
	r = ft_strsplit((*st).s, ' ');
	t = ft_strsplit(lable, ' ');
	i = 0;
	while (t[i] != NULL)
	{
		printf("lable = %s   st = %d\n", t[i], (*st).a[i]);
		i++;
	}
	j = 4384;
	e = 4384;
	while ((*data)[e] != '\0')
	{
		if ((*data)[e] == '(')
		{
			j = e;
			y = 0;
			j++;
			f = (char *)malloc(sizeof(char) * 10);
			while (ft_isdigit((*data)[j]))
			{
				f[y] = (*data)[j];
				y++;
				j++;
			}
			y = 0;
			while ((*data)[j] == '?')
			{
				j++;
				y++;
			}
			if (y > 3)
				f = pres_4(((*st).a[ft_atoi(f)] - ft_atoi(r[h]) ) / 2);
			else
				f = pres(((*st).a[ft_atoi(f)] - ft_atoi(r[h]) ) / 2);
			printf("f = %lld\n", ft_atoi(f));
			y = 0;
			while (f[y] != '\0')
			{
				(*data)[e] = f[y];
				y++;
				e++;
			}
			h++;
		}
		e++;
	}
	print_data(data);
}
