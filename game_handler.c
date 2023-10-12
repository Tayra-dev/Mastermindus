/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-roi <hle-roi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:51:01 by hle-roi           #+#    #+#             */
/*   Updated: 2023/10/11 14:38:16 by hle-roi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eventlib.h"

void	hinter(char **tab, int hintnb)
{
	if (hintnb % 5 == 0 && hintnb != 20)
		printf("\033[0;32mVoici un indice car tu as du mal: %s\n",
			tab[hintnb / 5]);
}

void	game_handler(char **tab, char *mode)
{
	int		rerun;
	char	user_input[26];

	rerun = 1;
	while (rerun <= 20)
	{
		printf("%sEntrer une combinaison de %i lettres: \033[0m",
			mode, ft_strlen(tab[0]));
		scanf("%25s", user_input);
		fflush(stdin);
		if (ft_strlen(user_input) != ft_strlen(tab[0]))
			printf("\033[0;31mL'entree ne fait pas la bonne longueur\n");
		else if (write_ret(ft_lowercase(user_input), tab[0]) == 1)
		{
			printf("\033[32;1mBravo\033[0;32m: vous avez trouve le mot ");
			set_rainbow(tab[0]);
			system("afplay ./victory.mp3");
			return ;
		}
		hinter(tab, rerun);
		rerun++;
	}
	printf("\033[31;1mDommage: le mot etait %s\n", tab[0]);
	system("afplay ./defeat.mp3");
}
