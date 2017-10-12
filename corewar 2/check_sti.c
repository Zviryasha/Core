/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sti.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 17:26:35 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/12 12:52:13 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

char	*check_arguments_sti(char *s, char *lable, char **data, struct lol *st)
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
	char *stars;

	stars = "";
	v = "0b**";
	if (check_operation(s) == -1)
		return (NULL);
	yoyo = ft_strstr(s, "sti ");
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
		else if (ft_isdigit(t[i][k]) == 1 || t[i][k] == '-')
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
		stars = ft_strjoin(stars, "10");
	}
	else if (t[i][k] == 'r')
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
	else if (ft_isdigit(t[i][k]) == 1 || t[i][k] == '-')
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
		stars = ft_strjoin(stars, "11");
	}
	else if (t[i][k] == ':')
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
        stars = ft_strjoin(stars, "11");
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
    else if (t[i][k] == '%')
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
            printf("lable1 =%s!\n", y);
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
        else if (ft_isdigit(t[i][k]) == 1 || t[i][k] == '-')
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
        stars = ft_strjoin(stars, "10");
    }
	else
		return (NULL);
	if (t[i + 1] != NULL || t[i][k] != '\0')
		return (NULL);
	stars_arg(stars, &v);
	return (v);
}
