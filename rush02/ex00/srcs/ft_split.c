/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flboulea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 04:09:53 by flboulea          #+#    #+#             */
/*   Updated: 2023/09/24 02:06:43 by flboulea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_in(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i] && c != str[i])
		i++;
	return (c == str[i]);
}

int	ft_len_word(char *str, int *i, char *charset)
{
	int	len;

	len = 0;
	while (!is_in(str[*i + len], charset))
		len++;
	*i = *i + len;
	return (len);
}

int	ft_count_words(char *str, char *charset)
{
	int	i;
	int	counter;
	int	empty;

	i = 0;
	counter = 0;
	empty = 1;
	while (str[i])
	{
		while (str[i] && is_in(str[i], charset))
			i++;
		while (str[i] && !is_in(str[i], charset))
		{
			empty = 0;
			i++;
		}
		while (str[i] && is_in(str[i], charset))
			i++;
		counter++;
	}
	if (empty)
		return (0);
	return (counter);
}

char	**ft_create_tab(char *str, char *charset, int nb_words)
{
	char	**tab;
	int		i;
	int		j;
	int		len_word;

	tab = malloc((nb_words + 1) * sizeof(char *));
	if (!tab)
		return (0);
	tab[nb_words] = 0;
	i = 0;
	j = 0;
	while (j < nb_words)
	{
		while (str[i] && is_in(str[i], charset))
			i++;
		len_word = ft_len_word(str, &i, charset);
		tab[j] = malloc(len_word + 1);
		if (!tab[j])
			return (0);
		tab[j][len_word] = '\0';
		j++;
	}
	return (tab);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		nb_words;
	int		word;
	char	**tab;

	nb_words = ft_count_words(str, charset);
	tab = ft_create_tab(str, charset, nb_words);
	if (!tab)
		return (0);
	i = 0;
	word = 0;
	while (word < nb_words)
	{
		while (is_in(str[i], charset))
			i++;
		j = 0;
		while (!is_in(str[i], charset))
			tab[word][j++] = str[i++];
		word++;
	}
	return (tab);
}
