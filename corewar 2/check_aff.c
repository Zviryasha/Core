/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_aff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 16:36:42 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/12 18:18:13 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

char    *check_arguments_aff(char *s)
{
	char **t;
	int i;
	int k;
	char *v;
	long long int ii;
	char *dig;
	char *yoyo;
	char *stars;

	stars = "";
	v = "10**";
	if (check_operation(s) == -1)
		return (NULL);
	yoyo = ft_strstr(s, "aff ");
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
	if (t[i + 1] != NULL || t[i][k] != '\0')
		return (NULL);
	stars_arg(stars, &v);
	return (v);
}
