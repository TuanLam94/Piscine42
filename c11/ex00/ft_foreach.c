/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:36:53 by tlam              #+#    #+#             */
/*   Updated: 2023/09/27 12:53:12 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		(f)(tab[i]);
		i++;
	}
}
/*

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putnbr(-214748364);
		ft_putnbr(8);
	}
	else
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb = -nb;
		}
		if (nb >= 10)
		{
			ft_putnbr(nb / 10);
		}
		nb = nb % 10;
		ft_putchar('0' + nb);
	}
}



int main()
{
	int tab[4];
	tab[0] = 4;
	tab[1] = 14;
	tab[2] = 21;
	tab[3] = 8;

	ft_foreach(tab, 4, &ft_putnbr);
	return (0);
}
*/
