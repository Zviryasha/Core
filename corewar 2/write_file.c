/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 16:34:44 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/13 11:08:28 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"
void    write_data_to_file(char *data, int fd);
static int  ft_16(char c);
static int         ft_atoi_16(char *s);


int		write_file(char *data, char *s)
{
	int i;
	int fd;
	int o;
	signed char k;

	i = 0;
	o = ft_strlen(s);
	s[o - 1] = '\0';
	s[o - 2] = '\0';
	s = ft_strjoin(s, "1.cor");
	fd = open(s, O_RDWR | O_CREAT, 777);
	if (fd == -1)
		return (-1);
	o = 0;
	k = 0;
	write_data_to_file(data, fd);
	printf("SOZDAL = %d\n", i);
	return (0);
}


static int  ft_16(char c)
{
    int     nb;

    nb = 0;
    if (c >= '0' && c <= '9')
        nb = c - '0';
    else if (c >= 'A' && c <= 'F')
        nb = c - 'A' + 10;
    else
        nb = c - 'a' + 10;
    return (nb);
}

static int         ft_atoi_16(char *s)
{
    int     nb;
    int     i;

    i = 0;
    nb = 0;
    while ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'F')
		   || (s[i] >= 'a' && s[i] <= 'f'))
    {
        nb = nb * 16 + ft_16(s[i]);
        i++;
    }
    return (nb);
}

void	write_data_to_file(char *data, int fd)
{
	char	s[2] = "00";
	int		i;

	i = 0;
	while (data[i])
	{
		s[0] = data[i++];
		s[1] = data[i++];
		ft_putchar_fd(ft_atoi_16(s), fd);
	}
}
