/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-roi <hle-roi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:56:23 by hle-roi           #+#    #+#             */
/*   Updated: 2023/10/11 15:17:26 by hle-roi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eventlib.h"

char	*set_mode(void)
{
	int		mode;

	printf("Choisis ta couleur (0 pour \x1B[33mJAUNE\033[0m,%s", 
		"1 pour \0LEU\033[0m) :");
	scanf("%d", &mode);
	fflush(stdin);
	if (mode)
		return ("\033[0;34m");
	else
		return ("\x1B[33m");
}

int	main(int argc, char *argv[])
{
	char	**dict;
	char	*mode;

	if (argc != 2)
		return (1);
	mode = set_mode();
	dict = read_file(argv[1], 0);
	if (!dict)
		return (1);
	game_handler(dict, mode);
	free(dict[0]);
	free(dict[1]);
	free(dict[2]);
	free(dict[3]);
	free(dict);
	return (0);
}
