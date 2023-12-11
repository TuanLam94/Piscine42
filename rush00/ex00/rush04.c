/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elichan <elichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 11:44:16 by elichan           #+#    #+#             */
/*   Updated: 2023/09/10 16:15:49 by elichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	l;
	int	c;

	l = 1;
	if (x <= 0 || y <= 0)
		return ;
	while (l <= y)
	{
		c = 1;
		while (c <= x)
		{
			if ((l == 1 && c == 1)
				|| ((l == y && c == x) && (c != 1) && (l != 1)))
				ft_putchar('A');
			else if ((l == 1 && c == x) || (l == y && c == 1))
				ft_putchar('C');
			else if ((c != 1 && c != x) && (l != 1 && l != y))
				ft_putchar(' ');
			else
				ft_putchar('B');
			c++;
		}
		ft_putchar('\n');
		l++;
	}
}
