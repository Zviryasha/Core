/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 15:04:30 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/12 18:16:29 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

char	*check_arguments_add(char *s)
{
	char **t;
	int i;
	int k;
	char *y;
	int o;
	char *v;
	long long int ii;
	char *dig;
	char *yoyo;
	char *stars;
	
	stars = "";
	yoyo = NULL;
	if (check_operation(s) == -1)
		return (NULL);
	if ((yoyo = ft_strstr(s, "add ")) != NULL)
		v = "04**";
	else if ((yoyo = ft_strstr(s, "sub ")) != NULL)
		v = "05**";
	t = ft_strsplit(yoyo, ' ');
	yoyo = NULL;
	if (t[1][0] != 'r')
		return (NULL);
	(t[1])++;
	if (ft_isdigit(*t[1]) == 0)
		return (NULL);
	if (ft_atoi(t[1]) < 0 || ft_atoi(t[1]) > 99)
		return (NULL);
	i = 1;
	k = 0;
	ii = 0;
	dig = ft_strnew(5);
	while (ft_isdigit(t[i][k]) == 1)
	{
		dig[ii] = t[i][k];
		printf("dig = %c\n", dig[ii]);
		ii++;
		k++;
	}
	ii = ft_atoi(dig);
	dig = ft_itoa_base(ii, 16);
	if (ft_strlen(dig) == 1)
		v = ft_strjoin(v, "0");
	stars = ft_strjoin(stars, "01");
	v = ft_strjoin(v, dig);
	if (t[i][k] == '\0')
	{
		k = 0;
		i++;
	}
	if (t[i][k] != SEPARATOR_CHAR)
		return (NULL);
	if (t[i][++k] == '\0')
	{
		k = 0;
		i++;
	}
	if (t[i][k] == 'r')
	{
		k++;
		y = (char *)malloc(sizeof(char) * 100);
		o = 0;
		while (ft_isdigit(t[i][k]) == 1)
		{
			y[o] = t[i][k];
			k++;
			o++;
		}
		if (ft_atoi(y) < 0 || ft_atoi(y) > 99)
			return (NULL);
		dig = ft_itoa_base(ft_atoi(y), 16);
		if (ft_strlen(dig) == 1)
			v = ft_strjoin(v, "0");
		v = ft_strjoin(v, dig);
		stars = ft_strjoin(stars, "01");
	}
	else
		return (NULL);
	if (t[i][k] == '\0')
	{
		i++;
		k = 0;
	}
	if (t[i] == NULL || t[i][k] != ',')
		return (NULL);
	k++;
	if (t[i][k] == '\0')
	{
		i++;
		k = 0;
	}
	if (t[i] == NULL)
		return (NULL);
	if (t[i][k] == 'r')
	{
		k++;
		y = (char *)malloc(sizeof(char) * 100);
		o = 0;
		while (ft_isdigit(t[i][k]) == 1)
		{
			y[o] = t[i][k];
			k++;
			o++;
		}
		if (ft_atoi(y) < 0 || ft_atoi(y) > 99)
			return (NULL);
		dig = ft_itoa_base(ft_atoi(y), 16);
		if (ft_strlen(dig) == 1)
			v = ft_strjoin(v, "0");
		v = ft_strjoin(v, dig);
		stars = ft_strjoin(stars, "01");
	}
	else
		return (NULL);
	if (t[i + 1] != NULL || t[i][k] != '\0')
		return (NULL);
	stars_arg(stars, &v);
	return (v);
}
