/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 18:44:24 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/01/30 19:14:54 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include "../libft/includes/libft.h"
# include <fcntl.h>

int		ft_input(int fd);
void	ft_error(int er);
int		ft_alg(int **map, int n);
int		ft_checkspot(int *map, char **result, int mapsize);
void	ft_clearspot(int *map, char **result, int flag);
void	ft_recurs(int **map, char **result, int mapsize, int fn);
void	ft_touch(int fn, int *map, char **result);
int		ft_valid(char **map);
void	ft_newmap(char **map, int n);
void	ft_output(char **result);
void	ft_coord(char **map, int n);
void	ft_back(int **map);

#endif
