/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:25:02 by tlam              #+#    #+#             */
/*   Updated: 2023/09/27 16:57:42 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char*))
{
	int	nb;
	int	i;

	i = 0;
	while (tab[i])
	{
		nb = (f)(tab[i]);
		if (nb != 0)
			return (1);
		i++;
	}
	return (0);
}
/*
int	is_number(char *c)
{
	int	i = 0;
	while (c[i])
	{
		if (c[i] > 48 && c[i] < 57)
			return (1);
		i++;
	}
	return (1);
}

#include <stdio.h>

int main()
{
	char *c = "12343";
	char *p = "1232";
	char *y = "1221";
	char *tab = {&c, &p, &y};
	int nb = ft_any(tab, &is_number);
	printf("%d\n", nb);
	return 0;
}
*/
