/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajon-hol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 12:31:34 by ajon-hol          #+#    #+#             */
/*   Updated: 2018/10/09 00:17:16 by ajon-hol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# define BUF_SIZE 4096

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_frame
{
	int			x;
	int			y;
	int			size;
}				t_frame;

typedef struct	s_mapdata
{
	int			x;
	int			y;
	char		empty;
	char		obstacle;
	char		fill;
}				t_mapdata;

char			*ft_map_concat(char *map, char *buf);
char			*ft_read_map(int fd);
t_frame			*ft_create_frame(int x_data, int y_data, int size_data);
int				ft_frame_check(char **map, t_frame *current, char obstacle);
t_frame			*ft_bsq_find(char **map, t_frame *current, t_frame *memory,
							t_mapdata *mapdata);
void			ft_bsq_find_and_print(char **map, t_mapdata *mapdata);
t_mapdata		*ft_get_map_data(char *map);
void			ft_map_print(char **map, t_frame *memory, t_mapdata *mapdata);
void			ft_putstr(char *str);
void			ft_putnbr(int nb);
int				ft_strlen(char *str, char border);
char			**ft_transform(char *map, t_mapdata *mapdata);

#endif
