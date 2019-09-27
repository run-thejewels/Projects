/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 18:44:24 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/02/02 21:02:38 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include "../libft/includes/libft.h"
# include <fcntl.h>

void	ft_input(int fd);
void	ft_error(int er);
void	ft_alg(int **map, int n);
int		ft_checkspot(int *map, char **result, int mapsize);
void	ft_clearspot(int *map, char **result, int flag);
void	ft_recurs(int **map, char **result, int mapsize, int fn);
void	ft_touch(int *map, char **result, int fn);
void	ft_valid(char **map);
void	ft_newmap(char **map, int n);
void	ft_output(char **result);
void	ft_coord(char **map, int n);
void	ft_back(int **map);
int		ft_checkeq(int **map, int fn, int fn1);
int		ft_qvad(int *map);
int		ft_findeq(int **map, int fn, int fn1);

#endif
