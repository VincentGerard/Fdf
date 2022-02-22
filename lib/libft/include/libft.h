/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:35:13 by vgerard           #+#    #+#             */
/*   Updated: 2022/01/10 10:35:13 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include "unistd.h"
# include "limits.h"
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int				ft_isalpha(int character);
int				ft_isdigit(int character);
int				ft_isalnum(int character);
int				ft_isascii(int character);
int				ft_isprint(int character);
size_t			ft_strlen(const char *string);
void			ft_bzero(void *str, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dest, const void *src, size_t n);
int				ft_memcmp(void *str1, char *str2, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
size_t			ft_strlcpy(char *dest, const char *src, size_t n);
unsigned int	ft_strlcat(char *s1, const char *s2, unsigned int n);

int				ft_toupper(int character);
int				ft_tolower(int character);
char			*ft_strchr(const char *str, int character);
char			*ft_strrchr(const char*str, int character);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
void			*ft_memchr(void *str, int character, size_t n);
char			*ft_strnstr(const char *str1, const char *str2, size_t n);
int				ft_atoi(const char *str);

void			*ft_calloc(size_t	nmem, size_t n);
char			*ft_strdup(const char *src);

char			*ft_substr(char const *str, unsigned int start, size_t n);
char			*ft_strjoin(char const *str1, const char *str2);
char			*ft_strtrim(char const *str, const char *set);
char			**ft_split(char const *str, char separator);
char			*ft_itoa(int number);
char			*ft_strmapi(char const *str, char (*f)(unsigned int, char));
void			ft_striteri(char *str, void (*f)(unsigned int, char *));
void			ft_putchar_fd(char character, int fd);
void			ft_putstr_fd(char *str, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int nbr, int fd);

//Bonus
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **list, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

#endif
