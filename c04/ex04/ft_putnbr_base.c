/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:20:53 by tlam              #+#    #+#             */
/*   Updated: 2023/09/14 12:18:16 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_base(char *base)
{
	int	len;
	int	i;
	int	j;

	i = 0;
	len = ft_strlen(base);
	if (len <= 1)
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	len;

	len = ft_strlen(base);
	if (check_base(base))
	{
		if (nbr == -2147483648)
		{
			ft_putnbr_base(-2147483648 / len, base);
			ft_putnbr_base(2147483648 % len, base);
		}
		else
		{
			if (nbr < 0)
			{
				ft_putchar('-');
				nbr = -nbr;
			}
			if (nbr >= len)
			{
				ft_putnbr_base(nbr / len, base);
			}
			ft_putchar(base[nbr % len]);
		}
	}
}
/*
int main ()
{
int nb = -0x80000000;
char *base = "012345678";
ft_putnbr_base(nb, base);
return 0;
}
*/
