/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:07:27 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/14 13:27:09 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

int				na_co_la(char **s, char *ac, char **data, char **lable, struct lol *st)
{
	if (open_s_file(ac, s) == -1)
		return (-1);
	if (del_all_coment(s) == -1)
		return (-1);
	if (name_coment(*s, data) == -1)
	{
		if (name_coment_1(*s, data) == -1)
			return (-1);
	}
	if ((*lable = pars_lable(*s)) == NULL)
		return (-1);
	(*st).lable = pars_lable(*s);
	return (0);
}

int				bet_main(char *ac)
{
	struct lol	st;
	char		*s;
	char		*lable;
	char		*data;

	s = "";
	data = "";
	if (check_file(ac) == 1)
	{
		if (na_co_la(&s, ac, &data, &lable, &st) == -1)
			return (-1);
		if (kk(s, lable, &data, &st) == NULL)
			return (-1);
		calc(&data);
		kripo(lable, &data, &st);
		write_file(data, ac);
	}
	else
		return (-1);
	return (0);
}
