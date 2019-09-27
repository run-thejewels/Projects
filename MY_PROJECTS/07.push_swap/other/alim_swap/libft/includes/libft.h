/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:49:56 by rymuller          #+#    #+#             */
/*   Updated: 2019/06/30 15:35:27 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# define ATOI_MAX 922337203685477580

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_gnl
{
	char			*content;
	int				fd;
	struct s_gnl	*next;
}					t_gnl;

char				*ft_itoa(int n);
void				ft_putnbr(int n);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_isalnum(int c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_isspace(char c);
void				ft_strclr(char *s);
void				ft_putchar(char c);
void				ft_strdel(char **as);
void				ft_memdel(void **app);
char				*ft_strnew(size_t size);
int					ft_atoi(const char *str);
void				ft_putstr(char const *s);
size_t				ft_strlen(const char *s);
long int			ft_atoi_shift(char **str);
void				*ft_memalloc(size_t size);
void				ft_putendl(char const *s);
char				*ft_strdup(const char *s1);
char				*ft_strtrim(char const *s);
void				ft_bzero(void *s, size_t n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar_fd(char c, int fd);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strchrnew(size_t size, char c);
void				ft_putstr_fd(char const *s, int fd);
int					ft_atoi_point_shift(const char *str);
char				**ft_strsplit(char const *s, char c);
void				ft_putendl_fd(char const *s, int fd);
void				ft_lstadd(t_list **alst, t_list *new);
char				*ft_strchrdup(const char *s1, char c);
char				*ft_strcpy(char *dst, const char *src);
void				*ft_memset(void *b, int c, size_t len);
void				ft_striter(char *s, void (*f)(char *));
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strequ(char const *s1, char const *s2);
char				*ft_strmap(char const *s, char (*f)(char));
void				*ft_memchr(const void *s, int c, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
size_t				ft_strlcat(char *dst, const char *src, size_t size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strstr(const char *haystack, const char *needle);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strcat(char *restrict s1, const char *restrict s2);
char				*ft_strchrjoin(char const *s1, char const *s2, char c);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strnstr(const char *haystack, const char *needle,
		size_t len);

# define BUFF_SIZE 32
# define CHECK(x) if (!x) return (-1)
# define CHERROR(x, y, z) if (x < 0 || y == NULL || z < 0) return (-1)

int					get_next_line(const int fd, char **line);

#endif
