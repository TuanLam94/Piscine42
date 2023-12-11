/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <tlam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:10:53 by tlam              #+#    #+#             */
/*   Updated: 2023/09/07 12:06:17 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putdeci(int nb)
{
	int	deci;
	int	unit;

	unit = nb % 10;
	deci = nb / 10;
	ft_putchar(deci + '0');
	ft_putchar(unit + '0');
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_putdeci(a);
			ft_putchar(' ');
			ft_putdeci(b);
			if (!(a == 98 && b == 99))
				write(1, ", ", 2);
			b++;
		}
	a++;
	}
}
