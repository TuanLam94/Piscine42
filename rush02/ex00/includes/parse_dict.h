/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flboulea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 02:04:07 by flboulea          #+#    #+#             */
/*   Updated: 2023/09/24 05:00:23 by flboulea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_DICT_H
# define PARSE_DICT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include "clean_things.h"
# include "tools.h"

char	**ft_split(char *str, char *charset);
char	**ft_cut(char *str);
void	free_tab(char **tab);
void	free_tab_tab(char ***tab);

#endif
