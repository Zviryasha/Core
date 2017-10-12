/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_live.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 03:33:05 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/12 18:14:00 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

char    *check_arguments_live(char *s, char *lable)
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
    v = "01";
    i = 1;
    k = 0;
	if (check_operation(s) == -1)
		return (NULL);
	yoyo = ft_strstr(s, "live ");
    t = ft_strsplit(yoyo, ' ');
	yoyo = "";
    while (t[k] != NULL)
        k++;
    if (k != 2)
        return (NULL);
    printf("k = %d\n", k);
    k = 0;
    printf("t[i][k] = %c\n", t[i][k]);
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
            dig = pres_4(ii);
            v = ft_strjoin(v, dig);
        }
		if (t[i + 1] != NULL || t[i][k] != '\0')
			return (NULL);
    }
    else
        return (NULL);
    return (v);
}
