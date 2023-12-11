/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flboulea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 01:09:29 by flboulea          #+#    #+#             */
/*   Updated: 2023/09/24 05:56:47 by flboulea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_dict.h"

// OK
int	get_file_length(char *path)
{
	int		fd;
	int		length;
	char	_;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	length = 0;
	while (read(fd, &_, 1))
		length++;
	close(fd);
	return (length);
}

// OK
char	*read_dict(char *path)
{
	char	*buf;
	int		file_length;
	int		fd;

	file_length = get_file_length(path);
	if (!file_length)
		return (0);
	buf = malloc(file_length + 1);
	if (!buf)
		return (0);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (free(buf), (char *)0);
	read(fd, buf, file_length);
	buf[file_length] = '\0';
	close(fd);
	return (buf);
}

// OK
char	**get_initial_entries(void)
{
	char	buf[336];
	int		fd;

	buf[335] = '\0';
	fd = open("dicts/initial_entries", O_RDONLY);
	if (fd == -1)
		return (0);
	read(fd, buf, 335);
	close(fd);
	return (ft_split(buf, "\n"));
}

// check si il y a tout les nombres de 'initial_entries' et que leur writing ne
// sont pas vide (si vide continuer de cherche dans la suite au cas ou redefini
// OK mais ssi on a le temps on teste plus fort
int	all_values(char ***dict)
{
	char	**entries;
	int		i;
	int		j;

	entries = get_initial_entries();
	if (!entries)
		return (0);
	i = 0;
	while (entries[i])
	{
		j = 0;
		while (dict[j] && (ft_strcmp(dict[j][0], entries[i]) || !dict[j][1]))
			j++;
		if (!dict[j])
			return (0);
		i++;
	}
	return (1);
}

// OK mais si on a le temps on teste plus fort
int	parse_dict(char *path, char ****dict, int *len)
{
	char	*buf_dict;
	char	**temp;

	buf_dict = read_dict(path);
	if (!buf_dict)
		return (0);
	temp = ft_split(buf_dict, "\n");
	if (!temp)
		return (free(buf_dict), 0);
	while (temp[*len])
		(*len)++;
	*dict = malloc((*len + 1) * sizeof(char **));
	if (!*dict)
		return (free(buf_dict), free_tab(temp), 0);
	(*dict)[*len] = 0;
	*len = -1;
	while (temp[++(*len)])
	{
		(*dict)[*len] = ft_cut(temp[*len]);
		if (!(*dict)[*len])
			return (free(buf_dict), free_tab(temp), free_tab_tab(*dict), 0);
		(*dict)[*len][0] = clean_number((*dict)[*len][0], 1);
		(*dict)[*len][1] = clean_writing((*dict)[*len][1]);
	}
	return (free(buf_dict), free_tab(temp), all_values(*dict));
}
