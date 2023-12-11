/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:52:40 by tlam              #+#    #+#             */
/*   Updated: 2023/09/14 09:36:54 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	negative;
	int	atoi;

	negative = 1;
	atoi = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\r' || *str == '\f' || *str == '\v')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			negative = -negative;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		atoi = atoi * 10 + (*str - 48);
		str++;
	}
	return (atoi * negative);
}
/*

#include <stdio.h>

int	ft_atoi(char *str);

int	main(void)
{
	int nb;
	char *str;
       	str = "   -+--2147483648 bonjour 34";
	nb = ft_atoi(str);
	printf("%d",nb);
	return 0;
}
*/
