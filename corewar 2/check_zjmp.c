/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_zjmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 23:48:56 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/12 12:48:23 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

char	*check_arguments_zjmp(char *s, char *lable, char **data, struct lol *st)
{
	char **t;
	int i;
	int k;
	char *y;
	int o;
	char **r;
	int c;
	char *v;
	long long int ii;
	char *dig;
	char *yoyo;

	yoyo = "";
	if (check_operation(s) == -1)
		return (NULL);
	if ((yoyo = ft_strstr(s, "zjmp ")) != NULL)
	{
		v = "09";
	}
	else if ((yoyo = ft_strstr(s, "lfork ")) != NULL)
		v = "0f";
	else if ((yoyo = ft_strstr(s, "fork ")) != NULL)
		v = "0c";
	t = ft_strsplit(yoyo, ' ');
	yoyo = "";
	i = 0;
	k = 0;
	while (t[i] != NULL)
	{
		printf("t[i] = %s\n", t[i]);
		i++;
	}
	i = 1;
	if (t[i][k] == '%')
	{
		k++;
		if (t[i][k] == ':')
		{
			k++;
			y = (char *)malloc(sizeof(char) * 100);
			o = 0;
			while (is_la(t[i][k]))
			{
				y[o] = t[i][k];
				k++;
				o++;
			}
			y[o] = '\0';
			printf("lable =%s!\n", y);
			r = ft_strsplit(lable, ' ');
			o = 0;
			c = 0;
			while (r[o] != NULL)
			{
				if (ft_strcmp(r[o], y) == 0)
					c++;
				o++;
			}
			if (c == 0)
				return (NULL);
			silka(&v, y, data, r, st);
		}
		else 
		{
			if (ft_isdigit(t[i][k]) == 1 || t[i][k] == '-')
			{
				y = (char *)malloc(sizeof(char) * 100);
				o = 0;
				if (t[i][k] == '-')
				{
					y[o] = t[i][k];
					o++;
					k++;
				}
				while (ft_isdigit(t[i][k]) == 1)
				{
					y[o] = t[i][k];
					k++;
					o++;
				}
				ii = ft_atoi(y);
				dig = pres(ii);
				v = ft_strjoin(v, dig);
			}
			else
				return (NULL);	
		}
		if (t[i + 1] != NULL || t[i][k] != '\0')
			return (NULL);
	}
	return (v);
}
