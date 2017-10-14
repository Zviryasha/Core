/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   silka.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 04:07:00 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/14 11:16:39 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

void	silka(char **v, char **data, struct lol *st, int i)
{
	int c;
	char *f;

	c = 4384;
	while ((*data)[c] != '\0')
		c++;
	printf("---------------------------------------------------------------c = %d\n", c - 4384);

	printf("PORIVNUU----------a = %d------> ---b = %d------------------- = \n", c - 4384, (*st).a[i]);
	if (((c - 4384) > (*st).a[i] && (*st).a[i] != 0))
	{
		printf("lox pidor-------------------------------------- = %d\n", c - 4384 - (*st).a[i]);
		printf("a[i]-------------------------------------- = %d\n", (*st).a[i]);
		f = pres(65535 - ((c - 4385 - (*st).a[i]) / 2));
		printf("JJ ------------------------------------------------ %s\n", f);
		*v = ft_strjoin(*v, f);
	}
	else
	{
		f = "(";
		f = ft_strjoin(f, ft_itoa(i));
		while (ft_strlen(f) != 3)
			f = ft_strjoin(f, "?");
		f = ft_strjoin(f, ")");
		printf("f = %s\n", f);
		*v = ft_strjoin(*v, f);
		(*st).s = ft_strjoin((*st).s, ft_itoa(c - 4384));
		(*st).s = ft_strjoin((*st).s, " ");
	}
}

char	*silka_4(char **v, char **data, struct lol *st, int i)
{
    int c;
    char *f;

    c = 4384;
    while ((*data)[c] != '\0')
        c++;
	printf("c = %d\n", c);
    if ((c - 4384) > (*st).a[i] && (*st).a[i] != 0)
    {
        f = pres_4(4294967295 - ((c - 4385 - (*st).a[i]) / 2));
        *v = ft_strjoin(*v, f);
    }
    else
    {
        f = "(";
        f = ft_strjoin(f, ft_itoa(i));
        while (ft_strlen(f) != 7)
            f = ft_strjoin(f, "?");
        f = ft_strjoin(f, ")");
        printf("f = %s\n", f);
        *v = ft_strjoin(*v, f);
		(*st).s = ft_strjoin((*st).s, ft_itoa(c - 4384));
		(*st).s = ft_strjoin((*st).s, " ");
    }
	return (ft_itoa(c - 4384));
}
