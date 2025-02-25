/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flboulea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 17:22:49 by flboulea          #+#    #+#             */
/*   Updated: 2023/09/24 20:47:08 by flboulea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

char	*g_val(char ***dict, char *key)
{
	int	i;

	i = 0;
	while (ft_strcmp(dict[i][0], key))
		i++;
	return (dict[i][1]);
}
