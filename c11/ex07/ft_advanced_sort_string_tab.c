/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:39:12 by tlam              #+#    #+#             */
/*   Updated: 2023/09/28 13:42:54 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(char **a, char **b)
{
	char	*swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i;

	i = 0;
	while (tab[i + 1])
	{
		if ((cmp)(tab[i], tab[i + 1]) > 0)
		{
			swap(&tab[i], &tab[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}
/*
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

#include <stdio.h>

int main()
{
	char* tab[6] = {"gamma", "delta", "alpha", "beta", "epsilon", "   "};
	ft_advanced_sort_string_tab(tab, &ft_strcmp);
	int	i = 0;
	while (i < 6)
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return 0;
}
*/
