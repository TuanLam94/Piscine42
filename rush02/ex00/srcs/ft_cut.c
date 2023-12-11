/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flboulea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 04:09:53 by flboulea          #+#    #+#             */
/*   Updated: 2023/09/24 05:58:48 by flboulea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "tools.h"

int	ft_index(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

// OK
char	**useless_tab(char ***tab)
{
	*tab = malloc(3 * sizeof(char *));
	if (!*tab)
		return (0);
	(*tab)[2] = 0;
	(*tab)[0] = malloc(3);
	if (!(*tab)[0])
		return (free(*tab), (char **)0);
	(*tab)[1] = malloc(3);
	if (!(*tab)[1])
		return (free((*tab)[0]), free(*tab), (char **)0);
	(*tab)[0][0] = '5';
	(*tab)[0][1] = '8';
	(*tab)[0][2] = '\0';
	(*tab)[1][0] = '5';
	(*tab)[1][1] = '8';
	(*tab)[1][2] = '\0';
	return (*tab);
}

// OK
char	**ft_cut(char *str)
{
	int		len_first_part;
	int		i;
	char	**tab;

	len_first_part = ft_index(str, ':');
	if (len_first_part == -1)
		return (useless_tab(&tab));
	tab = malloc(3 * sizeof(char *));
	if (!tab)
		return (0);
	tab[0] = malloc(len_first_part + 1);
	if (!tab[0])
		return (free(tab), (char **)0);
	tab[0][len_first_part] = '\0';
	tab[1] = malloc(ft_strlen(str) - len_first_part);
	if (!tab[1])
		return (free(tab[0]), free(tab), (char **)0);
	tab[1][ft_strlen(str) - len_first_part - 1] = '\0';
	i = -1;
	while (++i < len_first_part)
		tab[0][i] = str[i];
	i = -1;
	while (str[len_first_part + ++i + 1])
		tab[1][i] = str[len_first_part + i + 1];
	return (tab[2] = 0, tab);
}
