/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ldi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 16:06:22 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/12 12:51:20 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

char	*check_arguments_ldi(char *s, char *lable, char **data, struct lol *st)
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
	if (check_operation(s) == -1)
		return (NULL);
	if ((yoyo = ft_strstr(s, "lldi ")) != NULL)
		v = "0e**";
	else if ((yoyo = ft_strstr(s, "ldi ")) != NULL)
		v = "0a**";
	t = ft_strsplit(yoyo, ' ');
	yoyo = NULL;
	i = 0;
	while (t[i] != NULL)
	{
		printf("soso = %s\n", t[i]);
		i++;
	}
	i = 1;
	k = 0;
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
					c = o + 1;;
				o++;
			}
			if (c == 0)
				return (NULL);
			printf("LOX = %s\n", r[c - 1]);
			silka(&v, y, data, r, st);
		}
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
		if (ft_isdigit(t[i][k]) == 0)
			return (NULL);
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
	stars_arg(stars, &v);
	return (v);
}
