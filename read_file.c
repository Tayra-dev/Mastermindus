/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-roi <hle-roi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:56:40 by hle-roi           #+#    #+#             */
/*   Updated: 2023/10/11 15:14:32 by hle-roi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eventlib.h"

char	**init_dict(int i, int f_len)
{
	char	**dict;

	dict = malloc(sizeof(char *) * 4);
	if (!dict)
		return (0);
	while (i < 4)
	{
		dict[i] = malloc(sizeof(char) * f_len);
		if (!dict[i])
		{
			while (i-- > 0)
				free(dict[i]);
			free(dict);
			return (0);
		}
		i++;
	}
	return (dict);
}

void	free_dict(char **dict)
{
	free(dict[0]);
	free(dict[1]);
	free(dict[2]);
	free(dict[3]);
	free(dict);
}

char	**get_dict(char *str, int f_len, int j, int k)
{
	char	**dict;
	int		i;

	dict = init_dict(0, f_len);
	if (!dict)
		return (0);
	i = -1;
	while (str[++i] && j < 4)
	{
		if (str[i] != '\n')
			dict[j][k] = str[i];
		else
		{
			dict[j++][k] = '\0';
			k = -1;
		}
		k++;
	}
	free(str);
	if (ft_strlen(dict[0]) > 25 || !ft_isalpha(dict[0]))
	{
		free_dict(dict);
		return (0);
	}
	return (dict);
}

int	test_file(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	if (count == 4)
		return (1);
	else
		return (0);
}

char	**read_file(char *filename, int f_len)
{
	int		fd;
	char	*buff;
	char	c;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	while (read(fd, &c, 1))
		f_len++;
	close(fd);
	buff = malloc(f_len + 1 * sizeof(char));
	if (!buff)
		return (0);
	fd = open(filename, O_RDONLY);
	read(fd, buff, f_len);
	buff[f_len] = '\0';
	close(fd);
	if (!test_file(buff))
	{
		free(buff);
		return (0);
	}
	return (get_dict(ft_lowercase(buff), f_len, 0, 0));
}
