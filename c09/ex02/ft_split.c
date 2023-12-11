/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:41:58 by tlam              #+#    #+#             */
/*   Updated: 2023/09/25 15:53:23 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_set(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (!is_set(str[i], charset))
		{
			count++;
			while (str[i] && !is_set(str[i], charset))
				i++;
		}
		while (str[i] && is_set(str[i], charset))
			i++;
	}
	return (count);
}

int	allocate_memory(char *str, char *charset, char ***dest, int words)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	*dest = malloc(sizeof(char *) * (words + 1));
	if (!(*dest))
		return (0);
	while (str[i])
	{
		len = 0;
		while (str[i] && is_set(str[i], charset))
			i++;
		while (str[i] && !is_set(str[i], charset))
		{
			i++;
			len++;
		}
		(*dest)[j] = malloc(sizeof(char) * (len + 1));
		if (!(*dest)[j])
			return (0);
		j++;
	}
	return (1);
}

void	allocate_to_dest(char *str, char *charset, char **dest)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] && is_set(str[i], charset))
			i++;
		while (str[i] && !is_set(str[i], charset))
		{
			dest[k][j++] = str[i++];
		}
		dest[k][j] = '\0';
		k++;
	}
	if (k > 0 && !dest[k - 1][0])
		dest[k - 1] = 0;
}

char	**ft_split(char *str, char *charset)
{
	int		words;
	char	**dest;

	words = count_words(str, charset);
	if (!allocate_memory(str, charset, &dest, words))
		return (0);
	allocate_to_dest(str, charset, dest);
	return (dest);
}
/*

#include <stdio.h>
int main()
{
	char *str = " bon,, , ,jo,ur   a tous,a,";
	char *charset = " ,";
	char **dest = ft_split(str, charset);
	int	i = 0;
	while (dest[i])
	{
		printf("%s\n", dest[i]);
		i++;
	}
	return 0;
}
*/
