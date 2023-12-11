/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flboulea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 00:57:41 by flboulea          #+#    #+#             */
/*   Updated: 2023/09/24 06:07:31 by flboulea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>

int		parse_args(int ac, char **av, char *args[2]);
int		parse_dict(char *path, char ****dict, int *len);
void	write_number(char *nbr, char ***dict);
void	free_tab_tab(char ***tab);

#endif
