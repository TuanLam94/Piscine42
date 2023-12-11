/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flboulea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 17:13:06 by flboulea          #+#    #+#             */
/*   Updated: 2023/09/24 23:33:23 by flboulea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "write_number.h"
#include "tools.h"

void	write_this(char ***dict, char a, char b, int fd)
{
	char	buf[3];
	char	*value;

	buf[0] = a;
	buf[1] = b;
	buf[2] = '\0';
	value = g_val(dict, buf);
	write(fd, value, ft_strlen(value));
	write(fd, " ", 1);
}

void	print_hundred(char ***dict, char *nbr, int length, int fd)
{
	if (length == 3)
	{
		if (nbr[0] != '0')
		{
			write_this(dict, nbr[0], 0, fd);
			write(fd, g_val(dict, "100"), ft_strlen(g_val(dict, "100")));
			write(fd, " ", 1);
		}
		nbr++;
		length--;
	}
	if (length == 2)
	{
		if (nbr[0] > '1')
			write_this(dict, nbr[0], '0', fd);
		else if (nbr[0] != '0')
		{
			write_this(dict, nbr[0], nbr[1], fd);
			return ;
		}
		nbr++;
		length--;
	}
	if (nbr[0] != '0')
		write_this(dict, nbr[0], 0, fd);
}

void	print_thousand_power(char ***dict, int power, int fd)
{
	char	nbr[38];
	char	*value;
	int		i;

	nbr[0] = '1';
	i = 1;
	while (i < power * 3 + 1)
		nbr[i++] = '0';
	nbr[i] = '\0';
	value = g_val(dict, nbr);
	write (fd, value, ft_strlen(value));
	write(fd, " ", 1);
}

void	rec_write_number(char *nbr, char ***dict, int length, int fd)
{
	int	l;

	if (length > 36)
	{
		rec_write_number(nbr, dict, length - 36, fd);
		print_thousand_power(dict, 12, fd);
		rec_write_number(nbr + (length - 36), dict, 36, fd);
		return ;
	}
	l = length % 3;
	if (!l)
		l = 3;
	print_hundred(dict, nbr, l, fd);
	if (length > 3)
	{
		if (nbr[0] != '0' || nbr[1] != '0' || nbr[2] != '0')
			print_thousand_power(dict, (length - 1) / 3, fd);
		rec_write_number(nbr + l, dict, length - l, fd);
	}
}

void	write_number(char *nbr, char ***dict)
{
	char	*value;
	char	buf[25000];
	int		fd;

	fd = open(".result", O_RDWR);
	if (fd == -1)
		return ;
	if (!ft_strcmp(nbr, "0"))
	{
		value = g_val(dict, nbr);
		write(fd, value, ft_strlen(value));
		write(fd, " ", 1);
	}
	else
		rec_write_number(nbr, dict, ft_strlen(nbr), fd);
	write(fd, "\0", 1);
	close(fd);
	fd = open(".result", O_RDONLY);
	read(fd, buf, 25000);
	write(1, buf, ft_strlen(buf) - 1);
	write(1, "\n", 1);
}
