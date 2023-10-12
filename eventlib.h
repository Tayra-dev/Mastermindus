/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eventlib.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-roi <hle-roi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:42:12 by jgoudema          #+#    #+#             */
/*   Updated: 2023/10/11 11:53:58 by hle-roi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTLIB_H
# define EVENTLIB_H

/*--------- Includes ------------*/
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*--------- Protos ------------*/
char	**read_file(char *filename, int f_len);
void	game_handler(char **tab, char *mode);
int		ft_strlen(char *str);
int		write_ret(char *entry, char *word);
char	*ft_lowercase(char *str);
void	set_rainbow(char *str);
int		ft_isalpha(char *str);

#endif