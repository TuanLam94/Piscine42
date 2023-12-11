/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:06:30 by tlam              #+#    #+#             */
/*   Updated: 2023/09/12 09:41:45 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	*hex;

	hex = "0123456789abcdef";
	i = 0;
	while ((unsigned char) str[i])
	{
		if (((unsigned char)str[i] < ' ') || ((unsigned char) str[i] >= 127))
		{
			ft_putchar('\\');
			ft_putchar(hex[((unsigned char)str[i]) / 16]);
			ft_putchar(hex[((unsigned char)str[i]) % 16]);
		}
		else
		{
			if ((unsigned char)str[i] == '\\')
				ft_putchar('\\');
			ft_putchar((unsigned char)str[i]);
		}
		i++;
	}
}
