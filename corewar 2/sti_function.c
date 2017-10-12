/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 11:43:24 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/07 12:43:47 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

char	*pres(long long int k)
{
	char *s;
	char *r;
	int i;
	int j;

	printf("lolik = %lld\n", k);
	while (k > 65536)
		k = k - 65536;
	while (k < -65536)
		k = k + 65536;
	if (k < 0)
		k = k + 65536;
	s = ft_itoa_base(k, 16);
	r = (char *)malloc(sizeof(char) * 4);
	r[3] = '\0';
	i = 0;
	while (i != 3)
	{
		r[i] = 'p';
		i++;
	}
	j = ft_strlen(s);
	j = j - 1;;
	while (j >= 0)
	{
		r[i] = s[j];
		j--;
		i--;
	}
	i = 0;
	while (r[i] != 0)
	{
		if (r[i] == 'p')
			r[i] = '0';
		i++;
	}

	return (r);
}

void	stars_arg(char *s, char **data)
{
	int j;
	char *y;
	char *a;
	char *b;
	int i;
	int e;
	
	j = 0;
	y = ft_strnew(8);
	while (s[j] != '\0')
	{
		y[j] = s[j];
		j++;
	}
	while (j != 9)
	{
		y[j] = '0';
		j++;
	}
	j = 0;
	a = ft_strnew(4);
	b = ft_strnew(4);
	while (j != 4)
	{
		a[j] = y[j];
		j++;
	}
//	printf("a1 = %s\n", a);
	i = 0;
	while (j != 8)
	{
		b[i] = y[j];
		i++;
		j++;
	}
//	printf("b = %s\n", b);
//	printf("a = %s\n", a);
//	printf("Stars_arg = %s\n", y);
	e = ft_strlen(*data);
	while ((*data)[e] != '*')
		e--;
	b = ft_itoa(transform(b));
//	printf("b0000 = %s\n", b);
	b = ft_itoa_base(ft_atoi(b), 16);
	(*data)[e] = b[0];
	e--;
	a = ft_itoa(transform(a));
//	printf("a0000 = %s\n", a);
	a = ft_itoa_base(ft_atoi(a), 16);
	(*data)[e] = a[0];
}

int		transform(char *s)
{
	int i;
	int sum;
	int j;

	
	i = ft_strlen(s) - 1;
	sum = 0;
	j = 0;
	while (s[j] != '\0')
	{
		sum = sum + pow(2, i) * (s[j] - 48);
		i--;
		j++;
	}
	return (sum);
}
