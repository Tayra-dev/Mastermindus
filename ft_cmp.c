/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-roi <hle-roi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:01:52 by hle-roi           #+#    #+#             */
/*   Updated: 2023/10/11 14:57:05 by hle-roi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eventlib.h"

static void	ft_check(char *entry, char *word, int *rw)
{
	int	i;
	int	j;

	i = 0;
	while (word[i])
	{
		j = 0;
		while (entry[j])
		{
			if (word[i] == entry[i])
			{
				rw[0] += 1;
				entry[i] = '\n';
				break ;
			}
			if (word[i] == entry[j])
			{
				rw[1] += 1;
				entry[j] = '\n';
				break ;
			}
			j++;
		}
		i++;
	}
}

int	ft_cmp(char *entry, char *word, int *rw)
{
	ft_check(entry, word, rw);
	if (rw[0] == ft_strlen(word))
		return (1);
	return (0);
}

int	write_ret(char *entry, char *word)
{
	int	tab[2];

	tab[0] = 0;
	tab[1] = 0;
	if (ft_cmp(entry, word, tab) == 1)
		return (1);
	printf("\033[0;36mIl y a %d lettre bien placee\n", tab[0]);
	printf("\033[0;36mIl y a %d lettre mal placee\n", tab[1]);
	return (0);
}
