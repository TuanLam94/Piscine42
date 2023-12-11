/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:00:25 by tlam              #+#    #+#             */
/*   Updated: 2023/09/24 00:58:58 by flboulea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clean_things.h"

// OK
int	parse_args(int ac, char **av, char *args[2])
{
	if (ac < 2 || ac > 3)
		return (0);
	if (ac == 2)
	{
		args[0] = "dicts/numbers.dict";
		args[1] = clean_number(av[1], 0);
		if (!args[1])
			return (0);
	}
	else
	{
		args[0] = av[1];
		args[1] = clean_number(av[2], 0);
		if (!args[1])
			return (0);
	}
	return (1);
}
