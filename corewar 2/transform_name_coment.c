/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_name_coment.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 00:44:02 by opanchen          #+#    #+#             */
/*   Updated: 2017/09/29 02:46:15 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

void	transform_name(char *name, char **data)
{
	int i;
	char *s;

	*data = "";
	*data = ft_strjoin(*data, "00ea83f3");
	i = 0;
	while (name[i] != '\0')
	{
		s = ft_itoa_base(name[i], 16);
		*data = ft_strjoin(*data, s);
		printf("s = %s\n", s);
		i++;
	}
	while (i < PROG_NAME_LENGTH + 4)
	{
		*data = ft_strjoin(*data, "00");
		i++;
	}
	*data = ft_strjoin(*data, "********");
}

void	transform_coment(char *name, char **data)
{
	int i;
	char *s;
	int y;
	int k;
	int u;

	i = 0;
	while (name[i] != '\0')
	{
		s = ft_itoa_base(name[i], 16);
		*data = ft_strjoin(*data, s);
//		printf("s = %s\n", s);
		i++;
	}
	while (i < COMMENT_LENGTH + 4)
	{
		*data = ft_strjoin(*data, "00");
		i++;
	}
	i = 0;
	y = 1;
	k = 0;
	u = 1;
	printf("%3d ", u);
	while ((*data)[i] != '\0')
	{
		if (k == 32)
		{
			k = 0;
			printf("\n");
			u++;
			printf("%3d ", u);
		}
		printf("%c", (*data)[i]);
		if (y == 4)
		{
			y = 0;
			printf(" ");
		}
		i++;
		y++;
		k++;
	}
}

int		get_digit(unsigned long long int value, int base)
{
	int digit;

	digit = 0;
	while (value)
	{
		digit++;
		value /= base;
	}
	return (digit);
}

char	*ft_itoa_base(long long int value, int base)
{
	char 			*result;
	unsigned long long int	num;
	int				digit;
	int				is_negative;
	int				i;
	long long int				tmp;

	if (value < 0)
	{
		num = -value;
		is_negative = 1;
	}
	else if (value == 0)
	{
		result = (char *)malloc(2);
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	else
	{
		num = value;
		is_negative = 0;
	}

	digit = get_digit(num, base);
	i = 0;
	if (is_negative)
	{
		result = (char *)malloc(sizeof(*result) * (digit + 2));
		result[digit + 1] = '\0';
		result[i++] = '-';
	}
	else
	{
		result = (char *)malloc(sizeof(*result) * (digit + 1));
		result[digit--] = '\0';
	}
	while (digit >= i)
	{
		tmp = num % base;
		if (tmp >= 10)
			result[digit--] = tmp + 87;
		else
			result[digit--] = tmp + '0';
		num /= base;
	}
	return (result);
}
