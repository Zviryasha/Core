/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 16:57:41 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/04 04:28:54 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

char    *pres_4(long long int k)
{
    char *s;
    char *r;
    int i;
    int j;

	while (k > 4294967296)
		k = k - 4294967296;
	while (k < 4294967296)
		k = 4294967296 + k;
	if (k < 0)
		k = 4294967296 + k;
	s = ft_itoa_base(k, 16);
    r = (char *)malloc(sizeof(char) * 8);
    r[7] = '\0';
    i = 0;
    while (i != 7)
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
