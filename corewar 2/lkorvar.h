/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lkorvar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 14:48:30 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/12 20:02:51 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LKORVAR_H
# define LKORVAR_H

#include "libft/libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "get_next_line.h"
#include "op.h"
#include <math.h>


struct	lol
{
	int		*a;
	char	*s;
};



int     check_file(char *s);
int     open_s_file(char *s, char **y);
char    *pars_lable(char *s);
int     islable(char *s, int i);
int     name_coment(char *s, char **d);
int     iscorect_lable(char *s);
int     is_la(char c);
int     one_operation_per_line(char *s);
int     check_operation(char *str);
void    del_tab(char *s);
int 	*kk(char *s, char *t, char **data, struct lol *st);
int     find_operation(char *s, char *t, char **data, struct lol *st);
char	*check_arguments_live(char *s, char *l);
char	*check_arguments_sti(char *s, char *t, char **data, struct lol *st);
char	*check_arguments_and(char *s, char *lable, char **data, struct lol *st);
char	*check_arguments_zjmp(char *s, char *lable, char **data, struct lol *st);
char    *check_arguments_st(char *t, char *lable, char **data, struct lol *st);
char    *check_arguments_add(char *t);
char    *check_arguments_ldi(char *s, char *lable, char **data, struct lol *st);
char    *check_arguments_lld(char *s, char *lable, char **data, struct lol *st);
char    *check_arguments_aff(char *s);
void    transform_name(char *name, char **data);
int     get_digit(unsigned long long int value, int base);
char    *ft_itoa_base(long long int value, int base);
void    transform_coment(char *name, char **data);
void    print_data(char **data);
char    *pres(long long int k);
void	stars_arg(char *s, char **data);
int		transform(char *s);
char    *pres_4(long long int k);
void    check_lable_is(char *lable, char *str, char **data, struct lol *st);
void	znak_voprosa(char **t, int *a, char **data, char **str);
void    change_silky(char **data, int a, int *l);
void    silka(char **v, char *y, char **data, char **r, struct lol *st);
char	*silka_4(char **v, char *y, char **data, char **r, struct lol *st);
int		del_all_coment(char **s);
char    *name_trans(int *i, char *s);
char    *coment_trans(int *i, char *s);
void    calc(char **data);
int     name_coment_1(char *s, char **data);
void    kripo(char *lable, char **data, struct lol *st);
int     is_normas(char *s, char *t);
int    write_file(char *data, char *s);
int     hex(char c);
int     mane_2(int *i, char *s, char **data);
char    *changes(char *s);
int     come_2(int *i, char *s, char **data);
int     chenos(char *s, int *i, int *k);
int     cle_1(char *s, int *i, int *k, char *coment);
int     na_co_la(char **s, char *ac, char **data, char **lable);
int     bet_main(char *ac);
int     find_operation_1(char *s, char *lable, char **data, struct lol *st);
int     find_operation_2(char *s, char *lable, char **data, struct lol *st);
int     find_operation_3(char *s, char *lable, char **data, struct lol *st);
#endif
