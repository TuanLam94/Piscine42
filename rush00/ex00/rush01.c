/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elichan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 13:26:17 by elichan           #+#    #+#             */
/*   Updated: 2023/09/10 15:12:42 by elichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	l;
	int	c;

	l = 1;
	c = 1;
	if (x <= 0 || y <= 0)
		return ;
	while (l <= y)
	{
		while (c <= x)
		{	
			if ((c == 1 && l == 1) || (c == x && l == y && y != 1 && x != 1))
				ft_putchar('/');
			else if ((c == x && l == 1) || (c == 1 && l == y))
				ft_putchar('\\');
			else if ((c != 1 && c != x) && (l != 1 && l != y))
				ft_putchar(' ');
			else
				ft_putchar('*');
			c++;
		}
		ft_putchar('\n');
		c = 1;
		l++;
	}
}
