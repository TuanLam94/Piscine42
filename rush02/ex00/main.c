/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flboulea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 00:54:33 by flboulea          #+#    #+#             */
/*   Updated: 2023/09/24 20:48:23 by flboulea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "main.h"

int	main(int argc, char **argv)
{
	char	*args[2];
	char	***dict;
	int		len_for_parse_dict;

	if (!parse_args(argc, argv, args))
		return (write(1, "Error\n", 6), 0);
	len_for_parse_dict = 0;
	if (!parse_dict(args[0], &dict, &len_for_parse_dict))
		return (free(args[1]), write(1, "Dict Error\n", 11), 0);
	write_number(args[1], dict);
	return (free(args[1]), free_tab_tab(dict), 0);
}
